/*
 * fsm_automatic.h
 *
 *  Created on: Oct 26, 2022
 *      Author: tamqu
 */

#ifndef INC_FSM_AUTOMATIC_H_
#define INC_FSM_AUTOMATIC_H_

#include "global.h"

extern int led7SegState;
extern int led7segState2;

int getTimeAtIndex0(int time);
int getTimeAtIndex1(int time);

void fsm_automatic_run1();
void fsm_automatic_run2();

#endif /* INC_FSM_AUTOMATIC_H_ */
