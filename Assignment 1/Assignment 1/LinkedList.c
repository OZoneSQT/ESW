#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

#define ListReturnCode;


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

uint16_t noOfitems()
{
	return 4;
}

void* getItem(uint16_t index)
{
	return nullptr;
}
