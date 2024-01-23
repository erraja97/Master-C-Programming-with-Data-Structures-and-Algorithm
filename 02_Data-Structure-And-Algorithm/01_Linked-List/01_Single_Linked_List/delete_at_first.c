#include "sll.h"

int sl_delete_first(Slist **head)
{

    // check if list is empty or not also check if we have more than 1 node or not
    // if (*head == NULL || (*head)->link == NULL)

    // check if list is empty or not also check if we have more than 1 node or not
    if (*head == NULL)
    {
        return FAILURE;
    }

    // declare local pointer
    Slist *temp = *head;

    // point head to 2nd node
    *head = temp->link;

    // free first node
    free(temp);

    return SUCCESS;
}