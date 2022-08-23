    .thumb
    .text
    .align 2
    .syntax unified
    .extern g_main_thread_list
    .globl  TRXOS_start_OS
    .type   TRXOS_start_OS,%function
    .globl  SysTick_Handler
    .type   SysTick_Handler,%function
    .globl  TRXOS_Scheduler

TRXOS_start_OS:
    CPSID   I                           @ Disable interrupts.
    ldr     R0, =g_main_thread_list     @ R0 = &g_main_thread_list.
    ldr     R1, [R0]                    @ R1 = *g_main_thread_list.
    ldr     SP, [R1, #16]               @ Load SP.
    @pop     {R4-R11}                    @ Pop R4-R11.
    @pop     {R0-R3}                     @ Pop R0-R3.
    @pop     {R12}                       @ Pop R12.
    add     SP, SP, #56                  @ Skip thread LR, SP->thread PC.
    pop     {LR}                        @ Load thread PC onto LR.
    add     SP, SP, #4                  @ Skip trhead SR,SP->thread stack bottom.
    CPSIE   I                           @ Enable interrupts.
    BX      LR                          @ Jump to LR, LR = thread PC.

SysTick_Handler:
    CPSID   I                           @ Disable interrupts.
    push    {R4-R11}                    @ Save current R4-R11.
    ldr     R0, =g_main_thread_list     @ R0 = &g_main_thread_list.
    ldr     R1, [R0, #4]                @ R1 = *g_main_thread_list.
    str     SP, [R1, #16]               @ Save SP.
    push    {R0, LR}                    @ Launch the scheduler which        ... 
    bl      TRXOS_Scheduler             @ ... wil make the switch to the    ... 
    pop     {R0, LR}                    @ ... new thread.
    ldr     R0, =g_main_thread_list     @ Load the new          ...
    ldr     R1, [R0, #4]                @ ... thread SP onto    ...
    ldr     SP, [R1, #16]               @ ... the processor SP.
    pop     {R4-R11}                    @ Load R4-R11
    CPSIE   I                           @ Enable interrupts.
    BX      LR                          @ Jump onto thread.