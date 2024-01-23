#include "sll.h"

int insert_at_last(Slist **head, data_t data)
{

    // create a node
    Slist *new = malloc(sizeof(Slist));

    // error check
    if (new == NULL)
    {
        return FAILURE;
    }

    // update the node fields
    new->data = data;
    new->link = NULL;

    // check if list is empty or not
    if (*head == NULL)
    {
        *head = new;
        return SUCCESS;
    }

    // if list not empty
    // declare local reference pointer
    Slist *temp = *head;

    // traverse throught the list
    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    // establish link b/w last node and new node
    temp->link = new;
    return SUCCESS;
}