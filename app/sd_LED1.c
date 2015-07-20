#include "sd_LED1.h"
#include "infoLED.h"
#include "initButton.h"
#include "delay.h"

void SD_LED1(){
	static uint32_t previousTime = 0;
	static State state = Initial;
	switch(state){
		case Initial:
			if(delay(120,previousTime)){
			turnOFFLED1();
			state = STATE_A;
			previousTime = getCurrentTime();
			}
			break;
		case STATE_A:
			if(delay(120,previousTime)){
			turnONLED1();
			state = STATE_B;
			previousTime = getCurrentTime();
			}
			break;
		case STATE_B:
			if(delay(120,previousTime)){
			turnOFFLED1();
			state = STATE_A;
			previousTime = getCurrentTime();
			}
			break;
	}
}
