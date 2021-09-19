// #include <stdio.h>

int power(int x, int y)
{
	// Use temp to prevent 2*2 => 4*4 => 16*16
	int temp = x;

	for (int i = 1; i < y; i++) {
		// printf("%d\n", x);
		x = temp * x;
	}
		
	return x;

}