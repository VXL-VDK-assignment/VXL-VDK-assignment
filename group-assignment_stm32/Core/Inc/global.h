/*
 * global.h
 *
 *  Created on: Oct 26, 2022
 *      Author: tamqu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "led_display.h"
#include "main.h"
#include <stdio.h>

#define LANE1_INIT 1
#define LANE1_RED 2
#define LANE1_GREEN 3
#define LANE1_YELLOW 4

#define LANE2_INIT 11
#define LANE2_RED 12
#define LANE2_GREEN 13
#define LANE2_YELLOW 14

#define LANE0_INIT 21
#define LANE0_RED 22
#define LANE0_GREEN 23
#define LANE0_YELLOW 24
#define STOP 0

extern int LANE1_STATUS;
extern int LANE2_STATUS;
extern int LANE0_STATUS;

extern int countDownRed1;
extern int countDownYellow1;
extern int countDownGreen1;

extern int led_duration[3];
extern int counter;

extern int countDownRed2;
extern int countDownYellow2;
extern int countDownGreen2;



#endif /* INC_GLOBAL_H_ */
