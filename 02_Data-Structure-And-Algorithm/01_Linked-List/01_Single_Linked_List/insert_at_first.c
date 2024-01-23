#include "sll.h"

int insert_at_first(Slist **head, data_t data)
{
    // create a node
    Slist *new = malloc(sizeof(Slist));

    // check if node created or not
    if (new == NULL)
    {
        return FAILURE;
    }

    // update the node data and link
    new->data = data;
    new->link = NULL;

    // check if list is empty or not
    if (*head == NULL)
    {

        // create the first node
        *head = new;
        return SUCCESS;
    }
    else
    {
        // create local pointer
        Slist *temp = *head;
        *head = new;
        new->link = temp;
    }
    return SUCCESS;
}