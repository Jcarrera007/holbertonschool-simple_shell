#include "simpleshell.h"

int _strlen(const char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char *_strdup(const char *str)
{
	char *dup;
	int len = _strlen(str);
	int i;

	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	for (i = 0; i <= len; i++)
		dup[i] = str[i];
	return (dup);
}

char *_strcpy(char *dest, const char *src)
{
	int i;
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;
	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
