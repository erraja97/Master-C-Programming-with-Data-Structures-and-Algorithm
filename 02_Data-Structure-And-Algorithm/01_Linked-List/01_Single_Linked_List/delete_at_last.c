#include "sll.h"

int sl_delete_last(Slist **head)
{

    // check if list is empty or ghaving only one node
    // if (*head == NULL || (*head)->link == NULL)

    // check if list is empty
    if (*head == NULL)
    {
        return FAILURE;
    }

    // declare local pointer
    Slist *temp = *head;
    Slist *prev = NULL;

    // traverse till last node
    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }

    // free the last node
    free(temp);

    // update link of the second-to-last node to NULL
    if (prev != NULL)
    {
        prev->link = NULL;
    }
    else
    {
        // If there was only one node, update the head to NULL
        *head = NULL;
    }

    return SUCCESS;
}