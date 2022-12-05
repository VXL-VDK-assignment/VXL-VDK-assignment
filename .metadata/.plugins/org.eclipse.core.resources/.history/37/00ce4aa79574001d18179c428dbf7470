/*
 * input_reading.c
 *
 *  Created on: Oct 29, 2022
 *      Author: tamqu
 */
#include "input_reading.h"
#include "main.h"


int TimeOutForKeyPress =  500; //if the button is pressed more than 5s it will change state and repeatedly do so every single 5s of pressing
int TimeOutForKeyPress2 =  500; //if the button is pressed more than 5s it will change state and repeatedly do so every single 5s of pressing
int TimeOutForKeyPress3 =  500; //if the button is pressed more than 5s it will change state and repeatedly do so every single 5s of pressing
int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isButton1Press() {
	if (button1_flag == 1) {
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Press() {
	if (button2_flag == 1) {
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Press() {
	if (button3_flag == 1) {
		button3_flag = 0;
		return 1;
	}
	return 0;
}
int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;
void getKeyInput(){
  KeyReg2 = KeyReg1;
  KeyReg1 = KeyReg0;
  KeyReg0 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
    if (KeyReg2 != KeyReg3){
      KeyReg3 = KeyReg2;
      if (KeyReg3 == PRESSED_STATE){
        TimeOutForKeyPress = 500;
        button1_flag = 1;
      }
    } else{
    	TimeOutForKeyPress--;
		if (TimeOutForKeyPress == 0){
			if (KeyReg3 == PRESSED_STATE){
				TimeOutForKeyPress = 500;
				button1_flag = 1;
			 }
		}
    }
  }
}

int KeyReg02 = NORMAL_STATE;
int KeyReg12 = NORMAL_STATE;
int KeyReg22 = NORMAL_STATE;
int KeyReg32 = NORMAL_STATE;
void getKeyInput2(){
  KeyReg22 = KeyReg12;
  KeyReg12 = KeyReg02;
  KeyReg02 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);
  if ((KeyReg12 == KeyReg02) && (KeyReg12 == KeyReg22)){
    if (KeyReg22 != KeyReg32){
      KeyReg32 = KeyReg22;
      if (KeyReg32 == PRESSED_STATE){
        TimeOutForKeyPress2 = 500;
        button2_flag = 1;
      }
    } else{
    	TimeOutForKeyPress2--;

		if (TimeOutForKeyPress2 == 0){
			if (KeyReg32 == PRESSED_STATE){
				TimeOutForKeyPress2 = 500;
				button2_flag = 1;
			 }
		}
    }
  }
}

int KeyReg03 = NORMAL_STATE;
int KeyReg13 = NORMAL_STATE;
int KeyReg23 = NORMAL_STATE;
int KeyReg33 = NORMAL_STATE;
void getKeyInput3(){
  KeyReg23 = KeyReg13;
  KeyReg13 = KeyReg03;
  KeyReg03 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);
  if ((KeyReg13 == KeyReg03) && (KeyReg13 == KeyReg23)){
    if (KeyReg23 != KeyReg33){
      KeyReg33 = KeyReg23;
      if (KeyReg33 == PRESSED_STATE){
        TimeOutForKeyPress3 = 500;
        button3_flag = 1;
      }
    } else{
    	TimeOutForKeyPress3--;

		if (TimeOutForKeyPress3 == 0){
			if (KeyReg33 == PRESSED_STATE){
				TimeOutForKeyPress3 = 500;
				button3_flag = 1;
			 }
		}
    }
  }
}

