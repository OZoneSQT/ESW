#include <stdio.h>

#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"

int main (void) {
  int a = 10;
  int b = -2;

  printf ("\nHere, we add, subtract and multiply....\n\n");
  printf ("%d\t+\t%d\t=\t%d\n", a, b, esw_add(a,b));
  printf ("%d\t-\t%d\t=\t%d\n", a, b, esw_subtract(a,b));
  printf ("%d\t*\t%d\t=\t%d\n", a, b, esw_multiply(a,b));
  printf("%d\t/\t%d\t=\t%d\n", a, b, esw_division(a, b));
  return 0;
}


