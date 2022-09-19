/**
 * @file    clk.h
 * @author  helder
 * @brief   CLK funcionalities module header file.
 */

#ifndef CLK_H
#define CLK_H

#define CLK_OK      (0)
#define CLK_ERROR   (-1)

/** 
 * @brief This function sets the clock speed.
 * 
 * It is board dependant. Therefore we choose what clk speed level we want
 * and the frequency will be set acordingly.
 * The higher the level, the faster the clk: 0 being the slowest and 255 the
 * fastest clk possible.
 *
 * @param clk_speed_level The speed level, from 0 to 255.
 * @param p_system_clk_Hz Pointer to save the system frequency, main clock.
 * @param p_subsystem_clk_Hz Pointer to save the subsystem frequency.
 * @return CLK_OK on success, CLK_ERROR otherwise.
 */
int8_t CLK_set_clk_speed_level(
    uint8_t clk_speed_level,
    uint32_t* p_system_clk_Hz,
    uint32_t* p_subsystem_clk_Hz);

#endif /* CLK_H */

/* end of file */
