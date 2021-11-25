#include "bit-manipulation.h"

//K&R page 49

uint8_t getBit(uint8_t number, uint8_t position)
{
	return number & 1 << position;
}

uint8_t setBit(uint8_t number, uint8_t position)
{
	return number | 1 << position;
}

uint8_t clearBit(uint8_t number, uint8_t position)
{
	return number & (~(1 << position));
}

uint8_t invertBit(uint8_t number, uint8_t position)
{
	return number ^= 1 << position;
}

uint8_t maskBits(uint8_t number, uint8_t mask)
{
	number & mask;
}

uint8_t getBits(uint8_t byteToGetBitsFrom, uint8_t position, uint8_t numberOfBits)
{
	return (byteToGetBitsFrom >> (position + 1 - numberOfBits)) & ~(~0 << numberOfBits);
}

// fix all below here

// test this
uint8_t setBits(uint8_t byteToSetBitsFrom, uint8_t position, uint8_t numberOfBits)
{
	return (byteToSetBitsFrom >> (position + 1 - numberOfBits)) | ~(~0 << numberOfBits);
}

// test this
uint8_t clearBits(uint8_t byteToClearBitsFrom, uint8_t position, uint8_t numberOfBits) {
	// return number & (~(1 << position));
	return (byteToClearBitsFrom >> (position + 1 - numberOfBits)) | ~(~0 << numberOfBits);
}

// test this
uint8_t invertBits(uint8_t byteToInvertBitsFrom, uint8_t position, uint8_t numberOfBits) {
	// return number ^= 1 << position;
	return (byteToInvertBitsFrom >> (position + 1 - numberOfBits)) | ~(~0 << numberOfBits);
}
