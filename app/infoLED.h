#ifndef __INFOLED_H
#define __INFOLED_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

#define turnONLED1() HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_SET);
#define	turnOFFLED1() HAL_GPIO_WritePin(GPIOG,GPIO_PIN_13,GPIO_PIN_RESET);
#define turnONLED2() HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14,GPIO_PIN_SET);
#define	turnOFFLED2() HAL_GPIO_WritePin(GPIOG,GPIO_PIN_14,GPIO_PIN_RESET);
#define turnOFFLED3() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_SET);
#define	turnONLED3() HAL_GPIO_WritePin(GPIOC,GPIO_PIN_5,GPIO_PIN_RESET);
#define turnOFFLED4() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_SET);
#define	turnONLED4() HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,GPIO_PIN_RESET);

typedef enum{
	Initial,
	STATE_A,
	STATE_B,
}State;


#endif //__INFOLED_H


