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

int led7SegState = 1; //used for printing a particular case in virtual terminal
int led7SegState2 = 1;//used for printing a particular case in virtual terminal
int checkflag = 0;
void fsm_automatic_run1() {
	char buffer[10];
	switch(LANE1_STATUS) { //for lane 1
		case LANE1_INIT:
			initTrafficLight1();
			LANE1_STATUS = LANE1_RED;
			setTimer1(led_duration[0]*1000);

			timer4_flag = 1;
			led7SegState = 1;
			break;
		case LANE1_RED:
			setTrafficRed1();

			if (timer4_flag == 1) {
				switch(led7SegState) {
				case 1:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex0(led_duration[0]-countDownRed1));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					setTimer4(250);
					led7SegState = 2;
					break;
				case 2:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex1(led_duration[0]-countDownRed1));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					setTimer4(250);
					led7SegState = 3;
					break;
				case 3:
					setTimer4(250);
					led7SegState = 4;
					break;
				case 4:
					countDownRed1++;
					setTimer4(250);
					led7SegState = 1;
					break;
				}
				default:
					break;
			}

			if(timer1_flag == 1) {
				setTimer1(led_duration[2]*1000);
				LANE1_STATUS = LANE1_GREEN;

				countDownRed1 = 0; //reset
				timer4_flag = 1;
				led7SegState = 1;

			}
			break;
		case LANE1_GREEN:
			setTrafficGreen1();

			if (timer4_flag == 1) {
				switch(led7SegState) {
				case 1:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex0(led_duration[2]-countDownGreen1));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					setTimer4(250);
					led7SegState = 2;
					break;
				case 2:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex1(led_duration[2]-countDownGreen1));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					setTimer4(250);
					led7SegState = 3;
					break;
				case 3:
					setTimer4(250);
					led7SegState = 4;
					break;
				case 4:
					countDownGreen1++;
					setTimer4(250);
					led7SegState = 1;
					break;
				}
			}

			if(timer1_flag == 1) {
				setTimer1(led_duration[1]*1000);
				LANE1_STATUS = LANE1_YELLOW;

				countDownGreen1 = 0; //reset
				timer4_flag = 1;
				led7SegState = 1;//

			}
			break;
		case LANE1_YELLOW:
			setTrafficYellow1();

			if (timer4_flag == 1) {
				switch(led7SegState) {
				case 1:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex0(led_duration[1]-countDownYellow1));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					setTimer4(250);
					led7SegState = 2;
					break;
				case 2:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex1(led_duration[1]-countDownYellow1));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					setTimer4(250);
					led7SegState = 3;
					break;
				case 3:
					setTimer4(250);
					led7SegState = 4;
					break;
				case 4:
					countDownYellow1++;
					setTimer4(250);
					led7SegState = 1;
					break;
				}
			}

			if(timer1_flag == 1) {
				setTimer1(led_duration[0]*1000);
				LANE1_STATUS = LANE1_RED;

				countDownYellow1 = 0; //reset
				timer4_flag = 1;
				led7SegState = 1;//

			}
			break;
	}
}

void fsm_automatic_run2() {
	char buffer[10];
	switch(LANE2_STATUS) { //for lane 2
		case LANE2_INIT:
			initTrafficLight2();
			LANE2_STATUS = LANE2_GREEN;
			setTimer2(led_duration[2]*1000);

			timer3_flag = 1; //
			led7SegState2 = 1;
			break;
		case LANE2_RED:
			setTrafficRed2();

			if (timer3_flag == 1) {
				switch(led7SegState2) {
				case 1:
					setTimer3(250);
					led7SegState2 = 2;
					break;
				case 2:
					setTimer3(250);
					led7SegState2 = 3;
					break;
				case 3:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex0(led_duration[0]-countDownRed2));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					setTimer3(250);
					led7SegState2 = 4;
					break;
				case 4:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex1(led_duration[0]-countDownRed2));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					countDownRed2++;
					setTimer3(250);
					led7SegState2 = 1;
					break;
				}
			}

			if(timer2_flag == 1) {
				setTimer2(led_duration[2]*1000);
				LANE2_STATUS = LANE2_GREEN;

				countDownRed2 = 0; //reset
				led7SegState2 = 1; //
				timer3_flag = 1;
			}
			break;
		case LANE2_GREEN:
			setTrafficGreen2();

			if (timer3_flag == 1) {
				switch(led7SegState2) {
				case 1:
					setTimer3(250);
					led7SegState2 = 2;
					break;
				case 2:
					setTimer3(250);
					led7SegState2 = 3;
					break;
				case 3:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex0(led_duration[2]-countDownGreen2));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					setTimer3(250);
					led7SegState2 = 4;
					break;
				case 4:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex1(led_duration[2]-countDownGreen2));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					countDownGreen2++;
					setTimer3(250);
					led7SegState2 = 1;
					break;
				}
			}

			if(timer2_flag == 1) {
				setTimer2(led_duration[1]*1000);
				LANE2_STATUS = LANE2_YELLOW;

				countDownGreen2 = 0; //reset
				led7SegState2 = 1;//
				timer3_flag = 1;
			}
			break;
		case LANE2_YELLOW:
			setTrafficYellow2();

			if (timer3_flag == 1) {
				switch(led7SegState2) {
				case 1:
					setTimer3(250);
					led7SegState2 = 2;
					break;
				case 2:
					setTimer3(250);
					led7SegState2 = 3;
					break;
				case 3:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex0(led_duration[1]-countDownYellow2));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					setTimer3(250);
					led7SegState2 = 4;
					break;
				case 4:
					sprintf((char*)buffer, "!7SEG:%d#\r\n", getTimeAtIndex1(led_duration[1]-countDownYellow2));
					HAL_UART_Transmit(&huart2, &buffer[0], 10, 1000);
					countDownYellow2++;
					setTimer3(250);
					led7SegState2 = 1;
					break;
				}
			}

			if(timer2_flag == 1) {
				setTimer2(led_duration[0]*1000);
				LANE2_STATUS = LANE2_RED;

				countDownYellow2 = 0; //reset
				led7SegState2 = 1;//
				timer3_flag = 1;
			}
			break;
	}

}

//fsm for pedestrian
void fsm_automatic_run0() {
	switch(LANE0_STATUS) {
		case LANE0_INIT:
			initTrafficLight0();
			LANE0_STATUS = LANE0_GREEN;
			setTimer7(led_duration[2]*1000);

			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, buzzerValue); //at this time, buzzerValue = 999; do not work
			timer10_flag = 1; //used for buzzer; make it louder in case green light
			break;
		case LANE0_RED:
			if (checkflag == 1) {
				setTrafficRed0();
			}

			if(timer7_flag == 1) {
				setTimer7(led_duration[2]*1000);
				LANE0_STATUS = LANE0_GREEN;
			}
			break;
		case LANE0_GREEN: //only this case the pedestrian can cross the street
			if (checkflag == 1) {
				setTrafficGreen0();
				//Now make the buzzer louder in every 0.5s
				if (timer10_flag == 1) {
					setTimer10(500);
					buzzerValue = buzzerValue - 999/(led_duration[2]/0.5); //decrease to value 0, so that the buzzer become more louder
					__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, buzzerValue);
				}
			}

			if(timer7_flag == 1) {
				setTimer7(led_duration[1]*1000);
				LANE0_STATUS = LANE0_YELLOW;
			}
			break;
		case LANE0_YELLOW:
			buzzerValue = 999; //reset to make it stop working
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, buzzerValue); //at this time, buzzerValue = 999; do not work

			if (checkflag == 1) {
				setTrafficRed0(); //red light as well. lights for pedestrian do not have yellow light
			}

			if(timer7_flag == 1) {
				setTimer7(led_duration[0]*1000);
				LANE0_STATUS = LANE0_RED;
			}
			break;
	}
}

