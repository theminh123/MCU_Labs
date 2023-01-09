#include "mode.h"
#include "input_processing.h"
#include "display7seg.h"
#include "timer.h"
enum ButtonState { BUTTON_RELEASED , BUTTON1_PRESSED , BUTTON2_PRESSED , BUTTON3_PRESSED} ;
enum ButtonState buttonState = BUTTON_RELEASED;
int mode =  1;
void fsm_for_input_processing ( void ){
	switch ( buttonState ){
		 case BUTTON_RELEASED :
			 if(is_button_pressed(0)) {
				 buttonState = BUTTON1_PRESSED ;
				 mode++;

				 HAL_GPIO_WritePin(GPIOA, R2_Pin|R1_Pin|Y2_Pin|Y1_Pin|G2_Pin|G1_Pin, GPIO_PIN_SET);
	        	 if(led_time[0]==0||led_time[1]==0||led_time[2]==0){
	        		 led_value_buffer[0]=led_value_buffer[1]=led_value_buffer[2]=0;
	        	 }
			 }
			 if(mode > 1 && mode <= 4){
				 if( is_button_pressed (1) ) {
					 led_value_buffer[mode-2]++;
					 buttonState = BUTTON2_PRESSED ;

				 }
				 if( is_button_pressed (2) ) {
					 led_time[mode-2] = led_value_buffer[mode-2];
					 traffic_time = led_time[0] + led_time[1] + led_time[2];
					 buttonState = BUTTON3_PRESSED ;

				 }
			 }
			 break ;
		 case BUTTON1_PRESSED :
			 if (! is_button_pressed (0)) {
				 buttonState = BUTTON_RELEASED ;
			 }

			 if(mode > 4){
			 	mode = 1;

			 }
			 updateClockBuffer(led_value_buffer[mode-2],mode);
			 break ;
		 case BUTTON2_PRESSED:
			 if (! is_button_pressed (1) ) {
				 buttonState = BUTTON_RELEASED ;
			 }
			 if(led_value_buffer[mode-2] > 99){
				 led_value_buffer[mode-2]=1;
			 }
			 updateClockBuffer(led_value_buffer[mode-2], mode);
			 break;
		 case BUTTON3_PRESSED:
			 if (! is_button_pressed (2) ) {
				 buttonState = BUTTON_RELEASED ;
			 }
			 break;
		}
}
