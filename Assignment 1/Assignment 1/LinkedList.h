#pragma once
#include <stdint.h>

typedef enum listReturnCode {
    OK = 0,     // Everything OK
    EMPTY,      // List Empty
    NOT_FOUND,  // Item not found
    NULLL,      // List pointer is null, changed to nulll
    ERROR,      // Function could not be completed due to memory limit
} ListReturnCode;

typedef struct node* Node;
struct node
{
    void* item;
    Node* next;
};

void create();
ListReturnCode destroy();
ListReturnCode addItem(void* item);
void* getItem(uint16_t index);
void* getItem(void** item);
ListReturnCode removeItem(void* item);
uint16_t noOfitems();