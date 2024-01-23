#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{

    // if list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    //create new node
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
    {
        return FAILURE;
    }

    //assign data to new node
    new->data = ndata;
    new->next = NULL;
    new->prev = NULL;

    // declare local pointers
    Dlist *temp = *head;
    Dlist *afterTemp = NULL;

    // if data found at first node
    if (temp->data == gdata)
    {
        new->prev = temp;
        new->next = temp->next;
        temp->next = new;
        temp = new->next;

        if (temp != NULL)
        {
            temp->prev = new;
        }
        else
        {
            // If temp is NULL, it means new is the new tail
            *tail = new;
        }

        return SUCCESS;
    }

    // if data found at last node or in between nodes
    while (temp != NULL)
    {
        if (temp->data == gdata)
        {
            afterTemp = temp->next;

            new->prev = temp;
            new->next = afterTemp;

            temp->next = new;

            if (afterTemp != NULL)
            {
                afterTemp->prev = new;
            }
            else
            {
                // If afterTemp is NULL, it means temp is the current tail
                *tail = new;
            }

            return SUCCESS;
        }
        temp = temp->next;
    }

    return DATA_NOT_FOUND;
}
