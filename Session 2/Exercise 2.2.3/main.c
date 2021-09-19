
#include <stdio.h>

#include "power.h"

int main(void)
{
	int x = 2;
	int y = 3;

	int result = power(x, y);

	printf("%d\t^\t%d\t = \t%d\n", x, y, result);

	return 0;
}