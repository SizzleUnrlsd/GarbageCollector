/*===---- garbage_collector.h - Standard header for garbage_collector --------------===*\
 *
 * Personel/Public project
 * Garbage_collector
 * garbaage_collector.h :  library with prototypes
 *
\*===-------------------------------------------------------------------------------===*/

#ifndef GARBAGE_COLLECTOR_H_
    #define GARBAGE_COLLECTOR_H_

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <stdint.h>

    #include "struct.h"

#endif /* GARBAGE_COLLECTOR_H_ */

void garbage_uncollector(collector_t *garbage);
void garbage_dump(garbage_struct_t *garbage_ptr);
void *my_memcpy(void *dest, const void *src, size_t n);
void free_attribut(void *p, garbage_struct_t *garbage);
void garbage_collector(void *p, garbage_struct_t *garbage);
void *malloc_attribut(size_t size, garbage_struct_t *garbage);
collector_t **realloc_struct(collector_t **p,
                size_t size, unsigned int len);