#ifndef MY_LIST
#define MY_LIST

typedef struct linked_list
{
    int key;
    int value;
    struct linked_list *next;
} linked_list_t;

#endif

char *my_readline(void);
void my_putchar(char c);
void my_putstr(const char *str);
char **my_str_to_word_array(const char *);
int my_getnbr(const char *str);
void my_putnbr (int n);
int ppal_function (char *line, linked_list_t **list);
linked_list_t *add_node(int a, int b, linked_list_t *list);
void print_value(int a, linked_list_t *list);
linked_list_t *remove_node(int a, linked_list_t *list);
