#include "main.h"

/**
 * _fgetc - get a character from a file stream
 *
 * @stream: pointer to the file stream
 *
 * Return: the character read, or EOF on error
 */
int _fgetc(FILE *stream)
{
    char c;
    int ret;

#ifdef __linux__
    ret = read(fileno(stream), &c, 1);
#else
    ret = fgetc(stream);
    c = (char)ret;
#endif

    return (ret == -1 ? EOF : (int)c);
}
