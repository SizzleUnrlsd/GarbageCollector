/*===---- re_alloc.c - Standard header for garbage_collector ---------------------------===*\
 *
 * Personel/Public project
 * Garbage_collector
 * garbage_uncollector :  function to reallocate memory (make the array expandable) 
 *
\*===-----------------------------------------------------------------------------------===*/
#include "../garbage_collector.h"

collector_t **realloc_struct(collector_t **p,
                size_t size, unsigned int len)
{
    unsigned int i = 0;
    collector_t **p_nouveau =
    malloc(sizeof(collector_t *) * (size));
    for (; p[i]; i++) {
        if (i == LEN_ARRAY_STRUCT)
            break;
        p_nouveau[i] = malloc(sizeof(collector_t));
        p_nouveau[i]->index = p[i]->index;
        p_nouveau[i]->pointer = p[i]->pointer;
        free(p[i]);
    }
    i++;
    for (; i != len; i++) {
        p_nouveau[i] = malloc(sizeof(collector_t));
        p_nouveau[i]->index = 0;
        p_nouveau[i]->pointer = NULL;
    }
    free(p);
    return p_nouveau;
}
