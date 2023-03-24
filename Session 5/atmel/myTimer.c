/*
 * myTimer.c
 *
 * Created: 20-10-2020 13:23:07
 *  Author: skrue
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h> 
#include "driver/dht22.h"

bool _timerOne = 1;
bool _timerFive = 1;

bool timerOneMin() {
	if(timerOneMin() == NULL) {
		timerOneMin();
	}
	return _timerOne;
}

bool timerFiveLoop() {
	if(timerFiveMin() == NULL) {
		timerFiveMin();
	}
	return _timerFive;
}

void timerOneMin() {
	_timerOne = 0;
	_delay_ms(10000);
	_timerOne = 1;
	timerOneMin();
}

void timerFiveLoop() {
	_timerFive = 0;
	_delay_ms(50000);
	_timerFive = 1;
	timerFiveMin();
}

