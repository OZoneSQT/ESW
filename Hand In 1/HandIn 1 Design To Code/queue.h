#pragma
#include "item.h"

// init queue with length and setting head as NULL
void QueueInit(int);

// returns boolean (0 = false, 1 = true) as an integer
int QueueIsEmpty(void);

// puts item in queue, as the tail
void QueuePut(item);

// get the head item from the queue
item QueueGet();