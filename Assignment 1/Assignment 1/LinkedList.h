#pragma once

#include <stdint.h>

typedef enum ListReturnCode {
    OK = 0,
    EMPTY,
    NOT_FOUND,
    NUL,
    ERROR,
} ListReturnCode;

typedef struct Item* item;
struct Item
{
    // Anonymous union 
    union {
        void* data_a;
        void* data_b;  
    };
};

typedef struct Node* node;
struct Node
{
    void* content;
    node* next;
};

void create();
ListReturnCode destroy();
ListReturnCode addItem(void* item);
ListReturnCode getItem(void** item, uint16_t index);
ListReturnCode removeItem(void* item);
uint16_t noOfItems();
void* getItem(uint16_t index);

