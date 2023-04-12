/*
** EPITECH PROJECT, 2023
** B-PSU-200-RUN-2-1-minishell1-hugo.payet
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #define LEN_ARRAY_STRUCT 5000

    typedef struct collector_s {
        uint8_t *pointer;
        uint32_t index;
        char bound[4];
    } collector_t;

    typedef struct garbage_struct_s {
        collector_t **garbage;
        uint32_t io;
        char pbound[4];
    }garbage_struct_t;

#endif /* !STRUCT_H_ */
