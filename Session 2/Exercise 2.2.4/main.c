#include <stdio.h>

// #include "my_string_func.h"

#define MAX_LENGTH 1000

/*
* 
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



int main()
{
	char line[MAX_LENGTH];
	char upper[MAX_LENGTH];
	int line_length;
	char string[1000];
	

	// Read txt file
	FILE* ptr_file;
	char buf[1000];
	

	ptr_file = fopen("my_text_file.txt", "r");
	if (!ptr_file)
		return 1;

	/*
	while (fgets(buf, 1000, ptr_file) != NULL)
			++line_length;

	printf("line count = %d\n", line_length);
	*/

	while (fgets(buf, 1000, ptr_file) != NULL)
		puts(string);
		
		// printf("%s", buf);
		
	printf("%s", string);

	/* Use a while loop to read input lines as long as there are any.
	For each input line, print the length of the line as well as
	the upper case version of the line
	NOTE You are NOT allowed to use the standard toupper(…)
	function in string.h
	*/

	/*
	while ( /* Something should go here */ /*) {
		/* And here do the my_to_upper(…)*/ 
		/*	printf("Length: %d\t%s\n", line_length, upper);
	}
	*/

	fclose(ptr_file);

	return 0;
}



/*

https://www.cplusplus.com/reference/cstdio/fgets/
https://www.geeksforgeeks.org/fgets-gets-c-language/
https://www.tutorialspoint.com/c_standard_library/c_function_fgets.htm

#include <stdio.h>

int main()
{
	FILE* pFile;
	char mystring[100];

	pFile = fopen("myfile.txt", "r");
	if (pFile == NULL) perror("Error opening file");
	else {
		if (fgets(mystring, 100, pFile) != NULL)
			puts(mystring);
		fclose(pFile);
	}
	return 0;
}

*/