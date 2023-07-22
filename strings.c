#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "main.h"

int _strlen(char *s)
{
        int len = 0;

        while(*s != '\0')
        {
                len++;
                s++;
        }
        return (len);
}

char *_strcpy(char *dst, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char *_strdup(char *str)
{
        int n;
        char *dup;

	if (str == NULL)
		return (NULL);
        n = _strlen(str) + 1;
        dup = malloc(sizeof(char *) * n);
	if (dup == NULL)
	{
		perror("Malloc: ");
		free(dup);
		exit(EXIT_FAILURE);
	}
        if (dup != NULL)
		dup = _strcpy(dup, str);
	return (dup);
}
