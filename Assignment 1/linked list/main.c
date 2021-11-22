// C program for generic linked list
#include <stdio.h>
#include <stdlib.h>
#include "Link.h"

/* Driver program to test above function */
int main()
{
    list_t list = create();

    uint16_t a = 10;
    uint16_t b = 11;
    uint16_t c = 12;
    uint16_t d = 13;
    uint16_t e = 14;

    addItem(list, a);
    addItem(list, b);
    addItem(list, c);
    addItem(list, d);
    addItem(list, e);
    printf(" %d", noOfitems(list));
  //  printf(contains(list, b));
 //   removeItem(list, b);
  //  printf(contains(list, b));
 //   destroy(list);
 
    return 0;
}