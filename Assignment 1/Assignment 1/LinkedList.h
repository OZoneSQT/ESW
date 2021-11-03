#pragma once
#include <stdint.h>

enum ListReturnCode {
    OK,
    EMPTY,
    NOT_FOUND,
    NULL,
    ERROR,
};

void create();
ListReturnCode destroy();
ListReturnCode addItem(void* item);
ListReturnCode getItem(void** item, uint16_t index);
ListReturnCode removeItem(void* item);
uint16_t noOfitems();
void* getItem(uint16_t index);