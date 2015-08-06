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

typedef struct{
	uint32_t state;
}TaskBlock;


#define initTaskBlock(x) ((x)->state = Initial)
#define yield(x) (x)->state = __LINE__;} break; case __LINE__:
#define startTask(x) switch((x)->state) { case Initial:
#define endTask(x)  };


void yieldLED(TaskBlock *tb){
	static uint32_t previousTime = 0;
	if(pressButton() == 0){
		startTask(tb);
		while(1){
				turnOFFLED3();
				if(delay(10,previousTime)){
					previousTime = updateTimer();
					turnONLED1(); turnOFFLED2();
					yield(tb);

				if(delay(10,previousTime)){
					previousTime = updateTimer();
					turnOFFLED1(); turnONLED2();
					yield(tb);

		}
	    endTask(tb);
	}else{
		startTask(tb);
		while(1){
			if(delay(100,previousTime)){
					previousTime = updateTimer();
					turnONLED1(); turnOFFLED2(); turnOFFLED3();
					yield(tb);
			if(delay(100,previousTime)){
					previousTime = updateTimer();
					turnOFFLED1(); turnONLED2(); turnOFFLED3();
					yield(tb);
			if(delay(100,previousTime)){
					previousTime = updateTimer();
					turnOFFLED1(); turnOFFLED2(); turnONLED3();
		}
		endTask(tb);
	}
}

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



