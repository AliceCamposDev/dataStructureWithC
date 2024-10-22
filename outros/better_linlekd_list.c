#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node_type;

node_type *mk_node(int value, node_type *next)
{
    node_type *new_node = malloc(sizeof(node_type));
    new_node->value = value;
    new_node->next = next;
    return new_node;
}

typedef struct list_type
{
    node_type *head;
} llist;

node_type *llist_lpush(llist *list, node_type *node)
{
    if (list == NULL || node == NULL)
    {
        return NULL;
    }

    node->next = list->head;
    list->head = node;
}

node_type *llist_rpush(llist *list, node_type *node)
{
    if (list == NULL || node == NULL)
    {
        return NULL;
    }
    if (list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        node_type *current = list->head;
        while (current->next)
        {
            current = current->next;
        }
        current->next = node;
    }
    return node;
}

int main()
{

    node_type *a = mk_node(7, NULL);
    node_type *b = mk_node(6, a);
    node_type *c = mk_node(5, b);
    node_type *d = mk_node(4, c);
    node_type *e = mk_node(3, d);
    node_type *f = mk_node(2, e);
    node_type *g = mk_node(1, f);

    return 0;
}
