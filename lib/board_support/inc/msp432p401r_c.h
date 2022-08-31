/***************************************************************************
// DIO Registers
***************************************************************************/
#define PAIN                                               (HWREG16(0x40004C00)) /* Port A Input */
#define PAOUT                                              (HWREG16(0x40004C02)) /* Port A Output */
#define PADIR                                              (HWREG16(0x40004C04)) /* Port A Direction */
#define PAREN                                              (HWREG16(0x40004C06)) /* Port A Resistor Enable */
#define PADS                                               (HWREG16(0x40004C08)) /* Port A Drive Strength */
#define PASEL0                                             (HWREG16(0x40004C0A)) /* Port A Select 0 */
#define PASEL1                                             (HWREG16(0x40004C0C)) /* Port A Select 1 */
#define P1IV                                               (HWREG16(0x40004C0E)) /* Port 1 Interrupt Vector Register */
#define PASELC                                             (HWREG16(0x40004C16)) /* Port A Complement Select */
#define PAIES                                              (HWREG16(0x40004C18)) /* Port A Interrupt Edge Select */
#define PAIE                                               (HWREG16(0x40004C1A)) /* Port A Interrupt Enable */
#define PAIFG                                              (HWREG16(0x40004C1C)) /* Port A Interrupt Flag */
#define P2IV                                               (HWREG16(0x40004C1E)) /* Port 2 Interrupt Vector Register */
#define PBIN                                               (HWREG16(0x40004C20)) /* Port B Input */
#define PBOUT                                              (HWREG16(0x40004C22)) /* Port B Output */
#define PBDIR                                              (HWREG16(0x40004C24)) /* Port B Direction */
#define PBREN                                              (HWREG16(0x40004C26)) /* Port B Resistor Enable */
#define PBDS                                               (HWREG16(0x40004C28)) /* Port B Drive Strength */
#define PBSEL0                                             (HWREG16(0x40004C2A)) /* Port B Select 0 */
#define PBSEL1                                             (HWREG16(0x40004C2C)) /* Port B Select 1 */
#define P3IV                                               (HWREG16(0x40004C2E)) /* Port 3 Interrupt Vector Register */
#define PBSELC                                             (HWREG16(0x40004C36)) /* Port B Complement Select */
#define PBIES                                              (HWREG16(0x40004C38)) /* Port B Interrupt Edge Select */
#define PBIE                                               (HWREG16(0x40004C3A)) /* Port B Interrupt Enable */
#define PBIFG                                              (HWREG16(0x40004C3C)) /* Port B Interrupt Flag */
#define P4IV                                               (HWREG16(0x40004C3E)) /* Port 4 Interrupt Vector Register */
#define PCIN                                               (HWREG16(0x40004C40)) /* Port C Input */
#define PCOUT                                              (HWREG16(0x40004C42)) /* Port C Output */
#define PCDIR                                              (HWREG16(0x40004C44)) /* Port C Direction */
#define PCREN                                              (HWREG16(0x40004C46)) /* Port C Resistor Enable */
#define PCDS                                               (HWREG16(0x40004C48)) /* Port C Drive Strength */
#define PCSEL0                                             (HWREG16(0x40004C4A)) /* Port C Select 0 */
#define PCSEL1                                             (HWREG16(0x40004C4C)) /* Port C Select 1 */
#define P5IV                                               (HWREG16(0x40004C4E)) /* Port 5 Interrupt Vector Register */
#define PCSELC                                             (HWREG16(0x40004C56)) /* Port C Complement Select */
#define PCIES                                              (HWREG16(0x40004C58)) /* Port C Interrupt Edge Select */
#define PCIE                                               (HWREG16(0x40004C5A)) /* Port C Interrupt Enable */
#define PCIFG                                              (HWREG16(0x40004C5C)) /* Port C Interrupt Flag */
#define P6IV                                               (HWREG16(0x40004C5E)) /* Port 6 Interrupt Vector Register */
#define PDIN                                               (HWREG16(0x40004C60)) /* Port D Input */
#define PDOUT                                              (HWREG16(0x40004C62)) /* Port D Output */
#define PDDIR                                              (HWREG16(0x40004C64)) /* Port D Direction */
#define PDREN                                              (HWREG16(0x40004C66)) /* Port D Resistor Enable */
#define PDDS                                               (HWREG16(0x40004C68)) /* Port D Drive Strength */
#define PDSEL0                                             (HWREG16(0x40004C6A)) /* Port D Select 0 */
#define PDSEL1                                             (HWREG16(0x40004C6C)) /* Port D Select 1 */
#define P7IV                                               (HWREG16(0x40004C6E)) /* Port 7 Interrupt Vector Register */
#define PDSELC                                             (HWREG16(0x40004C76)) /* Port D Complement Select */
#define PDIES                                              (HWREG16(0x40004C78)) /* Port D Interrupt Edge Select */
#define PDIE                                               (HWREG16(0x40004C7A)) /* Port D Interrupt Enable */
#define PDIFG                                              (HWREG16(0x40004C7C)) /* Port D Interrupt Flag */
#define P8IV                                               (HWREG16(0x40004C7E)) /* Port 8 Interrupt Vector Register */
#define PEIN                                               (HWREG16(0x40004C80)) /* Port E Input */
#define PEOUT                                              (HWREG16(0x40004C82)) /* Port E Output */
#define PEDIR                                              (HWREG16(0x40004C84)) /* Port E Direction */
#define PEREN                                              (HWREG16(0x40004C86)) /* Port E Resistor Enable */
#define PEDS                                               (HWREG16(0x40004C88)) /* Port E Drive Strength */
#define PESEL0                                             (HWREG16(0x40004C8A)) /* Port E Select 0 */
#define PESEL1                                             (HWREG16(0x40004C8C)) /* Port E Select 1 */
#define P9IV                                               (HWREG16(0x40004C8E)) /* Port 9 Interrupt Vector Register */
#define PESELC                                             (HWREG16(0x40004C96)) /* Port E Complement Select */
#define PEIES                                              (HWREG16(0x40004C98)) /* Port E Interrupt Edge Select */
#define PEIE                                               (HWREG16(0x40004C9A)) /* Port E Interrupt Enable */
#define PEIFG                                              (HWREG16(0x40004C9C)) /* Port E Interrupt Flag */
#define P10IV                                              (HWREG16(0x40004C9E)) /* Port 10 Interrupt Vector Register */
#define PJIN                                               (HWREG16(0x40004D20)) /* Port J Input */
#define PJOUT                                              (HWREG16(0x40004D22)) /* Port J Output */
#define PJDIR                                              (HWREG16(0x40004D24)) /* Port J Direction */
#define PJREN                                              (HWREG16(0x40004D26)) /* Port J Resistor Enable */
#define PJDS                                               (HWREG16(0x40004D28)) /* Port J Drive Strength */
#define PJSEL0                                             (HWREG16(0x40004D2A)) /* Port J Select 0 */
#define PJSEL1                                             (HWREG16(0x40004D2C)) /* Port J Select 1 */
#define PJSELC                                             (HWREG16(0x40004D36)) /* Port J Complement Select */
#define P1IN                                               (HWREG8(0x40004C00))  /* Port 1 Input */
#define P2IN                                               (HWREG8(0x40004C01))  /* Port 2 Input */
#define P2OUT                                              (HWREG8(0x40004C03))  /* Port 2 Output */
#define P1OUT                                              (HWREG8(0x40004C02))  /* Port 1 Output */
#define P1DIR                                              (HWREG8(0x40004C04))  /* Port 1 Direction */
#define P2DIR                                              (HWREG8(0x40004C05))  /* Port 2 Direction */
#define P1REN                                              (HWREG8(0x40004C06))  /* Port 1 Resistor Enable */
#define P2REN                                              (HWREG8(0x40004C07))  /* Port 2 Resistor Enable */
#define P1DS                                               (HWREG8(0x40004C08))  /* Port 1 Drive Strength */
#define P2DS                                               (HWREG8(0x40004C09))  /* Port 2 Drive Strength */
#define P1SEL0                                             (HWREG8(0x40004C0A))  /* Port 1 Select 0 */
#define P2SEL0                                             (HWREG8(0x40004C0B))  /* Port 2 Select 0 */
#define P1SEL1                                             (HWREG8(0x40004C0C))  /* Port 1 Select 1 */
#define P2SEL1                                             (HWREG8(0x40004C0D))  /* Port 2 Select 1 */
#define P1SELC                                             (HWREG8(0x40004C16))  /* Port 1 Complement Select */
#define P2SELC                                             (HWREG8(0x40004C17))  /* Port 2 Complement Select */
#define P1IES                                              (HWREG8(0x40004C18))  /* Port 1 Interrupt Edge Select */
#define P2IES                                              (HWREG8(0x40004C19))  /* Port 2 Interrupt Edge Select */
#define P1IE                                               (HWREG8(0x40004C1A))  /* Port 1 Interrupt Enable */
#define P2IE                                               (HWREG8(0x40004C1B))  /* Port 2 Interrupt Enable */
#define P1IFG                                              (HWREG8(0x40004C1C))  /* Port 1 Interrupt Flag */
#define P2IFG                                              (HWREG8(0x40004C1D))  /* Port 2 Interrupt Flag */
#define P3IN                                               (HWREG8(0x40004C20))  /* Port 3 Input */
#define P4IN                                               (HWREG8(0x40004C21))  /* Port 4 Input */
#define P3OUT                                              (HWREG8(0x40004C22))  /* Port 3 Output */
#define P4OUT                                              (HWREG8(0x40004C23))  /* Port 4 Output */
#define P3DIR                                              (HWREG8(0x40004C24))  /* Port 3 Direction */
#define P4DIR                                              (HWREG8(0x40004C25))  /* Port 4 Direction */
#define P3REN                                              (HWREG8(0x40004C26))  /* Port 3 Resistor Enable */
#define P4REN                                              (HWREG8(0x40004C27))  /* Port 4 Resistor Enable */
#define P3DS                                               (HWREG8(0x40004C28))  /* Port 3 Drive Strength */
#define P4DS                                               (HWREG8(0x40004C29))  /* Port 4 Drive Strength */
#define P4SEL0                                             (HWREG8(0x40004C2B))  /* Port 4 Select 0 */
#define P3SEL0                                             (HWREG8(0x40004C2A))  /* Port 3 Select 0 */
#define P3SEL1                                             (HWREG8(0x40004C2C))  /* Port 3 Select 1 */
#define P4SEL1                                             (HWREG8(0x40004C2D))  /* Port 4 Select 1 */
#define P3SELC                                             (HWREG8(0x40004C36))  /* Port 3 Complement Select */
#define P4SELC                                             (HWREG8(0x40004C37))  /* Port 4 Complement Select */
#define P3IES                                              (HWREG8(0x40004C38))  /* Port 3 Interrupt Edge Select */
#define P4IES                                              (HWREG8(0x40004C39))  /* Port 4 Interrupt Edge Select */
#define P3IE                                               (HWREG8(0x40004C3A))  /* Port 3 Interrupt Enable */
#define P4IE                                               (HWREG8(0x40004C3B))  /* Port 4 Interrupt Enable */
#define P3IFG                                              (HWREG8(0x40004C3C))  /* Port 3 Interrupt Flag */
#define P4IFG                                              (HWREG8(0x40004C3D))  /* Port 4 Interrupt Flag */
#define P5IN                                               (HWREG8(0x40004C40))  /* Port 5 Input */
#define P6IN                                               (HWREG8(0x40004C41))  /* Port 6 Input */
#define P5OUT                                              (HWREG8(0x40004C42))  /* Port 5 Output */
#define P6OUT                                              (HWREG8(0x40004C43))  /* Port 6 Output */
#define P5DIR                                              (HWREG8(0x40004C44))  /* Port 5 Direction */
#define P6DIR                                              (HWREG8(0x40004C45))  /* Port 6 Direction */
#define P5REN                                              (HWREG8(0x40004C46))  /* Port 5 Resistor Enable */
#define P6REN                                              (HWREG8(0x40004C47))  /* Port 6 Resistor Enable */
#define P5DS                                               (HWREG8(0x40004C48))  /* Port 5 Drive Strength */
#define P6DS                                               (HWREG8(0x40004C49))  /* Port 6 Drive Strength */
#define P5SEL0                                             (HWREG8(0x40004C4A))  /* Port 5 Select 0 */
#define P6SEL0                                             (HWREG8(0x40004C4B))  /* Port 6 Select 0 */
#define P5SEL1                                             (HWREG8(0x40004C4C))  /* Port 5 Select 1 */
#define P6SEL1                                             (HWREG8(0x40004C4D))  /* Port 6 Select 1 */
#define P5SELC                                             (HWREG8(0x40004C56))  /* Port 5 Complement Select */
#define P6SELC                                             (HWREG8(0x40004C57))  /* Port 6 Complement Select */
#define P5IES                                              (HWREG8(0x40004C58))  /* Port 5 Interrupt Edge Select */
#define P6IES                                              (HWREG8(0x40004C59))  /* Port 6 Interrupt Edge Select */
#define P5IE                                               (HWREG8(0x40004C5A))  /* Port 5 Interrupt Enable */
#define P6IE                                               (HWREG8(0x40004C5B))  /* Port 6 Interrupt Enable */
#define P5IFG                                              (HWREG8(0x40004C5C))  /* Port 5 Interrupt Flag */
#define P6IFG                                              (HWREG8(0x40004C5D))  /* Port 6 Interrupt Flag */
#define P7IN                                               (HWREG8(0x40004C60))  /* Port 7 Input */
#define P8IN                                               (HWREG8(0x40004C61))  /* Port 8 Input */
#define P7OUT                                              (HWREG8(0x40004C62))  /* Port 7 Output */
#define P8OUT                                              (HWREG8(0x40004C63))  /* Port 8 Output */
#define P7DIR                                              (HWREG8(0x40004C64))  /* Port 7 Direction */
#define P8DIR                                              (HWREG8(0x40004C65))  /* Port 8 Direction */
#define P7REN                                              (HWREG8(0x40004C66))  /* Port 7 Resistor Enable */
#define P8REN                                              (HWREG8(0x40004C67))  /* Port 8 Resistor Enable */
#define P7DS                                               (HWREG8(0x40004C68))  /* Port 7 Drive Strength */
#define P8DS                                               (HWREG8(0x40004C69))  /* Port 8 Drive Strength */
#define P7SEL0                                             (HWREG8(0x40004C6A))  /* Port 7 Select 0 */
#define P8SEL0                                             (HWREG8(0x40004C6B))  /* Port 8 Select 0 */
#define P7SEL1                                             (HWREG8(0x40004C6C))  /* Port 7 Select 1 */
#define P8SEL1                                             (HWREG8(0x40004C6D))  /* Port 8 Select 1 */
#define P7SELC                                             (HWREG8(0x40004C76))  /* Port 7 Complement Select */
#define P8SELC                                             (HWREG8(0x40004C77))  /* Port 8 Complement Select */
#define P7IES                                              (HWREG8(0x40004C78))  /* Port 7 Interrupt Edge Select */
#define P8IES                                              (HWREG8(0x40004C79))  /* Port 8 Interrupt Edge Select */
#define P7IE                                               (HWREG8(0x40004C7A))  /* Port 7 Interrupt Enable */
#define P8IE                                               (HWREG8(0x40004C7B))  /* Port 8 Interrupt Enable */
#define P7IFG                                              (HWREG8(0x40004C7C))  /* Port 7 Interrupt Flag */
#define P8IFG                                              (HWREG8(0x40004C7D))  /* Port 8 Interrupt Flag */
#define P9IN                                               (HWREG8(0x40004C80))  /* Port 9 Input */
#define P10IN                                              (HWREG8(0x40004C81))  /* Port 10 Input */
#define P9OUT                                              (HWREG8(0x40004C82))  /* Port 9 Output */
#define P10OUT                                             (HWREG8(0x40004C83))  /* Port 10 Output */
#define P9DIR                                              (HWREG8(0x40004C84))  /* Port 9 Direction */
#define P10DIR                                             (HWREG8(0x40004C85))  /* Port 10 Direction */
#define P9REN                                              (HWREG8(0x40004C86))  /* Port 9 Resistor Enable */
#define P10REN                                             (HWREG8(0x40004C87))  /* Port 10 Resistor Enable */
#define P9DS                                               (HWREG8(0x40004C88))  /* Port 9 Drive Strength */
#define P10DS                                              (HWREG8(0x40004C89))  /* Port 10 Drive Strength */
#define P9SEL0                                             (HWREG8(0x40004C8A))  /* Port 9 Select 0 */
#define P10SEL0                                            (HWREG8(0x40004C8B))  /* Port 10 Select 0 */
#define P9SEL1                                             (HWREG8(0x40004C8C))  /* Port 9 Select 1 */
#define P10SEL1                                            (HWREG8(0x40004C8D))  /* Port 10 Select 1 */
#define P9SELC                                             (HWREG8(0x40004C96))  /* Port 9 Complement Select */
#define P10SELC                                            (HWREG8(0x40004C97))  /* Port 10 Complement Select */
#define P9IES                                              (HWREG8(0x40004C98))  /* Port 9 Interrupt Edge Select */
#define P10IES                                             (HWREG8(0x40004C99))  /* Port 10 Interrupt Edge Select */
#define P9IE                                               (HWREG8(0x40004C9A))  /* Port 9 Interrupt Enable */
#define P10IE                                              (HWREG8(0x40004C9B))  /* Port 10 Interrupt Enable */
#define P9IFG                                              (HWREG8(0x40004C9C))  /* Port 9 Interrupt Flag */
#define P10IFG                                             (HWREG8(0x40004C9D))  /* Port 10 Interrupt Flag */

/***************************************************************************
// ADC14 Registers
***************************************************************************/
#define ADC14CTL0                                          (HWREG32(0x40012000)) /* Control 0 Register  */
#define ADC14CTL1                                          (HWREG32(0x40012004)) /* Control 1 Register */
#define ADC14LO0                                           (HWREG32(0x40012008)) /* Window Comparator Low Threshold 0 Register  */
#define ADC14HI0                                           (HWREG32(0x4001200C)) /* Window Comparator High Threshold 0 Register  */
#define ADC14LO1                                           (HWREG32(0x40012010)) /* Window Comparator Low Threshold 1 Register  */
#define ADC14HI1                                           (HWREG32(0x40012014)) /* Window Comparator High Threshold 1 Register  */
#define ADC14MCTL0                                         (HWREG32(0x40012018)) /* Conversion Memory Control Register */
#define ADC14MCTL1                                         (HWREG32(0x4001201C)) /* Conversion Memory Control Register */
#define ADC14MCTL2                                         (HWREG32(0x40012020)) /* Conversion Memory Control Register */
#define ADC14MCTL3                                         (HWREG32(0x40012024)) /* Conversion Memory Control Register */
#define ADC14MCTL4                                         (HWREG32(0x40012028)) /* Conversion Memory Control Register */
#define ADC14MCTL5                                         (HWREG32(0x4001202C)) /* Conversion Memory Control Register */
#define ADC14MCTL6                                         (HWREG32(0x40012030)) /* Conversion Memory Control Register */
#define ADC14MCTL7                                         (HWREG32(0x40012034)) /* Conversion Memory Control Register */
#define ADC14MCTL8                                         (HWREG32(0x40012038)) /* Conversion Memory Control Register */
#define ADC14MCTL9                                         (HWREG32(0x4001203C)) /* Conversion Memory Control Register */
#define ADC14MCTL10                                        (HWREG32(0x40012040)) /* Conversion Memory Control Register */
#define ADC14MCTL11                                        (HWREG32(0x40012044)) /* Conversion Memory Control Register */
#define ADC14MCTL12                                        (HWREG32(0x40012048)) /* Conversion Memory Control Register */
#define ADC14MCTL13                                        (HWREG32(0x4001204C)) /* Conversion Memory Control Register */
#define ADC14MCTL14                                        (HWREG32(0x40012050)) /* Conversion Memory Control Register */
#define ADC14MCTL15                                        (HWREG32(0x40012054)) /* Conversion Memory Control Register */
#define ADC14MCTL16                                        (HWREG32(0x40012058)) /* Conversion Memory Control Register */
#define ADC14MCTL17                                        (HWREG32(0x4001205C)) /* Conversion Memory Control Register */
#define ADC14MCTL18                                        (HWREG32(0x40012060)) /* Conversion Memory Control Register */
#define ADC14MCTL19                                        (HWREG32(0x40012064)) /* Conversion Memory Control Register */
#define ADC14MCTL20                                        (HWREG32(0x40012068)) /* Conversion Memory Control Register */
#define ADC14MCTL21                                        (HWREG32(0x4001206C)) /* Conversion Memory Control Register */
#define ADC14MCTL22                                        (HWREG32(0x40012070)) /* Conversion Memory Control Register */
#define ADC14MCTL23                                        (HWREG32(0x40012074)) /* Conversion Memory Control Register */
#define ADC14MCTL24                                        (HWREG32(0x40012078)) /* Conversion Memory Control Register */
#define ADC14MCTL25                                        (HWREG32(0x4001207C)) /* Conversion Memory Control Register */
#define ADC14MCTL26                                        (HWREG32(0x40012080)) /* Conversion Memory Control Register */
#define ADC14MCTL27                                        (HWREG32(0x40012084)) /* Conversion Memory Control Register */
#define ADC14MCTL28                                        (HWREG32(0x40012088)) /* Conversion Memory Control Register */
#define ADC14MCTL29                                        (HWREG32(0x4001208C)) /* Conversion Memory Control Register */
#define ADC14MCTL30                                        (HWREG32(0x40012090)) /* Conversion Memory Control Register */
#define ADC14MCTL31                                        (HWREG32(0x40012094)) /* Conversion Memory Control Register */
#define ADC14MEM0                                          (HWREG32(0x40012098)) /* Conversion Memory Register */
#define ADC14MEM1                                          (HWREG32(0x4001209C)) /* Conversion Memory Register */
#define ADC14MEM2                                          (HWREG32(0x400120A0)) /* Conversion Memory Register */
#define ADC14MEM3                                          (HWREG32(0x400120A4)) /* Conversion Memory Register */
#define ADC14MEM4                                          (HWREG32(0x400120A8)) /* Conversion Memory Register */
#define ADC14MEM5                                          (HWREG32(0x400120AC)) /* Conversion Memory Register */
#define ADC14MEM6                                          (HWREG32(0x400120B0)) /* Conversion Memory Register */
#define ADC14MEM7                                          (HWREG32(0x400120B4)) /* Conversion Memory Register */
#define ADC14MEM8                                          (HWREG32(0x400120B8)) /* Conversion Memory Register */
#define ADC14MEM9                                          (HWREG32(0x400120BC)) /* Conversion Memory Register */
#define ADC14MEM10                                         (HWREG32(0x400120C0)) /* Conversion Memory Register */
#define ADC14MEM11                                         (HWREG32(0x400120C4)) /* Conversion Memory Register */
#define ADC14MEM12                                         (HWREG32(0x400120C8)) /* Conversion Memory Register */
#define ADC14MEM13                                         (HWREG32(0x400120CC)) /* Conversion Memory Register */
#define ADC14MEM14                                         (HWREG32(0x400120D0)) /* Conversion Memory Register */
#define ADC14MEM15                                         (HWREG32(0x400120D4)) /* Conversion Memory Register */
#define ADC14MEM16                                         (HWREG32(0x400120D8)) /* Conversion Memory Register */
#define ADC14MEM17                                         (HWREG32(0x400120DC)) /* Conversion Memory Register */
#define ADC14MEM18                                         (HWREG32(0x400120E0)) /* Conversion Memory Register */
#define ADC14MEM19                                         (HWREG32(0x400120E4)) /* Conversion Memory Register */
#define ADC14MEM20                                         (HWREG32(0x400120E8)) /* Conversion Memory Register */
#define ADC14MEM21                                         (HWREG32(0x400120EC)) /* Conversion Memory Register */
#define ADC14MEM22                                         (HWREG32(0x400120F0)) /* Conversion Memory Register */
#define ADC14MEM23                                         (HWREG32(0x400120F4)) /* Conversion Memory Register */
#define ADC14MEM24                                         (HWREG32(0x400120F8)) /* Conversion Memory Register */
#define ADC14MEM25                                         (HWREG32(0x400120FC)) /* Conversion Memory Register */
#define ADC14MEM26                                         (HWREG32(0x40012100)) /* Conversion Memory Register */
#define ADC14MEM27                                         (HWREG32(0x40012104)) /* Conversion Memory Register */
#define ADC14MEM28                                         (HWREG32(0x40012108)) /* Conversion Memory Register */
#define ADC14MEM29                                         (HWREG32(0x4001210C)) /* Conversion Memory Register */
#define ADC14MEM30                                         (HWREG32(0x40012110)) /* Conversion Memory Register */
#define ADC14MEM31                                         (HWREG32(0x40012114)) /* Conversion Memory Register */
#define ADC14IER0                                          (HWREG32(0x4001213C)) /* Interrupt Enable 0 Register  */
#define ADC14IER1                                          (HWREG32(0x40012140)) /* Interrupt Enable 1 Register  */
#define ADC14IFGR0                                         (HWREG32(0x40012144)) /* Interrupt Flag 0 Register  */
#define ADC14IFGR1                                         (HWREG32(0x40012148)) /* Interrupt Flag 1 Register  */
#define ADC14CLRIFGR0                                      (HWREG32(0x4001214C)) /* Clear Interrupt Flag 0 Register  */
#define ADC14CLRIFGR1                                      (HWREG32(0x40012150)) /* Clear Interrupt Flag 1 Register  */
#define ADC14IV                                            (HWREG32(0x40012154)) /* Interrupt Vector Register */

/***************************************************************************
// TIMER_A0 Registers
***************************************************************************/
#define TA0CTL                                             (HWREG16(0x40000000)) /* TimerAx Control Register */
#define TA0CCTL0                                           (HWREG16(0x40000002)) /* Timer_A Capture/Compare Control Register */
#define TA0CCTL1                                           (HWREG16(0x40000004)) /* Timer_A Capture/Compare Control Register */
#define TA0CCTL2                                           (HWREG16(0x40000006)) /* Timer_A Capture/Compare Control Register */
#define TA0CCTL3                                           (HWREG16(0x40000008)) /* Timer_A Capture/Compare Control Register */
#define TA0CCTL4                                           (HWREG16(0x4000000A)) /* Timer_A Capture/Compare Control Register */
#define TA0CCTL5                                           (HWREG16(0x4000000C)) /* Timer_A Capture/Compare Control Register */
#define TA0CCTL6                                           (HWREG16(0x4000000E)) /* Timer_A Capture/Compare Control Register */
#define TA0R                                               (HWREG16(0x40000010)) /* TimerA register */
#define TA0CCR0                                            (HWREG16(0x40000012)) /* Timer_A Capture/Compare  Register */
#define TA0CCR1                                            (HWREG16(0x40000014)) /* Timer_A Capture/Compare  Register */
#define TA0CCR2                                            (HWREG16(0x40000016)) /* Timer_A Capture/Compare  Register */
#define TA0CCR3                                            (HWREG16(0x40000018)) /* Timer_A Capture/Compare  Register */
#define TA0CCR4                                            (HWREG16(0x4000001A)) /* Timer_A Capture/Compare  Register */
#define TA0CCR5                                            (HWREG16(0x4000001C)) /* Timer_A Capture/Compare  Register */
#define TA0CCR6                                            (HWREG16(0x4000001E)) /* Timer_A Capture/Compare  Register */
#define TA0EX0                                             (HWREG16(0x40000020)) /* TimerAx Expansion 0 Register */
#define TA0IV                                              (HWREG16(0x4000002E)) /* TimerAx Interrupt Vector Register */

/* Register offsets from TIMER_A0_BASE address */
#define OFS_TA0CTL                                         (0x0000)              /* TimerAx Control Register */
#define OFS_TA0CCTL0                                       (0x0002)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA0CCTL1                                       (0x0004)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA0CCTL2                                       (0x0006)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA0CCTL3                                       (0x0008)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA0CCTL4                                       (0x000A)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA0CCTL5                                       (0x000C)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA0CCTL6                                       (0x000E)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA0R                                           (0x0010)              /* TimerA register */
#define OFS_TA0CCR0                                        (0x0012)              /* Timer_A Capture/Compare  Register */
#define OFS_TA0CCR1                                        (0x0014)              /* Timer_A Capture/Compare  Register */
#define OFS_TA0CCR2                                        (0x0016)              /* Timer_A Capture/Compare  Register */
#define OFS_TA0CCR3                                        (0x0018)              /* Timer_A Capture/Compare  Register */
#define OFS_TA0CCR4                                        (0x001A)              /* Timer_A Capture/Compare  Register */
#define OFS_TA0CCR5                                        (0x001C)              /* Timer_A Capture/Compare  Register */
#define OFS_TA0CCR6                                        (0x001E)              /* Timer_A Capture/Compare  Register */
#define OFS_TA0EX0                                         (0x0020)              /* TimerAx Expansion 0 Register */
#define OFS_TA0IV                                          (0x002e)              /* TimerAx Interrupt Vector Register */

/***************************************************************************
// TIMER_A1 Registers
***************************************************************************/
#define TA1CTL                                             (HWREG16(0x40000400)) /* TimerAx Control Register */
#define TA1CCTL0                                           (HWREG16(0x40000402)) /* Timer_A Capture/Compare Control Register */
#define TA1CCTL1                                           (HWREG16(0x40000404)) /* Timer_A Capture/Compare Control Register */
#define TA1CCTL2                                           (HWREG16(0x40000406)) /* Timer_A Capture/Compare Control Register */
#define TA1CCTL3                                           (HWREG16(0x40000408)) /* Timer_A Capture/Compare Control Register */
#define TA1CCTL4                                           (HWREG16(0x4000040A)) /* Timer_A Capture/Compare Control Register */
#define TA1CCTL5                                           (HWREG16(0x4000040C)) /* Timer_A Capture/Compare Control Register */
#define TA1CCTL6                                           (HWREG16(0x4000040E)) /* Timer_A Capture/Compare Control Register */
#define TA1R                                               (HWREG16(0x40000410)) /* TimerA register */
#define TA1CCR0                                            (HWREG16(0x40000412)) /* Timer_A Capture/Compare  Register */
#define TA1CCR1                                            (HWREG16(0x40000414)) /* Timer_A Capture/Compare  Register */
#define TA1CCR2                                            (HWREG16(0x40000416)) /* Timer_A Capture/Compare  Register */
#define TA1CCR3                                            (HWREG16(0x40000418)) /* Timer_A Capture/Compare  Register */
#define TA1CCR4                                            (HWREG16(0x4000041A)) /* Timer_A Capture/Compare  Register */
#define TA1CCR5                                            (HWREG16(0x4000041C)) /* Timer_A Capture/Compare  Register */
#define TA1CCR6                                            (HWREG16(0x4000041E)) /* Timer_A Capture/Compare  Register */
#define TA1EX0                                             (HWREG16(0x40000420)) /* TimerAx Expansion 0 Register */
#define TA1IV                                              (HWREG16(0x4000042E)) /* TimerAx Interrupt Vector Register */

/* Register offsets from TIMER_A1_BASE address */
#define OFS_TA1CTL                                         (0x0000)              /* TimerAx Control Register */
#define OFS_TA1CCTL0                                       (0x0002)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA1CCTL1                                       (0x0004)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA1CCTL2                                       (0x0006)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA1CCTL3                                       (0x0008)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA1CCTL4                                       (0x000A)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA1CCTL5                                       (0x000C)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA1CCTL6                                       (0x000E)              /* Timer_A Capture/Compare Control Register */
#define OFS_TA1R                                           (0x0010)              /* TimerA register */
#define OFS_TA1CCR0                                        (0x0012)              /* Timer_A Capture/Compare  Register */
#define OFS_TA1CCR1                                        (0x0014)              /* Timer_A Capture/Compare  Register */
#define OFS_TA1CCR2                                        (0x0016)              /* Timer_A Capture/Compare  Register */
#define OFS_TA1CCR3                                        (0x0018)              /* Timer_A Capture/Compare  Register */
#define OFS_TA1CCR4                                        (0x001A)              /* Timer_A Capture/Compare  Register */
#define OFS_TA1CCR5                                        (0x001C)              /* Timer_A Capture/Compare  Register */
#define OFS_TA1CCR6                                        (0x001E)              /* Timer_A Capture/Compare  Register */
#define OFS_TA1EX0                                         (0x0020)              /* TimerAx Expansion 0 Register */
#define OFS_TA1IV                                          (0x002e)              /* TimerAx Interrupt Vector Register */

/***************************************************************************
// TIMER_A2 Registers
***************************************************************************/
#define TA2CTL                                             (HWREG16(0x40000800)) /* TimerAx Control Register */
#define TA2CCTL0                                           (HWREG16(0x40000802)) /* Timer_A Capture/Compare Control Register */
#define TA2CCTL1                                           (HWREG16(0x40000804)) /* Timer_A Capture/Compare Control Register */
#define TA2CCTL2                                           (HWREG16(0x40000806)) /* Timer_A Capture/Compare Control Register */
#define TA2CCTL3                                           (HWREG16(0x40000808)) /* Timer_A Capture/Compare Control Register */
#define TA2CCTL4                                           (HWREG16(0x4000080A)) /* Timer_A Capture/Compare Control Register */
#define TA2CCTL5                                           (HWREG16(0x4000080C)) /* Timer_A Capture/Compare Control Register */
#define TA2CCTL6                                           (HWREG16(0x4000080E)) /* Timer_A Capture/Compare Control Register */
#define TA2R                                               (HWREG16(0x40000810)) /* TimerA register */
#define TA2CCR0                                            (HWREG16(0x40000812)) /* Timer_A Capture/Compare  Register */
#define TA2CCR1                                            (HWREG16(0x40000814)) /* Timer_A Capture/Compare  Register */
#define TA2CCR2                                            (HWREG16(0x40000816)) /* Timer_A Capture/Compare  Register */
#define TA2CCR3                                            (HWREG16(0x40000818)) /* Timer_A Capture/Compare  Register */
#define TA2CCR4                                            (HWREG16(0x4000081A)) /* Timer_A Capture/Compare  Register */
#define TA2CCR5                                            (HWREG16(0x4000081C)) /* Timer_A Capture/Compare  Register */
#define TA2CCR6                                            (HWREG16(0x4000081E)) /* Timer_A Capture/Compare  Register */
#define TA2EX0                                             (HWREG16(0x40000820)) /* TimerAx Expansion 0 Register */
#define TA2IV                                              (HWREG16(0x4000082E)) /* TimerAx Interrupt Vector Register */

/***************************************************************************
// TIMER32 Registers
***************************************************************************/
#define TIMER32_LOAD1                                      (HWREG32(0x4000C000)) /* Timer 1 Load Register */
#define TIMER32_VALUE1                                     (HWREG32(0x4000C004)) /* Timer 1 Current Value Register */
#define TIMER32_CONTROL1                                   (HWREG32(0x4000C008)) /* Timer 1 Timer Control Register */
#define TIMER32_INTCLR1                                    (HWREG32(0x4000C00C)) /* Timer 1 Interrupt Clear Register */
#define TIMER32_RIS1                                       (HWREG32(0x4000C010)) /* Timer 1 Raw Interrupt Status Register */
#define TIMER32_MIS1                                       (HWREG32(0x4000C014)) /* Timer 1 Interrupt Status Register */
#define TIMER32_BGLOAD1                                    (HWREG32(0x4000C018)) /* Timer 1 Background Load Register */
#define TIMER32_LOAD2                                      (HWREG32(0x4000C020)) /* Timer 2 Load Register */
#define TIMER32_VALUE2                                     (HWREG32(0x4000C024)) /* Timer 2 Current Value Register */
#define TIMER32_CONTROL2                                   (HWREG32(0x4000C028)) /* Timer 2 Timer Control Register */
#define TIMER32_INTCLR2                                    (HWREG32(0x4000C02C)) /* Timer 2 Interrupt Clear Register */
#define TIMER32_RIS2                                       (HWREG32(0x4000C030)) /* Timer 2 Raw Interrupt Status Register */
#define TIMER32_MIS2                                       (HWREG32(0x4000C034)) /* Timer 2 Interrupt Status Register */
#define TIMER32_BGLOAD2                                    (HWREG32(0x4000C038)) /* Timer 2 Background Load Register */

/* Register offsets from TIMER32_BASE address */
#define OFS_TIMER32_LOAD1                                  (0x00000000)          /* Timer 1 Load Register */
#define OFS_TIMER32_VALUE1                                 (0x00000004)          /* Timer 1 Current Value Register */
#define OFS_TIMER32_CONTROL1                               (0x00000008)          /* Timer 1 Timer Control Register */
#define OFS_TIMER32_INTCLR1                                (0x0000000C)          /* Timer 1 Interrupt Clear Register */
#define OFS_TIMER32_RIS1                                   (0x00000010)          /* Timer 1 Raw Interrupt Status Register */
#define OFS_TIMER32_MIS1                                   (0x00000014)          /* Timer 1 Interrupt Status Register */
#define OFS_TIMER32_BGLOAD1                                (0x00000018)          /* Timer 1 Background Load Register */
#define OFS_TIMER32_LOAD2                                  (0x00000020)          /* Timer 2 Load Register */
#define OFS_TIMER32_VALUE2                                 (0x00000024)          /* Timer 2 Current Value Register */
#define OFS_TIMER32_CONTROL2                               (0x00000028)          /* Timer 2 Timer Control Register */
#define OFS_TIMER32_INTCLR2                                (0x0000002C)          /* Timer 2 Interrupt Clear Register */
#define OFS_TIMER32_RIS2                                   (0x00000030)          /* Timer 2 Raw Interrupt Status Register */
#define OFS_TIMER32_MIS2                                   (0x00000034)          /* Timer 2 Interrupt Status Register */
#define OFS_TIMER32_BGLOAD2                                (0x00000038)          /* Timer 2 Background Load Register */

/***************************************************************************
// EUSCI_B0 Registers
***************************************************************************/
#define UCB0CTLW0                                          (HWREG16(0x40002000)) /* eUSCI_Bx Control Word Register 0 */
#define UCB0CTLW0_SPI                                      (HWREG16(0x40002000)) /*  */
#define UCB0CTLW1                                          (HWREG16(0x40002002)) /* eUSCI_Bx Control Word Register 1 */
#define UCB0BRW                                            (HWREG16(0x40002006)) /* eUSCI_Bx Baud Rate Control Word Register */
#define UCB0BRW_SPI                                        (HWREG16(0x40002006)) /*  */
#define UCB0STATW                                          (HWREG16(0x40002008)) /* eUSCI_Bx Status Register */
#define UCB0STATW_SPI                                      (HWREG16(0x40002008)) /*  */
#define UCB0TBCNT                                          (HWREG16(0x4000200A)) /* eUSCI_Bx Byte Counter Threshold Register */
#define UCB0RXBUF                                          (HWREG16(0x4000200C)) /* eUSCI_Bx Receive Buffer Register */
#define UCB0RXBUF_SPI                                      (HWREG16(0x4000200C)) /*  */
#define UCB0TXBUF                                          (HWREG16(0x4000200E)) /* eUSCI_Bx Transmit Buffer Register */
#define UCB0TXBUF_SPI                                      (HWREG16(0x4000200E)) /*  */
#define UCB0I2COA0                                         (HWREG16(0x40002014)) /* eUSCI_Bx I2C Own Address 0 Register */
#define UCB0I2COA1                                         (HWREG16(0x40002016)) /* eUSCI_Bx I2C Own Address 1 Register */
#define UCB0I2COA2                                         (HWREG16(0x40002018)) /* eUSCI_Bx I2C Own Address 2 Register */
#define UCB0I2COA3                                         (HWREG16(0x4000201A)) /* eUSCI_Bx I2C Own Address 3 Register */
#define UCB0ADDRX                                          (HWREG16(0x4000201C)) /* eUSCI_Bx I2C Received Address Register */
#define UCB0ADDMASK                                        (HWREG16(0x4000201E)) /* eUSCI_Bx I2C Address Mask Register */
#define UCB0I2CSA                                          (HWREG16(0x40002020)) /* eUSCI_Bx I2C Slave Address Register */
#define UCB0IE                                             (HWREG16(0x4000202A)) /* eUSCI_Bx Interrupt Enable Register */
#define UCB0IE_SPI                                         (HWREG16(0x4000202A)) /*  */
#define UCB0IFG                                            (HWREG16(0x4000202C)) /* eUSCI_Bx Interrupt Flag Register */
#define UCB0IFG_SPI                                        (HWREG16(0x4000202C)) /*  */
#define UCB0IV                                             (HWREG16(0x4000202E)) /* eUSCI_Bx Interrupt Vector Register */
#define UCB0IV_SPI                                         (HWREG16(0x4000202E)) /*  */

/* Register offsets from EUSCI_B0_BASE address */
#define OFS_UCB0CTLW0                                      (0x0000)              /* eUSCI_Bx Control Word Register 0 */
#define OFS_UCB0CTLW0_SPI                                  (0x0000)              /*  */
#define OFS_UCB0CTLW1                                      (0x0002)              /* eUSCI_Bx Control Word Register 1 */
#define OFS_UCB0BRW                                        (0x0006)              /* eUSCI_Bx Baud Rate Control Word Register */
#define OFS_UCB0BRW_SPI                                    (0x0006)              /*  */
#define OFS_UCB0STATW                                      (0x0008)              /* eUSCI_Bx Status Register */
#define OFS_UCB0STATW_SPI                                  (0x0008)              /*  */
#define OFS_UCB0TBCNT                                      (0x000a)              /* eUSCI_Bx Byte Counter Threshold Register */
#define OFS_UCB0RXBUF                                      (0x000c)              /* eUSCI_Bx Receive Buffer Register */
#define OFS_UCB0RXBUF_SPI                                  (0x000c)              /*  */
#define OFS_UCB0TXBUF                                      (0x000e)              /* eUSCI_Bx Transmit Buffer Register */
#define OFS_UCB0TXBUF_SPI                                  (0x000e)              /*  */
#define OFS_UCB0I2COA0                                     (0x0014)              /* eUSCI_Bx I2C Own Address 0 Register */
#define OFS_UCB0I2COA1                                     (0x0016)              /* eUSCI_Bx I2C Own Address 1 Register */
#define OFS_UCB0I2COA2                                     (0x0018)              /* eUSCI_Bx I2C Own Address 2 Register */
#define OFS_UCB0I2COA3                                     (0x001a)              /* eUSCI_Bx I2C Own Address 3 Register */
#define OFS_UCB0ADDRX                                      (0x001c)              /* eUSCI_Bx I2C Received Address Register */
#define OFS_UCB0ADDMASK                                    (0x001e)              /* eUSCI_Bx I2C Address Mask Register */
#define OFS_UCB0I2CSA                                      (0x0020)              /* eUSCI_Bx I2C Slave Address Register */
#define OFS_UCB0IE                                         (0x002a)              /* eUSCI_Bx Interrupt Enable Register */
#define OFS_UCB0IE_SPI                                     (0x002a)              /*  */
#define OFS_UCB0IFG                                        (0x002c)              /* eUSCI_Bx Interrupt Flag Register */
#define OFS_UCB0IFG_SPI                                    (0x002c)              /*  */
#define OFS_UCB0IV                                         (0x002e)              /* eUSCI_Bx Interrupt Vector Register */
#define OFS_UCB0IV_SPI                                     (0x002e)              /*  */

#define UCB0CTL0                                           (HWREG8_L(UCB0CTLW0)) /* eUSCI_Bx Control 1 */
#define UCB0CTL1                                           (HWREG8_H(UCB0CTLW0)) /* eUSCI_Bx Control 0 */
#define UCB0BR0                                            (HWREG8_L(UCB0BRW))   /* eUSCI_Bx Bit Rate Control 0 */
#define UCB0BR1                                            (HWREG8_H(UCB0BRW))   /* eUSCI_Bx Bit Rate Control 1 */
#define UCB0STAT                                           (HWREG8_L(UCB0STATW)) /* eUSCI_Bx Status */
#define UCB0BCNT                                           (HWREG8_H(UCB0STATW)) /* eUSCI_Bx Byte Counter Register */

/***************************************************************************
// EUSCI_B1 Registers
***************************************************************************/
#define UCB1CTLW0                                          (HWREG16(0x40002400)) /* eUSCI_Bx Control Word Register 0 */
#define UCB1CTLW0_SPI                                      (HWREG16(0x40002400)) /*  */
#define UCB1CTLW1                                          (HWREG16(0x40002402)) /* eUSCI_Bx Control Word Register 1 */
#define UCB1BRW                                            (HWREG16(0x40002406)) /* eUSCI_Bx Baud Rate Control Word Register */
#define UCB1BRW_SPI                                        (HWREG16(0x40002406)) /*  */
#define UCB1STATW                                          (HWREG16(0x40002408)) /* eUSCI_Bx Status Register */
#define UCB1STATW_SPI                                      (HWREG16(0x40002408)) /*  */
#define UCB1TBCNT                                          (HWREG16(0x4000240A)) /* eUSCI_Bx Byte Counter Threshold Register */
#define UCB1RXBUF                                          (HWREG16(0x4000240C)) /* eUSCI_Bx Receive Buffer Register */
#define UCB1RXBUF_SPI                                      (HWREG16(0x4000240C)) /*  */
#define UCB1TXBUF                                          (HWREG16(0x4000240E)) /* eUSCI_Bx Transmit Buffer Register */
#define UCB1TXBUF_SPI                                      (HWREG16(0x4000240E)) /*  */
#define UCB1I2COA0                                         (HWREG16(0x40002414)) /* eUSCI_Bx I2C Own Address 0 Register */
#define UCB1I2COA1                                         (HWREG16(0x40002416)) /* eUSCI_Bx I2C Own Address 1 Register */
#define UCB1I2COA2                                         (HWREG16(0x40002418)) /* eUSCI_Bx I2C Own Address 2 Register */
#define UCB1I2COA3                                         (HWREG16(0x4000241A)) /* eUSCI_Bx I2C Own Address 3 Register */
#define UCB1ADDRX                                          (HWREG16(0x4000241C)) /* eUSCI_Bx I2C Received Address Register */
#define UCB1ADDMASK                                        (HWREG16(0x4000241E)) /* eUSCI_Bx I2C Address Mask Register */
#define UCB1I2CSA                                          (HWREG16(0x40002420)) /* eUSCI_Bx I2C Slave Address Register */
#define UCB1IE                                             (HWREG16(0x4000242A)) /* eUSCI_Bx Interrupt Enable Register */
#define UCB1IE_SPI                                         (HWREG16(0x4000242A)) /*  */
#define UCB1IFG                                            (HWREG16(0x4000242C)) /* eUSCI_Bx Interrupt Flag Register */
#define UCB1IFG_SPI                                        (HWREG16(0x4000242C)) /*  */
#define UCB1IV                                             (HWREG16(0x4000242E)) /* eUSCI_Bx Interrupt Vector Register */
#define UCB1IV_SPI                                         (HWREG16(0x4000242E)) /*  */

/* Register offsets from EUSCI_B1_BASE address */
#define OFS_UCB1CTLW0                                      (0x0000)              /* eUSCI_Bx Control Word Register 0 */
#define OFS_UCB1CTLW0_SPI                                  (0x0000)              /*  */
#define OFS_UCB1CTLW1                                      (0x0002)              /* eUSCI_Bx Control Word Register 1 */
#define OFS_UCB1BRW                                        (0x0006)              /* eUSCI_Bx Baud Rate Control Word Register */
#define OFS_UCB1BRW_SPI                                    (0x0006)              /*  */
#define OFS_UCB1STATW                                      (0x0008)              /* eUSCI_Bx Status Register */
#define OFS_UCB1STATW_SPI                                  (0x0008)              /*  */
#define OFS_UCB1TBCNT                                      (0x000a)              /* eUSCI_Bx Byte Counter Threshold Register */
#define OFS_UCB1RXBUF                                      (0x000c)              /* eUSCI_Bx Receive Buffer Register */
#define OFS_UCB1RXBUF_SPI                                  (0x000c)              /*  */
#define OFS_UCB1TXBUF                                      (0x000e)              /* eUSCI_Bx Transmit Buffer Register */
#define OFS_UCB1TXBUF_SPI                                  (0x000e)              /*  */
#define OFS_UCB1I2COA0                                     (0x0014)              /* eUSCI_Bx I2C Own Address 0 Register */
#define OFS_UCB1I2COA1                                     (0x0016)              /* eUSCI_Bx I2C Own Address 1 Register */
#define OFS_UCB1I2COA2                                     (0x0018)              /* eUSCI_Bx I2C Own Address 2 Register */
#define OFS_UCB1I2COA3                                     (0x001a)              /* eUSCI_Bx I2C Own Address 3 Register */
#define OFS_UCB1ADDRX                                      (0x001c)              /* eUSCI_Bx I2C Received Address Register */
#define OFS_UCB1ADDMASK                                    (0x001e)              /* eUSCI_Bx I2C Address Mask Register */
#define OFS_UCB1I2CSA                                      (0x0020)              /* eUSCI_Bx I2C Slave Address Register */
#define OFS_UCB1IE                                         (0x002a)              /* eUSCI_Bx Interrupt Enable Register */
#define OFS_UCB1IE_SPI                                     (0x002a)              /*  */
#define OFS_UCB1IFG                                        (0x002c)              /* eUSCI_Bx Interrupt Flag Register */
#define OFS_UCB1IFG_SPI                                    (0x002c)              /*  */
#define OFS_UCB1IV                                         (0x002e)              /* eUSCI_Bx Interrupt Vector Register */
#define OFS_UCB1IV_SPI                                     (0x002e)              /*  */

#define UCB1CTL0                                           (HWREG8_L(UCB1CTLW0)) /* eUSCI_Bx Control 1 */
#define UCB1CTL1                                           (HWREG8_H(UCB1CTLW0)) /* eUSCI_Bx Control 0 */
#define UCB1BR0                                            (HWREG8_L(UCB1BRW))   /* eUSCI_Bx Bit Rate Control 0 */
#define UCB1BR1                                            (HWREG8_H(UCB1BRW))   /* eUSCI_Bx Bit Rate Control 1 */
#define UCB1STAT                                           (HWREG8_L(UCB1STATW)) /* eUSCI_Bx Status */
#define UCB1BCNT                                           (HWREG8_H(UCB1STATW)) /* eUSCI_Bx Byte Counter Register */

/***************************************************************************
// PCM Registers
***************************************************************************/
#define PCMCTL0                                            (HWREG32(0x40010000)) /* Control 0 Register */
#define PCMCTL1                                            (HWREG32(0x40010004)) /* Control 1 Register */
#define PCMIE                                              (HWREG32(0x40010008)) /* Interrupt Enable Register */
#define PCMIFG                                             (HWREG32(0x4001000C)) /* Interrupt Flag Register */
#define PCMCLRIFG                                          (HWREG32(0x40010010)) /* Clear Interrupt Flag Register */

/* Register offsets from PCM_BASE address */
#define OFS_PCMCTL0                                        (0x00000000)          /* Control 0 Register */
#define OFS_PCMCTL1                                        (0x00000004)          /* Control 1 Register */
#define OFS_PCMIE                                          (0x00000008)          /* Interrupt Enable Register */
#define OFS_PCMIFG                                         (0x0000000c)          /* Interrupt Flag Register */
#define OFS_PCMCLRIFG                                      (0x00000010)          /* Clear Interrupt Flag Register */

/***************************************************************************
// CS Registers
***************************************************************************/
#define CSKEY                                              (HWREG32(0x40010400)) /* Key Register */
#define CSCTL0                                             (HWREG32(0x40010404)) /* Control 0 Register */
#define CSCTL1                                             (HWREG32(0x40010408)) /* Control 1 Register */
#define CSCTL2                                             (HWREG32(0x4001040C)) /* Control 2 Register */
#define CSCTL3                                             (HWREG32(0x40010410)) /* Control 3 Register */
#define CSCTL4                                             (HWREG32(0x40010414)) /* Control 4 Register */
#define CSCTL5                                             (HWREG32(0x40010418)) /* Control 5 Register */
#define CSCTL6                                             (HWREG32(0x4001041C)) /* Control 6 Register */
#define CSCTL7                                             (HWREG32(0x40010420)) /* Control 7 Register */
#define CSCLKEN                                            (HWREG32(0x40010430)) /* Clock Enable Register */
#define CSSTAT                                             (HWREG32(0x40010434)) /* Status Register */
#define CSIE                                               (HWREG32(0x40010440)) /* Interrupt Enable Register */
#define CSIFG                                              (HWREG32(0x40010448)) /* Interrupt Flag Register */
#define CSCLRIFG                                           (HWREG32(0x40010450)) /* Clear Interrupt Flag Register */
#define CSSETIFG                                           (HWREG32(0x40010458)) /* Set Interrupt Flag Register */
#define CSDCOERCAL                                         (HWREG32(0x40010460)) /* DCO external resistor cailbration register */

/* Register offsets from CS_BASE address */
#define OFS_CSKEY                                          (0x00000000)          /* Key Register */
#define OFS_CSCTL0                                         (0x00000004)          /* Control 0 Register */
#define OFS_CSCTL1                                         (0x00000008)          /* Control 1 Register */
#define OFS_CSCTL2                                         (0x0000000c)          /* Control 2 Register */
#define OFS_CSCTL3                                         (0x00000010)          /* Control 3 Register */
#define OFS_CSCTL4                                         (0x00000014)          /* Control 4 Register */
#define OFS_CSCTL5                                         (0x00000018)          /* Control 5 Register */
#define OFS_CSCTL6                                         (0x0000001c)          /* Control 6 Register */
#define OFS_CSCTL7                                         (0x00000020)          /* Control 7 Register */
#define OFS_CSCLKEN                                        (0x00000030)          /* Clock Enable Register */
#define OFS_CSSTAT                                         (0x00000034)          /* Status Register */
#define OFS_CSIE                                           (0x00000040)          /* Interrupt Enable Register */
#define OFS_CSIFG                                          (0x00000048)          /* Interrupt Flag Register */
#define OFS_CSCLRIFG                                       (0x00000050)          /* Clear Interrupt Flag Register */
#define OFS_CSSETIFG                                       (0x00000058)          /* Set Interrupt Flag Register */
#define OFS_CSDCOERCAL                                     (0x00000060)          /* DCO external resistor cailbration register */

/***************************************************************************
// FLCTL Registers
***************************************************************************/
#define FLCTL_POWER_STAT                                   (HWREG32(0x40011000)) /* Power Status Register */
#define FLCTL_BANK0_RDCTL                                  (HWREG32(0x40011010)) /* Bank0 Read Control Register */
#define FLCTL_BANK1_RDCTL                                  (HWREG32(0x40011014)) /* Bank1 Read Control Register */
#define FLCTL_RDBRST_CTLSTAT                               (HWREG32(0x40011020)) /* Read Burst/Compare Control and Status Register */
#define FLCTL_RDBRST_STARTADDR                             (HWREG32(0x40011024)) /* Read Burst/Compare Start Address Register */
#define FLCTL_RDBRST_LEN                                   (HWREG32(0x40011028)) /* Read Burst/Compare Length Register */
#define FLCTL_RDBRST_FAILADDR                              (HWREG32(0x4001103C)) /* Read Burst/Compare Fail Address Register */
#define FLCTL_RDBRST_FAILCNT                               (HWREG32(0x40011040)) /* Read Burst/Compare Fail Count Register */
#define FLCTL_PRG_CTLSTAT                                  (HWREG32(0x40011050)) /* Program Control and Status Register */
#define FLCTL_PRGBRST_CTLSTAT                              (HWREG32(0x40011054)) /* Program Burst Control and Status Register */
#define FLCTL_PRGBRST_STARTADDR                            (HWREG32(0x40011058)) /* Program Burst Start Address Register */
#define FLCTL_PRGBRST_DATA0_0                              (HWREG32(0x40011060)) /* Program Burst Data0 Register0 */
#define FLCTL_PRGBRST_DATA0_1                              (HWREG32(0x40011064)) /* Program Burst Data0 Register1 */
#define FLCTL_PRGBRST_DATA0_2                              (HWREG32(0x40011068)) /* Program Burst Data0 Register2 */
#define FLCTL_PRGBRST_DATA0_3                              (HWREG32(0x4001106C)) /* Program Burst Data0 Register3 */
#define FLCTL_PRGBRST_DATA1_0                              (HWREG32(0x40011070)) /* Program Burst Data1 Register0 */
#define FLCTL_PRGBRST_DATA1_1                              (HWREG32(0x40011074)) /* Program Burst Data1 Register1 */
#define FLCTL_PRGBRST_DATA1_2                              (HWREG32(0x40011078)) /* Program Burst Data1 Register2 */
#define FLCTL_PRGBRST_DATA1_3                              (HWREG32(0x4001107C)) /* Program Burst Data1 Register3 */
#define FLCTL_PRGBRST_DATA2_0                              (HWREG32(0x40011080)) /* Program Burst Data2 Register0 */
#define FLCTL_PRGBRST_DATA2_1                              (HWREG32(0x40011084)) /* Program Burst Data2 Register1 */
#define FLCTL_PRGBRST_DATA2_2                              (HWREG32(0x40011088)) /* Program Burst Data2 Register2 */
#define FLCTL_PRGBRST_DATA2_3                              (HWREG32(0x4001108C)) /* Program Burst Data2 Register3 */
#define FLCTL_PRGBRST_DATA3_0                              (HWREG32(0x40011090)) /* Program Burst Data3 Register0 */
#define FLCTL_PRGBRST_DATA3_1                              (HWREG32(0x40011094)) /* Program Burst Data3 Register1 */
#define FLCTL_PRGBRST_DATA3_2                              (HWREG32(0x40011098)) /* Program Burst Data3 Register2 */
#define FLCTL_PRGBRST_DATA3_3                              (HWREG32(0x4001109C)) /* Program Burst Data3 Register3 */
#define FLCTL_ERASE_CTLSTAT                                (HWREG32(0x400110A0)) /* Erase Control and Status Register */
#define FLCTL_ERASE_SECTADDR                               (HWREG32(0x400110A4)) /* Erase Sector Address Register */
#define FLCTL_BANK0_INFO_WEPROT                            (HWREG32(0x400110B0)) /* Information Memory Bank0 Write/Erase Protection Register */
#define FLCTL_BANK0_MAIN_WEPROT                            (HWREG32(0x400110B4)) /* Main Memory Bank0 Write/Erase Protection Register */
#define FLCTL_BANK1_INFO_WEPROT                            (HWREG32(0x400110C0)) /* Information Memory Bank1 Write/Erase Protection Register */
#define FLCTL_BANK1_MAIN_WEPROT                            (HWREG32(0x400110C4)) /* Main Memory Bank1 Write/Erase Protection Register */
#define FLCTL_BMRK_CTLSTAT                                 (HWREG32(0x400110D0)) /* Benchmark Control and Status Register */
#define FLCTL_BMRK_IFETCH                                  (HWREG32(0x400110D4)) /* Benchmark Instruction Fetch Count Register */
#define FLCTL_BMRK_DREAD                                   (HWREG32(0x400110D8)) /* Benchmark Data Read Count Register */
#define FLCTL_BMRK_CMP                                     (HWREG32(0x400110DC)) /* Benchmark Count Compare Register */
#define FLCTL_IFG                                          (HWREG32(0x400110F0)) /* Interrupt Flag Register */
#define FLCTL_IE                                           (HWREG32(0x400110F4)) /* Interrupt Enable Register */
#define FLCTL_CLRIFG                                       (HWREG32(0x400110F8)) /* Clear Interrupt Flag Register */
#define FLCTL_SETIFG                                       (HWREG32(0x400110FC)) /* Set Interrupt Flag Register */
#define FLCTL_READ_TIMCTL                                  (HWREG32(0x40011100)) /* Read Timing Control Register */
#define FLCTL_READMARGIN_TIMCTL                            (HWREG32(0x40011104)) /* Read Margin Timing Control Register */
#define FLCTL_PRGVER_TIMCTL                                (HWREG32(0x40011108)) /* Program Verify Timing Control Register */
#define FLCTL_ERSVER_TIMCTL                                (HWREG32(0x4001110C)) /* Erase Verify Timing Control Register */
#define FLCTL_LKGVER_TIMCTL                                (HWREG32(0x40011110)) /* Leakage Verify Timing Control Register */
#define FLCTL_PROGRAM_TIMCTL                               (HWREG32(0x40011114)) /* Program Timing Control Register */
#define FLCTL_ERASE_TIMCTL                                 (HWREG32(0x40011118)) /* Erase Timing Control Register */
#define FLCTL_MASSERASE_TIMCTL                             (HWREG32(0x4001111C)) /* Mass Erase Timing Control Register */
#define FLCTL_BURSTPRG_TIMCTL                              (HWREG32(0x40011120)) /* Burst Program Timing Control Register */

/***************************************************************************
// NVIC Registers
***************************************************************************/
#define NVIC_ISER0                                         (HWREG32(0xE000E100)) /* Irq 0 to 31 Set Enable Register */
#define NVIC_ISER1                                         (HWREG32(0xE000E104)) /* Irq 32 to 63 Set Enable Register */
#define NVIC_ICER0                                         (HWREG32(0xE000E180)) /* Irq 0 to 31 Clear Enable Register */
#define NVIC_ICER1                                         (HWREG32(0xE000E184)) /* Irq 32 to 63 Clear Enable Register */
#define NVIC_ISPR0                                         (HWREG32(0xE000E200)) /* Irq 0 to 31 Set Pending Register */
#define NVIC_ISPR1                                         (HWREG32(0xE000E204)) /* Irq 32 to 63 Set Pending Register */
#define NVIC_ICPR0                                         (HWREG32(0xE000E280)) /* Irq 0 to 31 Clear Pending Register */
#define NVIC_ICPR1                                         (HWREG32(0xE000E284)) /* Irq 32 to 63 Clear Pending Register */
#define NVIC_IABR0                                         (HWREG32(0xE000E300)) /* Irq 0 to 31 Active Bit Register */
#define NVIC_IABR1                                         (HWREG32(0xE000E304)) /* Irq 32 to 63 Active Bit Register */
#define NVIC_IPR0                                          (HWREG32(0xE000E400)) /* Irq 0 to 3 Priority Register */
#define NVIC_IPR1                                          (HWREG32(0xE000E404)) /* Irq 4 to 7 Priority Register */
#define NVIC_IPR2                                          (HWREG32(0xE000E408)) /* Irq 8 to 11 Priority Register */
#define NVIC_IPR3                                          (HWREG32(0xE000E40C)) /* Irq 12 to 15 Priority Register */
#define NVIC_IPR4                                          (HWREG32(0xE000E410)) /* Irq 16 to 19 Priority Register */
#define NVIC_IPR5                                          (HWREG32(0xE000E414)) /* Irq 20 to 23 Priority Register */
#define NVIC_IPR6                                          (HWREG32(0xE000E418)) /* Irq 24 to 27 Priority Register */
#define NVIC_IPR7                                          (HWREG32(0xE000E41C)) /* Irq 28 to 31 Priority Register */
#define NVIC_IPR8                                          (HWREG32(0xE000E420)) /* Irq 32 to 35 Priority Register */
#define NVIC_IPR9                                          (HWREG32(0xE000E424)) /* Irq 36 to 39 Priority Register */
#define NVIC_IPR10                                         (HWREG32(0xE000E428)) /* Irq 40 to 43 Priority Register */
#define NVIC_IPR11                                         (HWREG32(0xE000E42C)) /* Irq 44 to 47 Priority Register */
#define NVIC_IPR12                                         (HWREG32(0xE000E430)) /* Irq 48 to 51 Priority Register */
#define NVIC_IPR13                                         (HWREG32(0xE000E434)) /* Irq 52 to 55 Priority Register */
#define NVIC_IPR14                                         (HWREG32(0xE000E438)) /* Irq 56 to 59 Priority Register */
#define NVIC_IPR15                                         (HWREG32(0xE000E43C)) /* Irq 60 to 63 Priority Register */
#define NVIC_STIR                                          (HWREG32(0xE000EF00)) /* Software Trigger Interrupt Register */

/* end of file */
