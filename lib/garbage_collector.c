/*===---- garbage_collector.c - Standard header for garbage_collector ----------------------------------------------------------===*\
 *
 * Personel/Public project
 * Garbage_collector
 * garbage_collector :  Lead manager of your waste. They retrieve it from the malloc special and redistribute it if necessary.
 *
\*===---------------------------------------------------------------------------------------------------------------------------===*/

#include "../garbage_collector.h"

static uint32_t index_int(void)
{
    static uint32_t a = 0;
    a++;
    return a;
}

void init_struct_garbage(collector_t *collector)
{
    *collector = (collector_t){.index = 0, .pointer = NULL};
}

void garbage_collector_extend(void *p, int32_t index, garbage_struct_t *garbage_struct)
{
    collector_t *collector = malloc(sizeof(collector_t));
    init_struct_garbage(collector);
    collector->index = index - 1;
    garbage_struct->io++;
    if (p == NULL)
        return;
    collector->pointer = p;
    garbage_struct->garbage[index - 1] = collector;
    return;
}

void garbage_collector(void *p, garbage_struct_t *garbage_ptr)
{
    static size_t acceptance_limit = LEN_ARRAY_STRUCT - 500;
    uint32_t index = index_int();
    if (index >= acceptance_limit) {
        acceptance_limit = acceptance_limit + 5000;
        garbage_ptr->garbage = realloc_struct(garbage_ptr->garbage, acceptance_limit, index);
    }
    garbage_collector_extend(p, index, garbage_ptr);
    return;
}
