/*
** EPITECH PROJECT, 2023
** memcpy
** File description:
** mem_cpy
*/
#include "../garbage_collector.h"

void *my_memcpy(void *dest, const void *src, size_t n)
{
    if (dest == NULL || src == NULL)
        return NULL;
    char *d = dest;
    const char *s = src;

    size_t i = 0;
    do {
        d[i] = s[i];
        i++;
    } while (i < n);

    return dest;
}

