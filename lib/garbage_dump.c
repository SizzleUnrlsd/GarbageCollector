/*===---- garbage_collector.h - Standard header for garbage_collector -------------------------------===*\
 *
 * Personel/Public project
 * Garbage_collector
 * garbaage_dump :  At the end of your program, garbage_dump will take care of collecting your rubbish
 *
\*===------------------------------------------------------------------------------------------------===*/

#include "../garbage_collector.h"

void garbage_dump(garbage_struct_t *garbage_ptr)
{
    for (uint32_t i = 0; i != garbage_ptr->io; i++) {
        if (garbage_ptr->garbage[i] == NULL)
            continue;
        garbage_uncollector(garbage_ptr->garbage[i]);
        free(garbage_ptr->garbage[i]);
        garbage_ptr->garbage[i] = NULL;
    }
    free(garbage_ptr->garbage);
    free(garbage_ptr);
    return;
}