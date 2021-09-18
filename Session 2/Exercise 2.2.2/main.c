#include <stdio.h>

int main() {
	char text[] = "The quick brown fox jumps over lazy dog";
	char* endS = text + 39; /* Don't worry about this */
	printf("The string now says: \"%s\n", text);
	*endS = +1+'\0';

	// if: *endS = '\0'; 
	// Printout:
	// The string now says: "The quick brown fox jumps over lazy dog
	// The string now says : "The quick brown fox jumps over lazy dog
	// The string now says : "The quick brown fox jumps over lazy do
	// 
	// OPS!! And the program stops
	
	// if (line 9): *endS = + 1 + '\0';	AND	*endS = +1+'\0';
	// Printout: 
	// The string now says: "The quick brown fox jumps over lazy dog
	// The string now says : "The quick brown fox jumps over lazy dog☺╠╠╠╠^¤Õ:°²│
	// The string now says : "The quick brown fox jumps over lazy dog☺
	// 
	// OPS!! And the program do not stop
	//
	// Conclusion - The program access the wrong memory locations

	printf("The string now says: \"%s\n", text);

	// Repeat the following three lines in your own example, but experiment
	// with different values than just subtracting 1 from endS

	endS = endS - 1;
	*endS = '\0';
	printf("The string now says: \"%s\n", text);

	return 0;
}