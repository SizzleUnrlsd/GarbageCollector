/**
 * Copyright (C) 2023 hugo
 * 
 * This file is part of garbage.
 * 
 * garbage is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * garbage is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with garbage.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "garbage-collector.h"

char *foo(const char *str)
{
    unused void *ptr = (void*)_malloc(sizeof(void*));

    return strdup(str);
}

int main(void)
{
    garbage_constructor();
    void *ptr0 = _malloc(sizeof(void*) * 8);

    char *str0 = foo("Hello !\n");
    garbage_backup_ptr(str0);

    char *str1 = foo("World !\n");
    garbage_backup_ptr(str1);

    unused void *ptr1 = _malloc(sizeof(void*) * 8);

    garbage_stat();
    garbage_routine();

    _free(ptr0);
    garbage_stat();

    return 0;
}
