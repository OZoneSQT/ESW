#include <stdio.h>
// #include <string.h>

#include "myStr.h"

#define A "Hello World"
#define B "Hello World"
#define E ""

/*

	Make three tests of the function, using constant strings as parameters:
	• Compare “Hello World” with “Hello World”
	• Compare “Hello World” with the empty string
	• Compare two empty strings
	• Compare “Hello World” with “Hello, world”

*/


char bool(int val)
{
	if (val == 0)
	{
		return "false";
	}
	else
	{
		return "true";
	}
}

int main(void)
{
	// Test strlen
	printf("The length of: %s is: %d", A, my_strlen(A));


	// Test strcmp
	printf("%s Compared with: %s is %s", A, A, bool(my_strcmp(A, A)));
	printf("%s Compared with: %s is %s", A, B, bool(my_strcmp(A, B)));
	printf("%s Compared with: %s is %s", A, A, bool(my_strcmp(A, E)));


	// Test strcpy
	char str1[20] = "Programming";
	char str2[20] = "";
	printf("str1 = %s, str2 = %s\n", str1, str2);
	my_strcpy(str2, str1);
	printf("str1 = %s, str2 = %s\n", str1, str2);


	// Test strdup
	char source[] = "Programming";

	char* target = my_strdup(source);
	printf("Source: %s, Target: %s", source, target);


	return 0;
}
