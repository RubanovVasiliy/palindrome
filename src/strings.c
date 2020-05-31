#include <stdio.h>
#include <stdlib.h>

int scmp(const char* str1, const char* str2)
{
    for (; *str1 && *str1 == *str2; str1++, str2++)
        ;
    return *str1 - *str2;
}

size_t slen(const char* str)
{
    size_t i = 0;
    while (*str++) {
        i++;
    }
    return i;
}

char* sdup(const char* s)
{
    size_t len = slen(s) + 1;
    void* new = malloc(len);
    if (new == NULL)
        return NULL;
    return (char*)memcpy(new, s, len);
}