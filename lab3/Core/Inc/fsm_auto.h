#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_
#include "main.h"
#include "display7seg.h"
#include "input_processing.h"

void traffic_light(void);
extern int led_time[3];
extern int led_value_buffer[3];
extern int traffic_time;
extern int traffic1_led;
extern int traffic2_led;

#endif /* INC_FSM_AUTO_H_ */
