#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "main.h"
#include "initLED.h"
#include "initButton.h"
#include "sd_LED1.h"
#include "sd_LED2.h"
#include "sd_LED3.h"
#include "delay.h"
#include "infoLED.h"
#include "Task.h"
#include "yieldLED.h"


void initSysTick(){
	if(SysTick_Config(SystemCoreClock / 1000)){
		/*Capture error*/
		while(1);
	}
}

void taskSwitch(void);

void testFunc(void);

void dummy(void);

int main(){


	initSysTick();
	InitTcb();
	//TaskBlock tb;
	//initTaskBlock(&tb);
	//dummy();
	//testFunc();
	//initLED3();
	//initLED2();
	//initLED1();
	//initPushCLicker();
	while(1){
	//testingSwitchCase(&tb);
	//yieldLED(&tb);
	//SD_LED3();
	//SD_LED2();
	//SD_LED1();

	}
}



