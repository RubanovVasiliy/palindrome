#ifndef STRINGS
#define STRINGS

#include <stddef.h>

char incorrect_sym[] = " .,!?-+=\"'\\/():;*<>[]{}#$%^&@_|\n\t";

int scmp(const char* str1, const char* str2);
size_t slen(const char* str);

#endif