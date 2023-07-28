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

extern char **environ;

/* Function prototypes */
void print_prompt();
void execute_command(const char *command);
void shell_main();
char *_strdup(char *s);
int _putchar(char c);
int _strlen(char *s);
char *_strcpy(char *dst, char *src);
ssize_t _getline(char **lp, size_t *n, FILE *strm);
int get_arg_count(char *s, const char *del);
char **get_arg_vector(char *s, char *del, int ac);
void wr(void);
void mcerr(char *av);
void exe(char *cmd, char *av[]);

#endif /* MAIN_H */
