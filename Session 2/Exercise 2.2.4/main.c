#include <stdio.h>
#include <ctype.h>

//#include "my_string_func.h"

#define MAX_LENGTH 1000
#define FILENAME "my_text_file.txt"

/*

	This exercise demonstrates you how you manipulate strings (character arrays); compute length of a
	string, as well as working with loops.

	Based on the below skeleton, complete the program to do the following:
	1. Converts each line being input to upper case and print it
	2. Computes the length of each line being input and prints the length
	3. Possibly combine the above two
	4. Implement the function my_to_upper and test it on a simple string such as “Hello World!”
	5. Implement the main loop to print the line length and the upper-cased version of the input lines –
	   use the file from above as your input file

	Note, that there are two ways to “feed” characters/lines of characters to your program. One is to just
	type using the keyboard and terminate the input feed by pressing ‘Enter’ on an empty line. Another
	is to redirect the standard input (keyboard) to a text file. Assume that your executable program is
	called “myprog.exe” then you redirect the keyboard to a file “myTextFile.txt” as follows:

*/

/*
*
* Viggo:
*	Just loop through the line array and subtract 32 to the lowercase char to make it uppercase and put
*	that into the upper array, in this loop you can also keep a counter to keep track of the line length.
*
*/

int main(void)
{
	char line[MAX_LENGTH];
	char upper[MAX_LENGTH];
	int line_length;


	// Read txt file
	FILE* ptr_file = fopen(FILENAME, "r");	// Accessing file, in read mode
	char buf[1000];


	// Error, asscessing file
	if (!ptr_file)
	{
		perror("Error, asscessing file");
		return 1;
	}
		

	/* Use a while loop to read input lines as long as there are any.
	For each input line, print the length of the line as well as
	the upper case version of the line
	NOTE You are NOT allowed to use the standard toupper(…)
	function in string.h
	*/

	while (fgets(buf, 1000, ptr_file) != NULL)
	{
		// printf("%d", read_line(fputs(buf, 1000, ptr_file))); 
		printf("%s", buf);
	}
		

	fclose(ptr_file);

	return 0;
}


/*

https://www.cplusplus.com/reference/cstdio/fgets/
https://www.geeksforgeeks.org/fgets-gets-c-language/
https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm




https://www.geeksforgeeks.org/toupper-function-in-c/

// C program to demonstrate
// example of toupper() function.
#include <ctype.h>
#include <stdio.h>

int main()
{
	int j = 0;
	char str[] = "geekforgeeks\n";
	char ch;

	while (str[j]) {
		ch = str[j];
		putchar(toupper(ch));
		j++;
	}

	return 0;
}


https://www.tutorialspoint.com/c_standard_library/c_function_toupper.htm

#include <stdio.h>
#include <ctype.h>

int main () {
   int i = 0;
   char c;
   char str[] = "Tutorials Point";

   while(str[i]) {
	  putchar (toupper(str[i]));
	  i++;
   }

   return(0);
}

*/