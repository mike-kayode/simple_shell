#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "main.h"

/**
 *_strlen - Gets the length of a string
 *@s: String to find the length
 *
 *Return: Length of the string
*/

int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
	{
		perror("String");
		return (0);
	}
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 *_strcpy - Copies a string
 *@dst: Destination to be copied into
 *@src: Source to be copied from
 *Return: Copied String
*/

char *_strcpy(char *dst, char *src)
{
	int i;

	if (src == NULL)
	{
		perror("String_Copy");
		return (NULL);
	}
	for (i = 0; src[i] != '\0'; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

/**
 *_strdup - For duplicating a string
 *@str: String to be duplicated
 *
 *Return: Duplicated string
*/

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
