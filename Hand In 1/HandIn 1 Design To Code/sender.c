#include <stdlib.h>
#include "item.h"
#include "sender.h"
#include "queue.h"

static item itm;
static int id = 0;

int random()
{
    return rand() % 5 + 1;
}

char* content()
{
	int r = random();
	char* message = "\n";

	if (r = 0)
	{
		message = "glroijg aprjkgh pnrs kgbp\n";
	}
	else if (r = 1)
	{
		message = "yjroijg rygh prytrs yrt sp\n";
	}
	else if (r = 2)
	{
		message = "fg ojg ape kgh pnrs g hrp\n";
	}
	else if (r = 3)
	{
		message = "tuyjtyk ijg apytjr jkgesp\n";

	}
	else if (r = 4)
	{
		message = "tut trhj jt rtsuhy rt trh\n";
	}
	else
	{
		message = "strange things can happen\n";
	}

	return message;

}


void runSender()
{
	while (!QueueIsFull)
	{
		itm.number = id;
		itm.string = content();
		
		QueuePut(itm);
		id++;
	}
}