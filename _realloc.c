#include "main.h"

/**
 * re_alloc - allocate memory and set all values to 0
 * @ptr: pointer to the memory previously allocated (malloc(old_size))
 * @old_size: size previously allocated
 * @new_size: new size to reallocate
 * Return: pointer to reallocated memory
 */

void *re_alloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        void *p;
        unsigned int x;

        if (new_size == 0 && ptr != NULL) /* free memory if reallocate 0 */
        {
                free(ptr);
                return (NULL);
        }

        if (new_size == old_size) /* return ptr if reallocating same old size */
                return (ptr);

        if (ptr == NULL) /* malloc new size if ptr is originally null */
        {
                p = malloc(new_size);
                if (p == NULL)
                        return (NULL);
                else
                        return (p);
        }

        p = malloc(new_size); /* malloc and check error */
        if (p == NULL)
                return (NULL);

        /* fill up values up till minimum of old or new size */
        for (x = 0; x < old_size && x < new_size; x++)
                *((char *)p + x) = *((char *)ptr + x);
        free(ptr); /* free old ptr */

        return (p);
}
