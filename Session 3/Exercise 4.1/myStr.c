// http://www.jbox.dk/sanos/source/lib/string.c.html


/* Returns length of string*/
int my_strlen(const char* str)
{
	const char* eos = str;
	while (*eos++);
	return (int)(eos - str - 1);
}


/*  Compare strings for equality Returns true/false */
int my_strcmp(const char* str1, const char* str2)
{
	int ret = 0;
	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str2) ++str1, ++str2;

	if (ret < 0) {
		ret = -1;
	}
	else if (ret > 0) {
		ret = 1;
	}

	return ret;
}


/* Returnes a copy of source string*/
char* my_strcpy(char *dest, const char *src)
{
	char* cp = dest;
	while (*cp++ = *src++);
	return dest;
}


/* Returns a pointer to a null-terminated byte string, must be passed to free(str)
   https://en.cppreference.com/w/c/experimental/dynamic/strdup */
char* my_strdup(const char *str)
{
	const char* eos = str;
	while (*eos++);
	return (int)(eos - str - 1);
}
