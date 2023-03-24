/*
 * impl.c
 *
 * Created: 20-10-2020 13:20:32
 *  Author: skrue
 */ 

#include "driver/dht22.h"
#include "impl.h"
#include "tempHumSensor.h"
#include "myTimer.h"

int _count = 0;
float _tempSum = 0;
float _humSum = 0;

float getAvgTemp(dht22 *dht) {
	if(timeLoop(dht22 *dht) == NULL) {
		timeLoop(dht22 *dht);
	} 
	float result = _tempSum / _count; 
	return result;
}

float getAvgHum(dht22 *dht) {
	if(timeLoop(dht22 *dht) == NULL) {
		timeLoop(dht22 *dht);
	} 
		float result = _humSum / _count;
		return result;
}


void timeLoop(dht22 *dht) {
	for(int i = 0; i < 5; i++) {
		while(timerOneMin() != 0) {
			_tempSum += getTemp(dht22 *dht);
			_humSum += getHum(dht22 *dht);
			if(i == 4) {
				resetStats();
				i = 0;
			}
		}		
	}
}


void resetStats() {
	_count = 0;
	_tempSum = 0;
	_humSum = 0;
}

