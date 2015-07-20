#include "sd_LED2.h"
#include "infoLED.h"
#include "initButton.h"
#include "delay.h"

void SD_LED2(){
	int blink;
	static uint32_t previousTime = 0;
	static State state = Initial;
	if(pressButton() == 1){
		blink = 5;
	}else{
		blink = 20;
	}
	switch(state){
		case Initial:
			if(delay(blink,previousTime)){
				turnOFFLED2();
				state = STATE_A;
				previousTime = updateTimer();
			}
			break;
		case STATE_A:
			if(delay(blink,previousTime)){
				turnONLED2();
				state = STATE_B;
				previousTime = updateTimer();
			}
			break;
		case STATE_B:
			if(delay(blink,previousTime)){
				turnOFFLED2();
				state = STATE_A;
				previousTime = updateTimer();
			}
			break;
	}
}
