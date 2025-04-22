#include "simpleshell.h"

size_t _strlen(const char *s)
{
    size_t len = 0;
    while (s && s[len])
        len++;
    return len;
}

char *_strcpy(char *dest, const char *src)
{
    char *start = dest;
    while ((*dest++ = *src++));
    return start;
}

char *_strcat(char *dest, const char *src)
{
    char *start = dest;
    while (*dest) dest++;
    while ((*dest++ = *src++));
    return start;
}
