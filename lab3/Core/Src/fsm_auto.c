#include "fsm_auto.h"
#include "main.h"
#include "timer.h"
#include "mode.h"
int led_time[3] = {5,2,3};
int led_value_buffer[3] = {5,2,3};
int traffic_time = 10;
int traffic1_led = 0;
int traffic2_led = 0;
void traffic_light(void){
		if(timer3_flag==1){
			traffic1_led --;
			traffic2_led --;
			setTimer3(100);
		}
		if(timer2_counter==(traffic_time - led_time[2])*100){
			HAL_GPIO_WritePin(GPIOA, G1_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, Y1_Pin,GPIO_PIN_RESET);
			traffic1_led = led_time[1];
		}
		if(timer2_counter==(traffic_time - led_time[2] - led_time[1])*100){
			HAL_GPIO_WritePin(GPIOA, R2_Pin|Y1_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, R1_Pin|G2_Pin,GPIO_PIN_RESET);
			traffic1_led = led_time[0];
			traffic2_led = led_time[2];
		}
		if(timer2_counter==(traffic_time - led_time[2]-led_time[0])*100){
			HAL_GPIO_WritePin(GPIOA, G2_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, Y2_Pin,GPIO_PIN_RESET);
			traffic2_led = led_time[1];
		}
		if(timer2_flag==1){
			HAL_GPIO_WritePin(GPIOA, R1_Pin|Y2_Pin,GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, R2_Pin|G1_Pin,GPIO_PIN_RESET);
			traffic1_led = led_time[2];
			traffic2_led = led_time[0];
			setTimer2(traffic_time*100);
		}
		updateClockBuffer(traffic1_led, traffic2_led);
}



