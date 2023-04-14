#ifndef MAIN_H
#define MAIN_H

#ifdef __linux__
#include <unistd.h>
#elif _WIN32
#include <io.h>
#include <fcntl.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
void print_prompt(void);
int execute(char *line);
size_t _strlen(char *s);

#endif /* MAIN_H */
