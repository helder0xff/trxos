    .thumb
    .text
    .align 2
    .syntax unified
    .extern g_main_thread_list
    .globl  TRXOS_Start_OS
    .type   TRXOS_Start_OS,%function
    .globl  SysTick_Handler
    .type   SysTick_Handler,%function
    .globl  TRXOS_Scheduler

TRXOS_Start_OS:
    CPSID   I                       @ Disable interrupts.
    ldr     R0, =g_main_thread_list  @ R0 = &
    ldr     R1, [R0]
    ldr     SP, [R1, #16]
    pop     {R4-R11}
    pop     {R0-R3}
    pop     {R12}
    add     SP, SP, #4
    pop     {LR}
    add     SP, SP, #4
    CPSIE   I
    BX      LR

SysTick_Handler:
    CPSID   I                       @ A comment
    push    {R4-R11}
    ldr     R0, =g_main_thread_list
    ldr     R1, [R0, #4]
    str     SP, [R1, #16]
    @ldr     R1, [R1]
    @str     R1, [R0, #4]
    push    {R0, LR}
    bl      TRXOS_Scheduler
    pop     {R0, LR}
    ldr     R0, =g_main_thread_list
    ldr     R1, [R0, #4]    
    ldr     SP, [R1, #16]
    pop     {R4-R11}
    CPSIE   I
    BX      LR    