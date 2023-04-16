#include "main.h"

/**
 * _realloc - custom implementation of realloc using sbrk or VirtualAlloc
 *
 * @ptr: a pointer to the memory block to reallocate
 * @size: the new size of the memory block
 *
 * Return: a pointer to the reallocated memory block
 */
void *_realloc(void *ptr, size_t size)
{
#ifdef _WIN32 /* Windows specific code */
    if (ptr == NULL)
        return _malloc(size);

    void *new_ptr = VirtualAlloc(NULL, size, MEM_COMMIT, PAGE_READWRITE);
    if (new_ptr == NULL)
        return NULL;

    // Copy the old contents to the new location
    _memcpy(new_ptr, ptr, size);
    VirtualFree(ptr, 0, MEM_RELEASE);
    return new_ptr;

#else /* Linux specific code */
    if (ptr == NULL)
        return _malloc(size);

    void *new_ptr = sbrk(size);
    if (new_ptr == (void *) -1)
        return NULL;

    // Copy the old contents to the new location
    _memcpy(new_ptr, ptr, size);
    return new_ptr;

#endif /* _WIN32 */
}
