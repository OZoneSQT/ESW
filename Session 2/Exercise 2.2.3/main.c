
#include <stdio.h>

#include "power.h"

int main(void)
{
	int x = 2;
	int y = 3;

	int result = power(x, y);

	// '\t' is called escape sequence(a character) which represent the “tab”
	printf("%d\t^\t%d\t = \t%d\n", x, y, result);	

	return 0;
}