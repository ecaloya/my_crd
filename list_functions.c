/*
** ETNA PROJECT, 02/04/2021 by loizag_g
** my_crd
** File description:
**      ce fichier contient les trois functions utilisées pour les listes chaînées
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_struct.h"

linked_list_t *add_node(int a, int b, linked_list_t *list)
{
    linked_list_t *node;
    node = malloc(sizeof(linked_list_t));

    linked_list_t *tmp = list;
    while (list != NULL)
        {
            if (a == list->key)
                {
                    my_putnbr(a);
                    list->value = b;
                    list = tmp;
                    return list;
                }
            list = list->next;
        }
    list = tmp;

    if (node == NULL)
        {
            return NULL;
        }
    node->key = a;
    node->value = b;
    node->next = list;
    my_putnbr(node->key);
    free(list);
    free(tmp);
    return node;

}

void print_value(int a, linked_list_t *list)
{
    linked_list_t *tmp = list;
    while (list != NULL)
        {
            if (a == list->key)
                {
                    my_putnbr(list->value);
                    list = tmp;
                    return;
                }
            list = list->next;
        }
    list = tmp;
    my_putnbr(-1);
    free(list);
    free(tmp);
}

linked_list_t *remove_node(int a, linked_list_t *list)
{
    linked_list_t *tmp = list;
    while (list != NULL)
        {
            if (a == list->key)
                {
                    list = list->next;
                    list = tmp;
                    my_putnbr(list->value);
                    return 0;
                }
            list = list->next;
        }
    list = tmp;
    my_putnbr(-1);
    free(tmp);
    return list;
}
