/*
 * PWM1.c
 *
 * Created: 17/04/2024 10:55:13
 *  Author: jaidy
 */ 
#include "PWM1.h"

float map(float x, float in_min, float in_max, float out_min, float out_max){
	return ((x - in_min)*(out_max - out_min)/(in_max - in_min)) + out_min;
}

void initPWM1A(uint8_t inverted, uint16_t prescaler, uint16_t top){
	DDRB |= (1 << DDB1); //PB1 COMO SALIDA
	TCCR1A |= (1 << WGM11);				 //PWM MODO FAST ICR1
	TCCR1B |= (1 << WGM13)|(1 << WGM12); //PWM MODO FAST ICR1
	ICR1 = top;
	
	if (inverted) {
		TCCR1A |= (1 << COM1A1)|(1 << COM1A0);//PWM INVERTIDO
		} else	 {
		TCCR1A |= (1 << COM1A1);//PWM NO INVERTIDO
	}

	if (prescaler == 8) {
		TCCR1B |= (1 << CS11);
		} else {
		TCCR1B |= (1 << CS12);
	}
}

void initPWM1B(uint8_t inverted, uint16_t prescaler, uint16_t top){
	DDRB |= (1 << DDB2); //PB2 COMO SALIDA
	TCCR1A |= (1 << WGM11);				 //PWM MODO FAST ICR1
	TCCR1B |= (1 << WGM13)|(1 << WGM12); //PWM MODO FAST ICR1
	ICR1 = top;
	
	if (inverted) {
		TCCR1A |= (1 << COM1B1)|(1 << COM1B0);//PWM INVERTIDO
		} else	 {
		TCCR1A |= (1 << COM1B1);//PWM NO INVERTIDO
	}

	if (prescaler == 8) {
		TCCR1B |= (1 << CS11);
		} else {
		TCCR1B |= (1 << CS12);
	}
}

void updateDutyCA1(uint16_t duty){//900=0� 2800=90� 4800=180�
	OCR1A = duty;
}

void updateDutyCB1(uint16_t duty){
	OCR1B = duty;
}