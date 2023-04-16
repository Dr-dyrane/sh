#include "main.h"

/**
 * _sbrk - custom implementation of sbrk that returns a pointer to a block of
 *         memory of the requested size
 *
 * @increment: the number of bytes to increase the program break by
 *
 * Return: a pointer to the start of the newly allocated memory block
 */
void *_sbrk(ptrdiff_t increment)
{
    static char *memory_pool = NULL;  // Pointer to the start of our memory pool
    static char *program_break = NULL; // Pointer to the current program break
    void *allocated_memory = NULL; // Pointer to the start of the newly allocated memory block

    if (memory_pool == NULL) // Allocate memory pool if not yet allocated
    {
        memory_pool = malloc(MEMORY_POOL_SIZE);
        if (memory_pool == NULL)
            return NULL;
        program_break = memory_pool;
    }

    if (program_break + increment >= memory_pool + MEMORY_POOL_SIZE) // Out of memory
        return NULL;

    allocated_memory = program_break;
    program_break += increment;
    return allocated_memory;
}
