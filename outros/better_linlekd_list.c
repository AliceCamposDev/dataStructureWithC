#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node_type;

typedef struct list_type
{
    node_type *head;
} llist;

// make new node
node_type *mk_node(int value, node_type *next)
{
    node_type *new_node = malloc(sizeof(node_type));
    new_node->value = value;
    new_node->next = next;
    return new_node;
}

// left push
node_type *llist_lpush(llist *list, node_type *node)
{
    if (list == NULL || node == NULL)
    {
        return NULL;
    }

    node->next = list->head;
    list->head = node;
}

// right push
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

// print list
void print_list(llist *list)
{
    if (list == NULL)
    {
        return;
    }
    node_type *current = list->head;
    printf("[%d", current->value);
    while (current->next)
    {
        current = current->next;
        printf(", %d", current->value);
    }
    printf("]");
}

// get node by its index
node_type *llist_at(llist *list, int index)
{
    if (list == NULL)
    {
        return NULL;
    }
    if (index == 0)
    {
        return list->head;
    }
    int i = index;
    node_type *current = list->head;

    while (current->next)
    {
        if (i == 1)
        {
            return current->next;
        }
        current = current->next;
        i--;
    }
    return NULL;
}

// delete node
node_type *llist_delete_node(llist *list, node_type *node)
{
    if (list == NULL)
    {
        return NULL;
    }

    node_type *current = list->head;

    if (node == current)
    {
        list->head = current->next;
        free(node);
        return (list->head);
    }

    while (current->next)
    {
        if (current->next == node)
        {
            if (current->next->next)
            {
                current->next = current->next->next;
                free(node);
                return (list->head);
            }
            current->next = NULL;
            free(node);
            return (list->head);
        }
        current = current->next;
    }
    return (list->head);
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

    llist *list = (llist *)malloc(sizeof(llist));
    list->head = g;

    print_list(list);
    printf("\n");
    printf("\n");
    node_type *z = mk_node(99, NULL);
    node_type *y = mk_node(7331, NULL);

    llist_lpush(list, z);
    llist_rpush(list, y);

    print_list(list);
    printf("\n");
    printf("\n");
    node_type *x = mk_node(1, NULL);

    x = llist_at(list, 0);
    printf("%d", x->value);
    printf("\n");
    printf("\n");

    llist_delete_node(list, llist_at(list, 4));
    print_list(list);
    printf("\n");
    printf("\n");
    llist_delete_node(list, llist_at(list, 7));
    print_list(list);
    printf("\n");
    printf("\n");
    llist_delete_node(list, llist_at(list, 0));
    print_list(list);

    printf("\n");
    return 0;
}
