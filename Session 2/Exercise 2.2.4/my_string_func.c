#include <stdio.h>
#include "my_string_func.h"

/* read_line: read a line into s, return length */
int read_line(char s[])
{
	int c = 0;
	int i = 0;
	int done = 0;

	do
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			done = 1;
		}
		else
		{
			s[i++] = c;
		}
	} while (!done);

	s[i] = '\0';
	return i;

}

/*
*
* Viggo:
*	Just loop through the line array and subtract 32 to the lowercase char to make it uppercase and put
*	that into the upper array, in this loop you can also keep a counter to keep track of the line length.
*
*/


void my_to_upper(char* str_in, char* str_out)
{

	/* You must implement your own version of toupper using the two strings
	str_in and str_out.
	Loop over the str_in (as long as it "contains" something).
	Look at the "current" character and check if its a lowercase letter.
	If it is, convert it to the upper case version and add that to the
	str_out character array
	*/

}


char* my_toUpper(char* string)
{
	for (char* p = string; *p != '\0'; p++)
	{
		if (*p >= 'a' && *p <= 'z')  //Only if it's a lower letter
			*p -= 32;
	}
	return string;
}


char* my_toLower(char* string)
{
	for (char* p = string; *p != '\0'; p++)
	{
		if (*p >= 'A' && *p <= 'Z')  //Only if it's a capital letter
			*p += 32;
	}
	return string;
}
