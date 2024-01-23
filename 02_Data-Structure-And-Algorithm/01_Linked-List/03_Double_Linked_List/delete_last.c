#include "dll.h"

int dl_delete_last(Dlist **head, Dlist **tail)
{

    // if list is empty
    if (*head == NULL)
    {
        return FAILURE;
    }

    // if list has only one node
    if (*head == *tail)
    {
        Dlist *temp = *head;
        *head = NULL;
        *tail = NULL;
        free(temp);
        return SUCCESS;
    }

    // if list has more than one node
    Dlist *temp = *head;
    Dlist *prev = NULL;

    while (temp != *tail)
    {
        prev = temp;
        temp = temp->next;
    }

    free(temp);
    prev->next = NULL;
    *tail = prev;

    return SUCCESS;
}