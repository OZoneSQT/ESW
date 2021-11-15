#include "LinkedList.h"
 
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


typedef struct List {
	node* head;
} List;

void create()
{
}

ListReturnCode destroy()
{
	return OK;
}

ListReturnCode addItem(void* item)
{
	return ERROR;
}

ListReturnCode getItem(void** item, uint16_t index)
{
	return NULL;
}

ListReturnCode removeItem(void* item)
{
	return ERROR;
}

uint16_t noOfItems()
{
	return 4;
}

void* getItem(uint16_t index)
{

	return noOfItems();
}
