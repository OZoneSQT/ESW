#pragma once
#include <stdint.h>

uint8_t getBit(uint8_t number, uint8_t position);
uint8_t setBit(uint8_t number, uint8_t position);
uint8_t clearBit(uint8_t number, uint8_t position);
uint8_t invertBit(uint8_t number, uint8_t position);

uint8_t maskBits(uint8_t number, uint8_t mask);

uint8_t getBits(uint8_t byteToGetBitsFrom, uint8_t position, uint8_t numberOfBits);

uint8_t setBits(uint8_t byteToSetBitsFrom, uint8_t position, uint8_t numberOfBits);

uint8_t clearBits(uint8_t byteToClearBitsFrom, uint8_t position, uint8_t numberOfBits);

uint8_t invertBits(uint8_t byteToInvertBitsFrom, uint8_t position, uint8_t numberOfBits);

// Also with uint16_t as returntype