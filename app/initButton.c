#include "initButton.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

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
