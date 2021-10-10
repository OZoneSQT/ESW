/*
 * Session 5 - Simpel Impl.c
 *
 * Created: 20-10-2020 12:17:09
 * Author : skrue
 */ 

#include <avr/io.h>
#include "driver/dht22.h"
#include "impl.h"
#include "myTimer.h"

dht22 sensor;
int pin = 6;

int main(void) {
	dht22 sensor = dht_init(dht22 *sensor, uint8_t pin);
	
	printf("Init...\n")
	printTemp(getAvgTemp(dht22 *pin));
	printHum(getAvgHum(dht22 *pin));
	
    while (timerFiveMin() != 0) {
		
		printTemp(getAvgTemp(dht22 *pin));
		printHum(getAvgHum(dht22 *pin));
		
    }
}

void printTemp(float value) {
	printf("AVG Temperature: " + value + " C\n");
}

void printHum(float value) {
	printf("AVG Humidity: " + value + " %\n")
}

