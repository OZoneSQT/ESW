#include <stdio.h>

#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"
#include "modulo.h"

int main (void) {
  int a = 9;
  int b = 5;

  printf ("\nHere, we add, subtract, multiply, devide and finding remeinder....\n\n");
  printf ("%d\t+\t%d\t=\t%d\n", a, b, esw_add(a,b));
  printf ("%d\t-\t%d\t=\t%d\n", a, b, esw_subtract(a,b));
  printf ("%d\t*\t%d\t=\t%d\n", a, b, esw_multiply(a,b));
  printf("%d\t/\t%d\t=\t%f\n", a, b, esw_division(a, b)); // cast integers to float in method
  printf("%d\t%%\t%d\t=\t%d\n", a, b, esw_modulo(a, b)); // escape carachter for the sign % is also %
  return 0;
}


