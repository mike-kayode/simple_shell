#ifndef MAIN_H
#define MAIN_H

/* Header files */
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "main.h"
#include <errno.h>

/* Function prototypes */
int _putchar(char c);
int _strlen(char *s);
ssize_t _getline(char **lp, size_t *n, FILE *strm);
int _ac(char **arg, char *del);
char *_acv(char **arg, char *del, int ac);
void wr(void);
void mcerr(char *av);
void exe(char *cmd, char *av[]);

#endif /* MAIN_H */
