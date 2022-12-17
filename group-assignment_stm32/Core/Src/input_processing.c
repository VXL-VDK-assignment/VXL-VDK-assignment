/*
 * input_processing.c
 *
 *  Created on: Oct 31, 2022
 *      Author: tamqu
 */
#include "input_processing.h"
#include "fsm_automatic.h"
#include "global.h"

enum ButtonState { NORMAL, SET_TIME_RED, SET_TIME_YELLOW, SET_TIME_GREEN };
enum ButtonState buttonState = NORMAL;

int counterForRed = 0;
int counterForGreen = 0;
int counterForYellow = 0;

int loopFlag = 0;
void fsm_for_input_processing(void){
	switch(buttonState){
		case NORMAL: //Mode 1

			countDownGreen1 = 0;
			countDownGreen2 = 0;
			countDownRed1 = 0;
			countDownRed2 = 0;
			countDownYellow1 = 0;
			countDownYellow2 = 0;
			setTimer6(1000);

			LANE1_STATUS = LANE1_INIT;
			LANE2_STATUS = LANE2_INIT;
			LANE0_STATUS = LANE0_INIT;

			while(1) {
				if(timer5_flag == 1){
					checkflag = 0; //reset checkflag
					timer5_flag = 0; //reset timer5_flag
					initTrafficLight0(); //turn off all lights
				}

				fsm_automatic_run1();
				fsm_automatic_run2();
				fsm_automatic_run0();

				if(isButtonPressed(3) == 1) {
					checkflag = 1;
					setTimer5((led_duration[0] + led_duration[1] + led_duration[2])*1000*2); //two cycles
				}
				if(isButtonPressed(0) == 1) {
					buttonState = SET_TIME_RED;
					setTrafficRed1();
					setTrafficRed2();
					loopFlag = 0; //reset
					timer1_flag = 1; //for toggle LEDs in mode 2, 3, 4
					break;
				}
			}
			break;
		case SET_TIME_RED: //Mode 2
			while (loopFlag == 0) {
				if (timer1_flag == 1) { //toggle RED LEDs every 0.5s
					setTimer1(500);
					HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
					HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
				}

				if (isButtonPressed(1) == 1) counterForRed++;

				if(isButtonPressed(2) == 1) {
					led_duration[0] += counterForRed;
					if (led_duration[0] > 99) led_duration[0] = 1;
					counterForRed = 0; //reset
				}

				if(isButtonPressed(0) == 1) {
					buttonState = SET_TIME_YELLOW;
					setTrafficYellow1();
					setTrafficYellow2();
					loopFlag = 1;
					timer1_flag = 1; //for toggle LEDs in mode 2, 3, 4
					counterForRed = 0; //rest
				}
			}
			break;
		case SET_TIME_YELLOW: //Mode 3
			loopFlag = 0;
			while (loopFlag == 0) {
				if (timer1_flag == 1) { //toggle YELLOW LEDs every 0.5s
					setTimer1(500);
					HAL_GPIO_TogglePin(D2_GPIO_Port, D2_Pin);
					HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
					HAL_GPIO_TogglePin(D4_GPIO_Port, D4_Pin);
					HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
				}

				if (isButtonPressed(1) == 1) counterForYellow++;

				if(isButtonPressed(2) == 1) {
					led_duration[1] += counterForYellow;
					if (led_duration[1] > 99) led_duration[1] = 1;
					counterForYellow = 0; //reset
				}

				if(isButtonPressed(0) == 1) {
					buttonState = SET_TIME_GREEN;
					setTrafficGreen1();
					setTrafficGreen2();
					loopFlag = 1;
					timer1_flag = 1; //for toggle LEDs in mode 2, 3, 4
					counterForYellow = 0; //reset
				}
			}
			break;
		case SET_TIME_GREEN: //Mode 4
			loopFlag = 0;
			while (loopFlag == 0) {
				if (timer1_flag == 1) { //toggle GREEN LEDs every 0.5s
					setTimer1(500);
					HAL_GPIO_TogglePin(D3_GPIO_Port, D3_Pin);
					HAL_GPIO_TogglePin(D5_GPIO_Port, D5_Pin);
				}

				if (isButtonPressed(1) == 1) counterForGreen++;

				if(isButtonPressed(2) == 1) {
					led_duration[2] += counterForGreen;
					if (led_duration[2] > 99) led_duration[2] = 1;
					counterForGreen = 0; //reset
				}

				if(isButtonPressed(0) == 1) {
					buttonState = NORMAL;
					loopFlag = 1;
					counterForGreen = 0; //reset
				}
			}
			break;
	}
}



