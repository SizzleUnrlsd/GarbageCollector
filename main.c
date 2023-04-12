/*===---- garbage_collector.h - Standard header for garbage_collector --------------===*\
 *
 * Personel/Public project
 * Garbage_collector
 * main.c
 *
\*===-------------------------------------------------------------------------------===*/
#include "garbage_collector.h"

garbage_struct_t *init_garbage_structure(void)
{
    garbage_struct_t *garbage_struct = malloc(sizeof(garbage_struct_t));
    garbage_struct->garbage = malloc(sizeof(collector_t *) * LEN_ARRAY_STRUCT);
    if (garbage_struct->garbage == NULL)
        exit(84);
    garbage_struct->io = 0;
    return garbage_struct;
}

int main(void)
{
    garbage_struct_t *garbage_ptr = init_garbage_structure();
    char *str_a = malloc_attribut(sizeof(char) * (13 + 1), garbage_ptr);
    char *str_b = malloc_attribut(sizeof(char) * (13 + 1), garbage_ptr);

    memset(str_a, '0', 13);
    memset(str_b, '0', 13);
    str_a[13] = '\0';
    str_b[13] = '\0';
    printf("%s, %s\n", str_a, str_b);
    garbage_dump(garbage_ptr);
    return 0;
}
