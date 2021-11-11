#pragma once
#include <stdint.h>

enum ListReturnCode {
    OK = 0,
    EMPTY,
    NOT_FOUND,
    NULL,
    ERROR,
};

typedef struct Item* item 
{
    // Anonymous union
    union {
        void* data_a;
        void* data_b;
    };
}

typedef struct Node* node
{
    void* item;
    uint16_t index;
    Node* next;
}

void create();
ListReturnCode destroy();
ListReturnCode addItem(void* item);
ListReturnCode getItem(void** item, uint16_t index);
ListReturnCode removeItem(void* item);
uint16_t noOfitems();
void* getItem(uint16_t index);