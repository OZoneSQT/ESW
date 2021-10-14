#include <stdio.h> 
#include <stdlib.h>
#include "queue.h"
#include "sender.h"
#include "reciver.h"
#include "queue.h"

static struct Item itm;

int rand_t()
{
	return rand() % 99 + 1;
}

int main(void)
{
	int size = 50;
	QueueInit(size);

	runSender();

	for (int i = 0; i < size; i++)
	{
		if (rand_t()%2)
		{
			if (!QueueIsFull)
			{
				runSender();
			}
			else
			{
				runReciver();
			}
			
		} 
		else
		{
			if (!QueueIsEmpty)
			{
				runReciver(); 
			}
			else
			{
				runSender();
			}
		}
	}

	return 0;
}
