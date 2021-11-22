#pragma once

#include <stdint.h>

typedef struct Humidity {
    uint8_t latestHumidity;
    uint8_t _driverPort;
}Humidity;

typedef struct Humidity* humidity_t;

humidity_t humidity_create(uint8_t portNo);
void humidity_destroy(humidity_t self);
void humidity_meassure(humidity_t self);
float humidity_getHumidity(humidity_t self);