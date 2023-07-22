#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

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

char *_strdup(char *str)
{
        int i = 0, n;
        char *dup;

        n = _strlen(str) + 1;
        dup = malloc(sizeof(char *) * n);
        while(*str != '\0')
        {
                dup[i] = str[i];
                str++;
        }
        return (dup);
}
