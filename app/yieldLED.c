#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "main.h"
#include "initLED.h"
#include "initButton.h"
#include "delay.h"
#include "infoLED.h"
#include "Task.h"
#include "yieldLED.h"

#define initTaskBlock(x) ((x)->state = Initial)
#define yield(x) (x)->state = __LINE__; break; case __LINE__:
#define startTask(x) switch((x)->state) { case Initial:
#define endTask(x)  };

void yieldLED(TaskBlock *tb){
	static uint32_t previousTime = 0;
	if(pressButton() == 0){
		startTask(tb);
		while(1){
				turnOFFLED3();
				if(delay(10,previousTime))
					previousTime = updateTimer();
					turnONLED1(); turnOFFLED2();
					yield(tb);

				if(delay(10,previousTime))
					previousTime = updateTimer();
					turnOFFLED1(); turnONLED2();
					yield(tb);

		}
	    endTask(tb);
	}else{
		startTask(tb);
		while(1){
			if(delay(100,previousTime))
					previousTime = updateTimer();
					turnONLED1(); turnOFFLED2(); turnOFFLED3();
					yield(tb);
			if(delay(100,previousTime))
					previousTime = updateTimer();
					turnOFFLED1(); turnONLED2(); turnOFFLED3();
					yield(tb);
			if(delay(100,previousTime))
					previousTime = updateTimer();
					turnOFFLED1(); turnOFFLED2(); turnONLED3();
		}
		endTask(tb);
	}
}