#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <termios.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define DELIM " \t\r\n\a"
#define TOKEN_BUFSIZE 210

/* This points to an array of pointers to strings called the environment */
extern char **environ;

/**
 * struct term_cfg - stores terminal settings
 * @original: original terminal setting
 */
typedef struct term_cfg
{
	struct termios original;
} terminal_cfg;

void init_term(terminal_cfg *config);
void reset_term_init(terminal_cfg *config);
char *copy_str(char *dst, char *src);
int cmp_str(char *str1, char *str2);
int len_str(char *str);
char *concat_str(char *dst, char *src);
char *dup_str(const char *src);

#endif
