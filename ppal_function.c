/*
** ETNA PROJECT, 02/04/2021 by loizag_g
** my_crd
** File description:
**      ce fichier contient la function principale qui met en place les fonctions des listes chaînées
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_struct.h"

int ppal_function (char *line, linked_list_t **list)
{
    int nb;
    int first;
    int second;
    int i = 0;
    char **tab_line;
    tab_line = my_str_to_word_array(line);

    while (tab_line[i] != NULL)
        {
            i++;
        }
    if (i == 0)
        {
            return -1;
        }
    else if (i == 1)
        {
            nb = my_getnbr(tab_line[0]);
            print_value(nb, *list);
            return 1;
        }
    else if (i > 1 || i <= 2)
        {
            first = my_getnbr(tab_line[0]);
            
            if (tab_line[1][0] >= '0' && tab_line[1][0] <= '9')
                {
                    second = my_getnbr(tab_line[1]);
                    *list = add_node(first, second, *list);
                    return 2;
                }
            if (tab_line[1][0] == 'D')
                {
                    *list = remove_node(first, *list);
                    return 3;
                }
        }
    return 0;
}
