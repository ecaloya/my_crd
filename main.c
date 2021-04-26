/*
** ETNA PROJECT, 02/04/2021 by loizag_g
** my_crd
** File description:
**      ce fichier est le main de tout le programme
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my_struct.h"

int main()
{
    char *line;
    linked_list_t *list = NULL;
    linked_list_t *tmp = list;
    line = my_readline();

    while (line != NULL)
        {
            ppal_function(line, &list);
            my_putstr("\n");
            line = my_readline();
        }
    while (tmp != NULL)
        {
            list = list->next;
            free(tmp);
            tmp = list;
        }
    return (0);
}
