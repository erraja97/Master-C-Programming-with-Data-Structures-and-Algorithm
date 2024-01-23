#include "dll.h"

int dl_delete_first(Dlist **head, Dlist **tail)
{
    if (*head == NULL)
    {
        return FAILURE;
    }

    // declare local pointer
    Dlist *temp = *head;

    // check if there is only one node
    // if (*head == *tail)
    if (temp->next == NULL)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        // point head to the second node
        *head = temp->next;

        // update the previous pointer of the new head to NULL
        (*head)->prev = NULL;
    }

    // free the first node
    free(temp);

    return SUCCESS;
}
