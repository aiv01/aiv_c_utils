#include "lists.h"

list_item *list_append(list_item *prev, void *data)
{
    list_item *new_item = malloc(sizeof(list_item));
    new_item->data = data;
    new_item->next = NULL;
    if (prev)
    {
        prev->next = new_item;
    }
    return new_item;
}

list_item *list_get(list_item *head, unsigned int index)
{
    while (head && index > 0)
    {
        index--;
        head = head->next;
    }
    return head;
}

list_item *list_remove(list_item *head, list_item *item)
{
    list_item *orig_head = head;
    list_item *prev = NULL;
    while (head)
    {
        if (head == item)
        {
            if (head == orig_head)
            {
                orig_head = head->next;
            }
            if (prev)
            {
                prev->next = head->next;
            }
            free(head);
            return orig_head;
        }
        prev = head;
        head = head->next;
    }
    return head;
}

unsigned int list_size(list_item *head)
{
    unsigned int counter = 0;
    while (head)
    {
        counter++;
        head = head->next;
    }
    return counter;
}

list_item *list_remove_by_index(list_item *head, unsigned int index)
{
    list_item *item = list_get(head, index);
    if (item)
    {
        head = list_remove(head, item);
    }
    return head;
}