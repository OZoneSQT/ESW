#include <stdio.h> 
#include <stdlib.h>
#include "queue.h"
#include "sender.h"
#include "reciver.h"

int main(void)
{
	int size = 3;
	
	QueueInit(size);

	for(int i = 0; i < 50; i++)
	{
		runSender();
		runReciver();
	}

	return 0;
}