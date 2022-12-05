/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2022
 *      Author: tamqu
 */
#include "fsm_automatic.h"
#include "global.h"


int getTimeAtIndex0(int time) {
	int temp = time/10;
	return temp;
}
int getTimeAtIndex1(int time) {
	return time%10;
}

//int led7SegState = 1;
//int led7SegState2 = 1;

void fsm_automatic_run1() {
	switch(LANE1_STATUS) { //for lane 1
		case LANE1_INIT:
			initTrafficLight1();
			LANE1_STATUS = LANE1_RED;
			setTimer1(led_duration[0]*1000);
//			timer4_flag = 1;
//			led7SegState = 1;
			break;
		case LANE1_RED:
			setTrafficRed1();

//			if (timer4_flag == 1) {
//				switch(led7SegState) {
//				case 1:
//					enableLed7Seg1();
//					display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed1)]);
//					setTimer4(250);
//					led7SegState = 2;
//					break;
//				case 2:
//					enableLed7Seg2();
//					display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed1)]);
//					setTimer4(250);
//					led7SegState = 3;
//					break;
//				case 3:
//					enableLed7Seg3();
//					setTimer4(250);
//					led7SegState = 4;
//					break;
//				case 4:
//					enableLed7Seg4();
//					countDownRed1++;
//					setTimer4(250);
//					led7SegState = 1;
//					break;
//				}
//				default:
//					break;
//			}
			if(timer1_flag == 1) {
				setTimer1(led_duration[2]*1000);
				LANE1_STATUS = LANE1_GREEN;
//				countDownRed1 = 0; //reset
//				timer4_flag = 1;
//				led7SegState = 1;
			}
			break;
		case LANE1_GREEN:
			setTrafficGreen1();

			if(timer1_flag == 1) {
				setTimer1(led_duration[1]*1000);
				LANE1_STATUS = LANE1_YELLOW;
//				countDownGreen1 = 0; //reset
			}
			break;
		case LANE1_YELLOW:
			setTrafficYellow1();

			if(timer1_flag == 1) {
				setTimer1(led_duration[0]*1000);
				LANE1_STATUS = LANE1_RED;
//				countDownYellow1 = 0; //reset
			}
			break;
	}
}

void fsm_automatic_run2() {
	switch(LANE2_STATUS) { //for lane 2
		case LANE2_INIT:
			initTrafficLight2();
			LANE2_STATUS = LANE2_GREEN;
			setTimer2(led_duration[2]*1000);
//			timer3_flag = 1; //
//			led7SegState2 = 1;
			break;
		case LANE2_RED:
			setTrafficRed2();
//			if (timer3_flag == 1) {
//				switch(led7SegState2) {
//				case 1:
//					enableLed7Seg1();
//					setTimer3(250);
//					led7SegState2 = 2;
//					break;
//				case 2:
//					enableLed7Seg2();
//					setTimer3(250);
//					led7SegState2 = 3;
//					break;
//				case 3:
//					display7SEG_1(segmentNumber[getTimeAtIndex0(led_duration[0]-countDownRed2)]);
//					enableLed7Seg3();
//					setTimer3(250);
//					led7SegState2 = 4;
//					break;
//				case 4:
//					display7SEG_1(segmentNumber[getTimeAtIndex1(led_duration[0]-countDownRed2)]);
//					enableLed7Seg4();
//					countDownRed2++;
//					setTimer3(250);
//					led7SegState2 = 1;
//					break;
//				}
//			}
			if(timer2_flag == 1) {
				setTimer2(led_duration[2]*1000);
				LANE2_STATUS = LANE2_GREEN;
//				countDownRed2 = 0; //reset
			}
			break;
		case LANE2_GREEN:
			setTrafficGreen2();

			if(timer2_flag == 1) {
				setTimer2(led_duration[1]*1000);
				LANE2_STATUS = LANE2_YELLOW;
//				countDownGreen2 = 0; //reset
			}
			break;
		case LANE2_YELLOW:
			setTrafficYellow2();

			if(timer2_flag == 1) {
				setTimer2(led_duration[0]*1000);
				LANE2_STATUS = LANE2_RED;
//				countDownYellow2 = 0; //reset
			}
			break;
	}
}


