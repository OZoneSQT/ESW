#include "driver/dht22.h"
#include "tempHumSensor.h"

/*
 * tempHumSensor.c
 *
 * Created: 20-10-2020 14:13:39
 *  Author: skrue
 */ 

float getTemp(dht22 *dht) {
	float temp = dht_read_temp(dht22 *dht, *temp);
	return temp;
}

float getHum(dht22 *dht) {
	float hum = dht_read_hum(dht22 *dht, *hum);
	return hum;
}

