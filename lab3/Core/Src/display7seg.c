#include "main.h"
void display7SEG(int num){
	  switch(num){
	  case 0:
		  HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_RESET);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, a_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
	      break;
	  case 2:
		  HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_RESET);
	      break;
	  case 3:
		  HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
	      break;
	  case 4:
		  HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, a_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
	      break;
	  case 5:
		  HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, b_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
	      break;
	  case 6:
		  HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, b_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
	      break;
	  case 7:
		  HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, 1);
	      break;
	  case 8:
		  HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
	      break;
	  case 9:
		  HAL_GPIO_WritePin(GPIOB, a_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, b_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, c_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, d_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, e_Pin, 1);
		  HAL_GPIO_WritePin(GPIOB, f_Pin, GPIO_PIN_RESET);
		  HAL_GPIO_WritePin(GPIOB, g_Pin, GPIO_PIN_RESET);
	      break;
	  }
}
/* USER CODE END 0 */
const int MAX_LED = 4;
int index_led = 0;
int led_buffer [4] = {0,0,0,0};
void update7SEG ( int index ){
 switch ( index ){
 case 0:
 // Display the first 7 SEG with led_buffer [0]
	 display7SEG(led_buffer[0]);
	 HAL_GPIO_WritePin(GPIOA, EN0_Pin,0);
	 HAL_GPIO_WritePin(GPIOA, EN1_Pin|EN2_Pin|EN3_Pin,1);
 break ;
 case 1:
 // Display the second 7 SEG with led_buffer [1]
	 HAL_GPIO_WritePin(GPIOA, EN1_Pin,0);
	 HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin|EN3_Pin,1);
	 display7SEG(led_buffer[1]);
 break ;
 case 2:
 // Display the third 7 SEG with led_buffer [2]
	 HAL_GPIO_WritePin(GPIOA, EN2_Pin,0);
	 HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN1_Pin|EN3_Pin,1);
	 display7SEG(led_buffer[2]);
 break ;
 case 3:
 // Display the forth 7 SEG with led_buffer [3]
	 HAL_GPIO_WritePin(GPIOA, EN3_Pin,0);
	 HAL_GPIO_WritePin(GPIOA, EN0_Pin|EN2_Pin|EN1_Pin,1);
	 display7SEG(led_buffer[3]);
 break ;
 default :
 break ;
 }
}
void updateClockBuffer(int top, int bot){
	led_buffer[0] = top/10;
	led_buffer[1] = top%10;
	led_buffer[2] = bot/10;
	led_buffer[3] = bot%10;
}


