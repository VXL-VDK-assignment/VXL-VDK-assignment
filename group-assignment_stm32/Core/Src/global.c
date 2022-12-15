/*
 * global.c
 *
 *  Created on: Oct 26, 2022
 *      Author: tamqu
 */
#include "global.h"

int LANE1_STATUS = LANE1_INIT;
int LANE2_STATUS = LANE2_INIT;
int LANE0_STATUS = LANE0_INIT;

int countDownRed1 = 0;
int countDownYellow1 = 0;
int countDownGreen1 = 0;

int countDownRed2 = 0;
int countDownYellow2 = 0;
int countDownGreen2 = 0;

int buzzerValue = 999; //do not work

int led_duration[3] = {5, 2, 3}; //red, yellow, green

