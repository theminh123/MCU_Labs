#ifndef INC_DISPLAY7SEG_H_
#define INC_DISPLAY7SEG_H_
#include "main.h"
extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];
void display7SEG(int num);
void update7SEG(int index);
void updateClockBuffer(int top, int bot);

#endif /* INC_DISPLAY7SEG_H_ */
