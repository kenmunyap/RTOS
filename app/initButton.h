#ifndef __INITBUTTON_H
#define __INITBUTTON_H

#define pressButton() HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0)

void initPushCLicker();

#endif //__INITBUTTON_H
