#include "delay.h"
#include "stm32f4xx_hal.h"

uint32_t currentTime = 0;

int updateTimer(){
	static int counter = 0;

	if(counter++ >= 1000){
		counter = 0;
		currentTime ++;
	}

	return currentTime;
}

int getCurrentTime(){
	return HAL_GetTick();
}


int delay(int delayCycle,int previousTime){
		if(((currentTime = getCurrentTime()) - previousTime) < delayCycle){
			return 0;
		}else{
			return 1;
		}
}
