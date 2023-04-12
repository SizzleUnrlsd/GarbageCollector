/*===---- garbage_uncollector.c - Standard header for garbage_collector ----------------===*\
 *
 * Personel/Public project
 * Garbage_collector
 * garbage_uncollector :  One of the unit functions of cleaning your waste 
 *
\*===-----------------------------------------------------------------------------------===*/

#include "../garbage_collector.h"

void garbage_uncollector(collector_t *garbage)
{
    if (garbage->pointer == NULL)
        return;
    else {
        free(garbage->pointer);
        garbage->pointer = NULL;
    }
    return;
}
