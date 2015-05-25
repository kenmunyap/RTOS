#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

typedef enum{
	Initial,
	STATE_A,
	STATE_B,
}State;

uint32_t currentTime = 0;

#define turnONLED1() HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_SET);
#define	turnOFFLED1() HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_RESET);
#define turnONLED2() HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14,GPIO_PIN_SET);
#define	turnOFFLED2() HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14,GPIO_PIN_RESET);
#define turnOFFLED3() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_SET);
#define	turnONLED3() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET);

#define pressButton() HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)
#define yield() state = __LINE__;break; case __LINE__:
void initPushCLicker(){

	GPIO_InitTypeDef GpioInfo;

	__GPIOA_CLK_ENABLE();

	GpioInfo.Mode = GPIO_MODE_INPUT;
	GpioInfo.Pin = GPIO_PIN_0;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;
	GpioInfo.Alternate = GPIO_MODE_AF_PP;

	//Init LED on PG13
	HAL_GPIO_Init(GPIOA, &GpioInfo);
}


void initLED1(){

	GPIO_InitTypeDef GpioInfo;

	__GPIOG_CLK_ENABLE();

	GpioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GpioInfo.Pin = GPIO_PIN_13;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;
	GpioInfo.Alternate = GPIO_MODE_AF_PP;

	//Init LED on PG13
	HAL_GPIO_Init(GPIOG, &GpioInfo);
}

void initLED2(){
	GPIO_InitTypeDef GpioInfo;

	__GPIOG_CLK_ENABLE();

	GpioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GpioInfo.Pin = GPIO_PIN_14;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;
	GpioInfo.Alternate = GPIO_MODE_AF_PP;

	//Init LED on PG14
	HAL_GPIO_Init(GPIOG, &GpioInfo);
}

void initLED3(){
	GPIO_InitTypeDef GpioInfo;

	__GPIOC_CLK_ENABLE();

	GpioInfo.Mode = GPIO_MODE_OUTPUT_PP;
	GpioInfo.Pin = GPIO_PIN_5;
	GpioInfo.Pull = GPIO_NOPULL;
	GpioInfo.Speed = GPIO_SPEED_HIGH;
	GpioInfo.Alternate = GPIO_MODE_AF_PP;

	//Init LED on PG14
	HAL_GPIO_Init(GPIOC, &GpioInfo);
}

uint32_t getCurrentTime(){
	static uint32_t counter = 0;
	static uint32_t currentTime = 0;
	if(counter++ >= 1000){
		counter = 0;
		currentTime ++;
	}
	return currentTime;
}

int delay(uint32_t delayCycle,uint32_t previousTime){

		if(((currentTime = getCurrentTime()) - previousTime) < delayCycle){
			return 0;
		}else{
			return 1;
		}
}


void SD_LED1(){
	static uint32_t previousTime = 0;
	static State state = Initial;
	switch(state){
		case Initial:
			if(delay(120,previousTime)){
			turnOFFLED1();
			state = STATE_A;
			previousTime = currentTime;
			}
			break;
		case STATE_A:
			if(delay(120,previousTime)){
			turnONLED1();
			state = STATE_B;
			previousTime = currentTime;
			}
			break;
		case STATE_B:
			if(delay(120,previousTime)){
			turnOFFLED1();
			state = STATE_A;
			previousTime = currentTime;
			}
			break;
	}
}

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
				previousTime = currentTime;
			}
			break;
		case STATE_A:
			if(delay(blink,previousTime)){
				turnONLED2();
				state = STATE_B;
				previousTime = currentTime;
			}
			break;
		case STATE_B:
			if(delay(blink,previousTime)){
				turnOFFLED2();
				state = STATE_A;
				previousTime = currentTime;
			}
			break;
	}
}

void SD_LED3(){

		static uint32_t previousTime = 0;
		static State state = Initial;
		static uint32_t counter = 0;
		switch(state){
			case Initial:
				turnOFFLED3();
					if(pressButton() == 1){
						counter = 0;
						state = STATE_A;
					}else{
						state = Initial;
					}
				break;
			case STATE_A:
				if(counter == 5){
					state = Initial;
				}else{
					if(delay(20,previousTime)){
						turnONLED3();
						state = STATE_B;
						previousTime = currentTime;
					}
				}
				break;
			case STATE_B:
					if(delay(20,previousTime)){
						turnOFFLED3();
						state = STATE_A;
						counter = counter + 1;
						previousTime = currentTime;
					}
				break;
		}

}




int main(){
	initLED1();
	initLED2();
	initLED3();
	initPushCLicker();
	while(1){
		SD_LED1();
		SD_LED2();
		SD_LED3();
	}
}

