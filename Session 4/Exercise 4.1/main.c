#include <stdio.h>

#define FILENAME "my_text_file.txt"
char* name = "Bob\n";

int main(void)
{
	
	// Read txt file
	FILE* ptr_file = fopen(FILENAME, "w");	// Accessing file, in write mode, a will keep existing text
	// char buf[255];

	// Error, asscessing file
	if (!ptr_file)
	{
		perror("Error, asscessing file");
		return 1;
	}

	// action
	fprintf(ptr_file, "test:\n");	// note: without %s
	fputs(name, ptr_file);

	// close file
	fclose(ptr_file);

	return 0;
}