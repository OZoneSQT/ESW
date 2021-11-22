#pragma once
#include <stdint.h>

typedef enum {
    OK = 0,     // Everything OK
    EMPTY,      // List Empty
    NOT_FOUND,  // Item not found
    NULLL,      // List pointer is null, changed to nulll
    ERROR,      // Function could not be completed due to memory limit
} ListReturnCode;

typedef struct linkedList* list_t;

typedef struct linkedList {
    void* item;
    list_t* next; // next node
} node_t;

// Init linked list, returns list
list_t create(void);

// free all allocate memory
ListReturnCode destroy(list_t list);

// allocate memory for item and add item, to the end of list
ListReturnCode addItem(list_t list, void* item);

// return item, on position in list
void* getItemByIndex(list_t list, uint16_t index);

// remove a specfic item from list, note node-position changes, if a node is removed
ListReturnCode removeItem(list_t list, void* item);

// return number of items
uint16_t noOfitems(list_t list);

// check if list contains item
ListReturnCode contains(list_t head, void* item);