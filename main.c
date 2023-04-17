#include "main.h"

/**
 * main - main function for the simple shell program
 *
 * Return: always 0
 */

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int status;

    while (1)
    {
        print_prompt();

#ifdef __linux__
        nread = getline(&line, &len, stdin);
#elif _WIN32
        len = 1024; // set len to a reasonable value
        line = malloc(len);
        if (!line)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        if (fgets(line, len, stdin) == NULL)
        {
            free(line);
            exit(EXIT_SUCCESS);
        }
        nread = strlen(line);
#endif

        if (nread == -1)
        {
            free(line);
            _putchar('\n');
            exit(EXIT_SUCCESS);
        }

        status = execute(line);

#ifdef __linux__
        free(line);
        line = NULL;
#endif

        if (status == EXIT_FAILURE)
            exit(EXIT_FAILURE);
    }

    return (0);
}
