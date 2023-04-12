/*===---- malloc_attribut.c - Standard header for garbage_collector --------------------===*\
 *
 * Personel/Public project
 * Garbage_collector
 * malloc_attribut :  special malloc that keeps track of your pointers (future rubbish)
 *
\*===-----------------------------------------------------------------------------------===*/

#include "../garbage_collector.h"

void *malloc_attribut(size_t size, garbage_struct_t *garbage_ptr)
{
    void *p = malloc(size);
    if (p == NULL)
        exit(84);
    garbage_collector(p, garbage_ptr);
    return p;
}
