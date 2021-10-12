#pragma
#include "item.h"

// init queue with length and setting head as NULL
void QueueInit(int);

// returns boolean (0 = false, 1 = true) as an integer
int QueueIsEmpty(void);

// return numbers of items in the queue as an int
int QueueIsFull();

// puts item in queue, as the tail
void QueuePut(struct Item);

// get the head item from the queue
struct Item QueueGet();
