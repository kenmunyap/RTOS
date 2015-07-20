#include "sd_LED3.h"
#include "infoLED.h"
#include "initButton.h"
#include "delay.h"

void SD_LED3(){
	static uint32_t previousTime = 0;
	static State state = Initial;
	static int rememberPress = 0;
	static int counter = 0;

	switch(state){
		case Initial:
			turnOFFLED3();
			if(rememberPress == 0){
				if(pressButton() == 1){
					rememberPress = 1;
					counter = 0;
					state = STATE_A;
				}
			}else{
					if(pressButton() == 0){
						rememberPress = 0;
						state = Initial;
					}
			}
			break;
		case STATE_A:
			if(counter == 5){
				state = Initial;
			}else{
				if(delay(50,previousTime)){
					turnONLED3();
					state = STATE_B;
					previousTime = updateTimer();
				}
			}
			break;
		case STATE_B:
			if(delay(50,previousTime)){
				turnOFFLED3();
				state = STATE_A;
				counter = counter + 1;
				previousTime = updateTimer();
			}
			break;
	}
}
