#include "main.h"

#ifdef _WIN32 /* Windows specific code */

#include <windows.h>

/**
 * _malloc - custom implementation of malloc using VirtualAlloc
 *
 * @size: the size of the memory to allocate
 *
 * Return: a pointer to the allocated memory
 */
void *_malloc(size_t size)
{
    void *ptr = VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
    return ptr == NULL ? NULL : ptr;
}

#else /* Linux specific code */

#include <unistd.h>

/**
 * _malloc - custom implementation of malloc using sbrk
 *
 * @size: the size of the memory to allocate
 *
 * Return: a pointer to the allocated memory
 */
void *_malloc(size_t size)
{
    void *ptr = sbrk(size);
    return ptr == (void *) -1 ? NULL : ptr;
}

#endif /* _WIN32 */