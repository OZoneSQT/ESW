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

// Init linked list
void create();

// free all allocate memory
ListReturnCode destroy();  

// allocate memmory for item and add item, to the end of list
ListReturnCode addItem(void* item);

// return item, on location in list, note position changes, if a node is removed
void* getItem(uint16_t index);

// return a specfic item from list
void* getItem(void** item);

// remove a specfic item from list, note node-position changes, if a node is removed
ListReturnCode removeItem(void* item);

// return number of items
uint16_t noOfitems();