#include <stdlib.h>
#include "queue.h"
#include "item.h"

typedef struct QueueNode *link;

static int maxSize = 0;
static int elementCounter = 0;

struct QueueNode
{
	struct Item itm;
	link next;
};

static link head, tail;

link NEW(struct Item itm, link next)
{
	link x = malloc(sizeof (*x));
	x->itm = itm;
	x->next = next;
	return x;
}

void QueueInit(int size)
{
	head = NULL;
	maxSize = size;
	elementCounter = 0;
}

int QueueIsEmpty()
{
	return head == NULL;
}

int QueueIsFull()
{
	int result = 0;
	
	if (elementCounter >= maxSize)
	{
		result = 1;
	}

	return result;
}

void QueuePut(struct Item itm)
{
	if (head == NULL)
	{
		head = (tail = NEW(itm, head));
		elementCounter++;
		return;
	}
	tail->next = NEW(itm, head);
	tail->next;
}

struct Item QueueGet()
{
	struct Item itm = head->itm;
	link x = head->next;
	free(head);
	head = x;
	elementCounter--;
	return itm;
}
 