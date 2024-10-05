#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int value;
    struct node *next;
} node_t;

node_t *mk_node(int value, node_t *next)
{
    node_t *node = malloc(sizeof(node_t));

    node->value = value;
    node->next = next;

    return node;
}

void print_list(node_t *list)
{
    printf("%d", list->value);
    if (list->next != NULL)
    {
        printf(", ");
        print_list(list->next);
        return;
    }
    printf(".");
}

int get_value_by_index(node_t *list, int i)
{
    if (list == NULL || i < 0)
    {
        printf("\n O index solicitado é maior que a lista ou lista apresenta problemas\n");
        return 0;
    }

    if (i == 0)
    {
        return (list->value);
    }
    get_value_by_index(list->next, i - 1);
}

void delete_element(node_t **list, int i)
{
    if (*list == NULL || i < 0)
    {
        printf("\nO index solicitado é maior que a lista ou lista apresenta problemas\n");
        return;
    }

    node_t *current = *list;

    if (i == 0)
    {
        **list = *current->next;
        // free
        return;
    }

    if (i == 1)
    {
        if (current->next != NULL)
        {
            // free(current->next);
            current->next = current->next->next;
            return;
        }
    }

    delete_element(&current->next, i - 1);
    return;
}

void add_node(node_t **list, int value, int i)
{
    if (*list == NULL || i < 0)
    {
        printf("\nA lista apresenta problemas ou o index inserido foi maior que o permitido\n");
        return;
    }
    node_t *current = *list;

    if (i == 0)
    {
        node_t *new_node = mk_node(value, current);
        *list = new_node;

        return;
    }
    if (i == 1)
    {
        if (current->next != NULL)
        {
            node_t *new_node = mk_node(value, current->next);
            current->next = new_node;   
            return;
        }
        node_t *new_node = mk_node(value, NULL);
        current->next = new_node;
        return;
    }

    add_node(&current->next, value, i - 1);
}

int main()
{
    node_t *a = mk_node(7, NULL);
    node_t *b = mk_node(6, a);
    node_t *c = mk_node(5, b);
    node_t *d = mk_node(4, c);
    node_t *e = mk_node(3, d);
    node_t *f = mk_node(2, e);
    node_t *g = mk_node(1, f);

    node_t **list_index = &g;
    print_list(*list_index);
    printf("\nindex 4 = %d \n", get_value_by_index(*list_index, 4));
    printf("deleting index 4 node\n");
    delete_element(list_index, 4);
    print_list(*list_index);
    printf("\nindex 4 = %d \n", get_value_by_index(*list_index, 4));
    add_node(list_index, 9, 6);
    print_list(*list_index);
    printf("\nadding node with value 0 on index 5\n");
    add_node(list_index, 0, 5);
    print_list(*list_index);
    return 0;
}
