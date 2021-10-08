#include <stdlib.h>
#include "queue.h"
#include "item.h"

typedef struct QueueNode* link;

struct QueueNode
{
	item itm;
	link next;
};

static link head, tail;

link NEW(item itm, link next)
{
	link x = malloc(sizeof * x);
	x->itm = itm;
	x->next = next;
	return x;
}

void QueueInit(int size)
{
	head = NULL;
}

int QueueIsEmpty()
{
	return head == NULL;
}

void QueuePut(item itm)
{
	if (head == NULL)
	{
		head = (tail = NEW(itm, head));
		return;
	}
	tail->next = NEW(itm, head);
	tail->next;
}

item QueueGet()
{
	item itm = head->itm;
	link x = head->next;
	free(head);
	head = x;
	return x;
}