#include <stdio.h>
#include "reciver.h"
#include "queue.h"

static struct Item itm;

void runReciver()
{
	itm = QueueGet();
	printf("Message id: %d content %s\n", itm.number, itm.string);
}

