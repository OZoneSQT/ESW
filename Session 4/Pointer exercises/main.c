#include <stdio.h>

/*
	Pointer exercises:
	What will be printed to the console?
*/
void function_x(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main(void)
{
	int x = 42;
	int* ip;

	ip = &x;

	printf("x: %d\n", x);		// x = 42
	printf("*ip: %d\n", *ip);	// address of *ip
	printf("ip: %d\n", ip);		// address of ip
	printf("&ip: %d\n", &ip);	// address of ip
	printf("&x: %d\n", &x);		// address of x

	x++;						// x = 42
	(*ip)++;					// ip = 44
	printf("*ip: %d\n", ip);	// address of x


	// next

	int y = 13;
	int* iq;

	iq = &y;

	printf("*iq: %d\n", *iq);	// y = 13

	*iq = *ip;

	printf("*iq: %d\n", *iq);	// iq = 44 (ip)


	// last

	*ip = 5;
	*iq = 10;

	function_x(ip, iq);

	printf("*ip: %d\n", *ip);	// 5
	printf("*iq: %d\n", *iq);	// 10

	int p = 22;
	int q = 44;
	function_x(&p, &q);
	printf("p: %d\n", p);		// 44
	printf("q: %d\n", q);		// 22

	return 0;
}


