#include <stdio.h>

main()
{
	int c;

	while ((c = getchar()) != EOF)
		printf("EOF is %d\n", EOF);		// Ex 1-7 Print value of EOF
		putchar(c);

}

/* 
* EX 1.6
* 
* 	No booleans in C => 0 = false, 1 = true
* 	
*	EOF = End of line,
*
* 	!= EOF  =  1   (not end of line != 0 )
*
*/

