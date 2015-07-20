  .syntax unified
  .cpu cortex-m4
  .fpu softvfp
  .thumb

  .global testFunc

  .section .text.testFunc
  .type testFunc, %function

testFunc:
	//movs r0, #0x12
	//movs r1, #0x34
	//stmdb sp!, {r0,r1}
	//ldmia sp!, {r0,r1}
	//push {r1,r0}
	//movs r2, #0x56
	//push {lr}
	//movs r0, #0x12
	//pop {lr}
	//ldr  r3, = 0x123456
	//movw.w r4, 0x1234 //move word = 16bits btm part
	//movt.w r4, 0xface //movw word = 16bits top part
	//bx lr
		//stmdb sp!, {r0,r1}
	//ldmia sp!, {r0,r1}
	//push {r1,r0}
	//movs r2, #0x56
	//push {lr}
	//movs r0, #0x12
	//bl dummy
	//pop {lr}
	//ldr  r3, = 0x123456
	//movw.w r4, 0x1234 //move word = 16bits btm part
	//movt.w r4, 0xface //movw word = 16bits top part
	//bx lr

