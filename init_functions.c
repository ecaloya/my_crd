/*
** ETNA PROJECT, 02/04/2021 by loizag_g
** my_crd
** File description:
**      ce fichier conient toutes les functions nécessaires pour initialiser le programme
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_struct.h"

char *my_readline(void)
{
  size_t n = 0;
  char *ret = NULL;
  ssize_t result = getline(&ret, &n, stdin);

  if (result <= 0) {
    free(ret);
    return NULL;
  }
  if (ret[result - 1] == '\n') {
    ret[result - 1] = '\0';
  }
  return ret;
}

void my_putchar(char c)
{
  write(1, &c, 1);
}

void my_putstr(const char *str)
{
    int i = 0;
    
    while (str[i] != '\0')
    {
        my_putchar(str[i]);
        i++;
    }
}

/* word_count is need to my_str_to_word_array */

int word_count(const char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0')
        {
            while (str[i] != '\0' && str[i] == ' ')
                {
                    i++;
                }
            if (str[i] != '\0')
                {
                    count++;
                }
            while (str[i] != '\0' && str[i] != ' ')
                {
                    i++;
                }
        }
    return count;
}

char **my_str_to_word_array(const char *str)
{
    char **tab;
    int nb_words = word_count(str) + 1;
    int i = 0;
    int j = 0;
    int w = 0;
    int tab_index = 0;

    tab = malloc((nb_words * sizeof(char*) + 2));

    while (str[i] != '\0')
        {
            while (str[j] != '\0' && str[j] != ' ')
                {
                    j++;
                }
            tab[tab_index] = malloc(sizeof(char) * (j - i) + 1);

            while (i < j)
                {
                    tab[tab_index][w] = str[i];
                    i++;
                    w++;
                }
            tab[tab_index][w] = '\0';
            tab_index++;
            w = 0;

            while (str[i] != '\0' && str[i] == ' ')
                {
                    i++;
                }
            j = i;
        }
    tab[tab_index] = NULL;
    return tab;
}

/* get_neg is needed for my_getnbr */

int get_neg(const char *str)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
        {
            if (str[i] == '-')
                {
                    j++;
                }
            i++;
        }

    if (j % 2 == 0)
        {
            return 1;
        }
    return -1;
}

int my_getnbr(const char *str)
{
    int i = 0;
    int num = 0;
    int digit = 0;
    int m;
    m = get_neg(str);

    while (str[i] != '\0')
        {
            if (str[i] >= '0' && str[i] <= '9')
                {
                    digit = str[i] - '0';
                    num = num * 10 + digit;
                }
            i++;
        }
    return num * m;
}

int get_position(int n)
{
    int res = 1;
    while (n >= 10)
        {
            n = n / 10;
            res = res * 10;            
        }
    return res;
}


void my_putnbr(int n)
{
    int div;
    if (n < 0)
        {
            my_putchar('-');
            n = -n;
        }
    div = get_position(n);
    while (n >= 10)
        {
            my_putchar(n / div + '0');
            n = n % div;
            div = div / 10;
        }
    my_putchar(n/div + '0');
}
