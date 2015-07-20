  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global taskSwitch
  .global SysTick_Handler

  .extern HAL_IncTick
  .extern taskOneStack
  .extern taskTwoStack
  .extern mainQueue
  .extern readyQueue

  .section .text.taskSwitch
  .type taskSwitch, %function
/*
taskSwitch:
	ldr r0, =#0x11111111
	ldr r1, =#0x22222222
	ldr r2, =#0x33333333
	ldr r3, =#0x44444444
	ldr r4, =#0x55555555
	ldr r5, =#0x66666666
	ldr r6, =#0x77777777
	ldr r7, =#0x88888888
	ldr r8, =#0x99999999
	ldr r9, =#0xaaaaaaaa
	ldr r10,=#0xbbbbbbbb
	ldr r11,=#0xcccccccc
	ldr r12,=#0xdddddddd
	ldr lr, =#0xffffffff
	push	{r4-r11}
	b    	.
*/

   .align 8
   .type SysTick_Handler, %function
SysTick_Handler:
 	push 	{r4-r11}
  	ldr 	r0, = mainQueue
  	ldr 	r1, [r0]
  	ldr 	r1, [r0,#4]
	str 	sp, [r1,#4]
	ldr 	r0, =readyQueue
	ldr		r1,[r0]
	ldr 	sp, [r1, #4]
	pop 	{r4-r11}
    bx     lr


//	push {r4-r11}
//	ldr r0,= mainQueue
//	str sp,[r1,#4]
//	ldr r0,= readyQueue
//	ldr r1,[r0]
//	ldr r2,[r1,#4]
//	pop {r4-r11}
//	ldr r5,[r2,#4]
//	ldr pc,[r2,#56]
//	bx  lr




