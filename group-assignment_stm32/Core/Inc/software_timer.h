/*
 * software_timer.h
 *
 *  Created on: Oct 31, 2022
 *      Author: tamqu
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;
extern int timer4_flag;
extern int timer5_flag;
extern int timer6_flag;
extern int timer7_flag;
extern int timer10_flag; //for buzzer

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void setTimer6(int duration);
void setTimer7(int duration);
void setTimer10(int duration); //for buzzer

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */
