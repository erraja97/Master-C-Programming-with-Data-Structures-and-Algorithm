#include "dll.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL)
    {
        return FAILURE;
    }

    //declare local pointer
    Dlist *temp = NULL;

    //delete elements from list except last node
    while ((*head) != (*tail))
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    // delete last node and make head, tail point to null
    temp = *head;
    *head = NULL;
    *tail = NULL;
    free(temp);
    return SUCCESS;
}