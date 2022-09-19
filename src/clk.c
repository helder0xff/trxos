/**
 * @file    clk.c
 * @author  helder
 * @brief   CLK funcionalities module source file.
 */

#ifdef MSP432
#include <msp432p401r_b.h>
#include <msp432p401r_c.h>
#endif

#include <clk.h>

#define HIGH_FREQUENCY_CRYSTAL_HZ   (48000000)
#define LOW_FREQUENCY_CRYSTAL_HZ    (32768)

/** 
 * @brief This function sets the lowest clock speed possible.
 * 
 * It is board dependant. Therefore the frequency will be set acordingly.
 *
 * @param p_system_clk_Hz Pointer to save the system frequency, main clock.
 * @param p_subsystem_clk_Hz Pointer to save the subsystem frequency.
 * @return CLK_OK on success, CLK_ERROR otherwise.
 */
static int8_t _set_clk_speed_level_super_low(
    uint32_t* p_system_clk_Hz,
    uint32_t* p_subsystem_clk_Hz);

int8_t CLK_set_clk_speed_level( 
    uint8_t clk_speed_level,
    uint32_t* p_system_clk_Hz,
    uint32_t* p_subsystem_clk_Hz){
    /*
     * Although from the TRXOS point of view a lower clk_speed_level means
     * a lower speed, it is not the case within this function for the sake
     * of simplicity. Therefore, we reverse the clk_speed_level value at the
     * most beginning.
     * We support the following clk speeds:
     * 
     * clk_speed_level  | system_clk_Hz     | subsystem_clk_Hz
     * --------------------------------------------------------
     * 0                | 48     MHz        | 12     MHz
     * 1                | 24     MHz        | 6      MHz
     * 2                | 12     MHz        | 3      MHz
     * 3                | 6      MHz        | 1.5    MHz
     * 4                | 3      MHz        | 750    KHz
     * 5                | 1.5    MHz        | 375    KHz
     * 6                | 750    KHz        | 375    KHz
     * 7                | 375    KHz        | 375    KHz
     * 8 - 254          | 375    KHz        | 375    KHz
     * 255              | 32.768 KHz        | 32.768 KHz
     * --------------------------------------------------------
     */
    clk_speed_level = 255 - clk_speed_level;
    if(255 == clk_speed_level){
        _set_clk_speed_level_super_low(p_system_clk_Hz, p_subsystem_clk_Hz);

        return CLK_OK;
    }
    if(8 <= clk_speed_level && 254 >= clk_speed_level){
        clk_speed_level = 7;
    }

    /************************* CHOOSE THE POWER MODE *************************/
    /* Wait for the Power Control Manager to be idle. */
    while(PCMCTL1 & PMR_BUSY){
        ;
    }

    /* Request change to Power Mode
     * To request a Power mode change firstly we need to unlock write access
     * to the PMR by writing the right value onto the PCMKEY.
     * 1) Clean Key and Active Mode Request Fields.
     * 2) Write Key and request.
     */
    uint32_t amr_am_ldo_core = 
        (HIGH_FREQUENCY_CRYSTAL_HZ / 2 < 
        (HIGH_FREQUENCY_CRYSTAL_HZ / (1 << clk_speed_level))) ?
        AMR__AM_LDO_VCORE1 :
        AMR__AM_LDO_VCORE0;
    PCMCTL0 =   (PCMCTL0 & ~(PCMKEY_M | AMR_M)) |           /* 1) */
                (PCM_PMR_KEY_VAL | amr_am_ldo_core);        /* 2) */

    /* Check if a valid transition request. */
    if(PCMIFG & AM_INVALID_TR_IFG){        
        PCMCLRIFG = CLR_AM_INVALID_TR_IFG; /* Clear flag. */
        return CLK_ERROR;
    }

    uint32_t cpm_am_ldo_core = 
        (HIGH_FREQUENCY_CRYSTAL_HZ / 2 < 
        (HIGH_FREQUENCY_CRYSTAL_HZ / (1 << clk_speed_level))) ?
        CPM__AM_LDO_VCORE1 :
        CPM__AM_LDO_VCORE0;
    /* Wait till the Current Power Mode is set to  */
    while((PCMCTL0 & CPM_M) != cpm_am_ldo_core){
        ;
    }
    /*------------------------ CHOOSE THE POWER MODE ------------------------*/


    /**************************** CHOOSE THE CLK ****************************/
    /* Wait for the Power Control Manager to be idle. */
    while(PCMCTL1 & PMR_BUSY){
        ;
    }

    /* Configure HFXT oscillator pins. Pin 2 HFXT in, 
     * pin 3 HFXT out on port J.
     */        
    PJSEL0 |= 0x0C;
    PJSEL1 &= ~0x0C;

    /* Unlokc CS registers write. */
    CSKEY = CSKEY_VAL;

    /* Select clk system (CS) to run at 48MHz */
    CSCTL2 =    (CSCTL2 & ~HFXTFREQ_M)  |   /* Clean HFXTFREQ */
                HFXTFREQ_6              |   /* >40 MHz to 48 MHz */
                HFXTDRIVE               |   /* Drive for > 4MHz*/
                HFXT_EN;
    /* Disable HFXT bypass. */
    CSCTL2 &= ~HFXTBYPASS;

    /* Wait for the HFXT clock to stabilize. */
    while(CSIFG & HFXTIFG){
        /* clear the HFXT oscillator interrupt flag. */
        CSCLRIFG = CLR_HFXTIFG;
    }

    /* Configure for 2 wait states (minimum for 
     * 48 MHz operation) for flash Bank 0. 
     */
    FLCTL_BANK0_RDCTL = (FLCTL_BANK0_RDCTL & ~FLCTL_BANK0_RDCTL_WAIT_M) |
                        FLCTL_BANK0_RDCTL_WAIT_2;
    /* Configure for 2 wait states (minimum for 
     * 48 MHz operation) for flash Bank 0. 
     */
    FLCTL_BANK1_RDCTL = (FLCTL_BANK1_RDCTL & ~FLCTL_BANK0_RDCTL_WAIT_M) |
                        FLCTL_BANK1_RDCTL_WAIT_2;

    /* Possible divisors, from 2^0 to 2^7. */
    uint32_t div_s_values[8]   =   {DIVS_0, DIVS_1, DIVS_2, DIVS_3, 
                                    DIVS_4, DIVS_5, DIVS_6, DIVS_7};
    uint32_t div_a_values[8]   =   {DIVM_0, DIVM_1, DIVM_2, DIVM_3,
                                    DIVM_4, DIVM_5, DIVM_6, DIVM_7};
    uint32_t div_hs_values[8]  =   {DIVHS_0, DIVHS_1, DIVHS_2, DIVHS_3,
                                    DIVHS_4, DIVHS_5, DIVHS_6, DIVHS_7};
    uint32_t div_m_values[8]   =   {DIVM_0, DIVM_1, DIVM_2, DIVM_3,
                                    DIVM_4, DIVM_5, DIVM_6, DIVM_7};

    /* 
     * We set the subsystem clock 4 times slower than the main clock and
     * the hs clock 2 times slower than the main clock. No specific reason,
     * probably to be reviewed in future versions.
     * When we cannot divide a clk more than 128 times (2^7), so we cap it when
     * necessary.
     */
    uint8_t div_m_level     =   clk_speed_level;
    uint8_t div_s_level     =   7 < div_m_level + 2 ? 
                                7 :
                                div_m_level + 2;
    uint8_t div_a_level     =   0;
    uint8_t div_hs_level    =   7 < div_m_level + 1 ?
                                7 :
                                div_m_level + 1;
    CSCTL1 = 
        div_s_values[div_s_level]   |   /* configure for SMCLK divider        */
        div_a_values[div_a_level]   |   
        div_hs_values[div_hs_level] |   /* configure for HSMCLK divider       */
        div_m_values[div_m_level]   |
        SELA__REFOCLK               |   /* ACLK sourced from REFOCLK          */
        SELS__HFXTCLK               |   /* SMCLK and HSMCLK from HFXTCLK      */
        SELM__HFXTCLK;                  /* MCLK from HFXTCLK                  */
    /* Disable LFXT */
    CSCTL2 &= ~LFXT_EN;
    CSKEY = 0; /* Lock CS registers writing. */    
    /*--------------------------- CHOOSE THE CLK ---------------------------*/ 

    *p_system_clk_Hz     = HIGH_FREQUENCY_CRYSTAL_HZ / (1 << div_m_level);
    *p_subsystem_clk_Hz  = HIGH_FREQUENCY_CRYSTAL_HZ / (1 << div_s_level);

    return CLK_OK;
}

static int8_t _set_clk_speed_level_super_low(
    uint32_t* p_system_clk_Hz, 
    uint32_t* p_subsystem_clk_Hz){
    /************************* CHOOSE THE POWER MODE *************************/
    /* Wait for the Power Control Manager to be idle. */
    while(PCMCTL1 & PMR_BUSY){
        ;
    }

    /* Request change to Power Mode
     * To request a Power mode change firstly we need to unlock write access
     * to the PMR by writing the right value onto the PCMKEY.
     * 1) Clean Key and Active Mode Request Fields.
     * 2) Write Key and request.
     */
    PCMCTL0 =   (PCMCTL0 & ~(PCMKEY_M | AMR_M)) |               /* 1) */
                (PCM_PMR_KEY_VAL | AMR__AM_LDO_VCORE0);         /* 2) */

    /* Check if a valid transition request. */
    if(PCMIFG & AM_INVALID_TR_IFG){        
        PCMCLRIFG = CLR_AM_INVALID_TR_IFG; /* Clear flag. */
        return CLK_ERROR;
    }

    /* Wait till the Current Power Mode is set to  */
    while((PCMCTL0 & CPM_M) != CPM__AM_LDO_VCORE0){
        ;
    }
    /*------------------------ CHOOSE THE POWER MODE ------------------------*/

    /**************************** CHOOSE THE CLK ****************************/
    /* Wait for the Power Control Manager to be idle. */
    while(PCMCTL1 & PMR_BUSY){
        ;
    }

    /* Configure LFXT oscillator pins. Pin 0 LFXT in, 
     * pin 1 LFXT out on port J.
     */        
    PJSEL0 |= 0x03;
    PJSEL1 &= ~0x03;

    /* Unlokc CS registers write. */
    CSKEY = CSKEY_VAL;

    /* Enable the LFXT. */
    CSCTL2 =    LFXTDRIVE_3 |
                LFXT_EN;                
    /* Disable HFXT bypass. */
    CSCTL2 &= ~LFXTBYPASS;

    /* Wait for the HFXT clock to stabilize. */
    while(CSIFG & LFXTIFG){
        /* clear the HFXT oscillator interrupt flag. */
        CSCLRIFG = CLR_LFXTIFG;
    }

    /* Configure for 0 wait states for flash Bank 0. */
    FLCTL_BANK0_RDCTL = (FLCTL_BANK0_RDCTL & ~FLCTL_BANK0_RDCTL_WAIT_M) |
                        FLCTL_BANK0_RDCTL_WAIT_0;
    /* Configure for 0 wait states for flash Bank 1. */
    FLCTL_BANK1_RDCTL = (FLCTL_BANK1_RDCTL & ~FLCTL_BANK0_RDCTL_WAIT_M) |
                        FLCTL_BANK1_RDCTL_WAIT_0;

    CSCTL1 = 
        DIVS_0          |   /* configure for SMCLK divider                    */
        DIVA_0          |   
        DIVHS_0         |   /* configure for HSMCLK divider                   */
        DIVM_0          |
        SELA__LFXTCLK   |   /* ACLK sourced from LFXTCLK                      */
        SELS__LFXTCLK   |   /* SMCLK and HSMCLK sourced from LFXTCLK          */
        SELM__LFXTCLK;      /* MCLK sourced from LFXTCLK                      */
    /* Disable HFXT. */
    CSCTL2 &= ~HFXT_EN;
    CSKEY = 0; /* Lock CS registers writing. */                        
    /*--------------------------- CHOOSE THE CLK ---------------------------*/

    *p_system_clk_Hz     = 32768;
    *p_subsystem_clk_Hz  = 32768;

    return CLK_OK;        
}

/* end of file */
