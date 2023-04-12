/*===---- free_attribut.c - Standard header for garbage_collector ------------------------===*\
 *
 * Personel/Public project
 * Garbage_collector
 * free_attribut :  special free to destroy waste that needs to be specifically released
 *
\*===-------------------------------------------------------------------------------------===*/

#include "../garbage_collector.h"

void free_attribut(void *p, garbage_struct_t *garbage)
{
    uint32_t i = 0;
    for (; i != garbage->io; i++) {
        if (i > 0 && garbage->garbage[i - 1]->index < garbage->garbage[i]->index)
            continue;
        else if (i != 0)
            break;
    }
    for (uint32_t index = 0; index != i; index++) {
        printf("%p %p\n", garbage->garbage[index]->pointer, p);
        if (garbage->garbage[index]->pointer == p)
            garbage_uncollector(garbage->garbage[index]);
    }
    return;
}
