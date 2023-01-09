#include "mode.h"
#include "main.h"
#include "input_reading.h"
#include "display7seg.h"
#include "timer.h"
#include "fsm_auto.h"
void mode_changing(int mode){
	switch ( mode ){

		case 1:
			traffic_light();
			break ;
        case 2:
        	if(timer1_flag==1){
                HAL_GPIO_TogglePin(GPIOA, R2_Pin|R1_Pin);
        	}
            break;
        case 3:
        	if(timer1_flag==1){
				HAL_GPIO_TogglePin(GPIOA, Y2_Pin|Y1_Pin);
        	}
            break;
        case 4:
        	if(timer1_flag==1){
                HAL_GPIO_TogglePin(GPIOA, G2_Pin|G1_Pin);
        	}
            break;
	}
}



