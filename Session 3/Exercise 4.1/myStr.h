#pragma once

/* Returns length of string*/
int my_strlen(const char* str);

/*  Compare strings for equality Returns true/false */
int my_strcmp(const char* str1, const char* str2);

/* Returnes a copy of source string*/
char* my_strcpy(char* dest, const char* src);

/* Returns a pointer to a null-terminated byte string, must be passed to free(str) - https://en.cppreference.com/w/c/experimental/dynamic/strdup */
char* my_strdup(const char* str);