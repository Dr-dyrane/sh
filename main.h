#ifndef MAIN_H
#define MAIN_H

#define READ_SIZE 1024
#define MEMORY_POOL_SIZE 1024 * 1024 // 1MB memory pool

#ifdef __linux__
#include <unistd.h>

#elif _WIN32
#include <io.h>
#include <fcntl.h>
#include <windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Custom memory management functions */
void *_sbrk(ptrdiff_t increment);

/* Function prototypes */
void print_prompt(void);
int execute(char *line);
size_t _strlen(char *s);
int _getline(char **lineptr, size_t *n, FILE *stream);
int _fgetc(FILE *stream);
void *_realloc(void *ptr, size_t size);
void *_memcpy(void *dest, const void *src, size_t n);

#endif /* MAIN_H */
