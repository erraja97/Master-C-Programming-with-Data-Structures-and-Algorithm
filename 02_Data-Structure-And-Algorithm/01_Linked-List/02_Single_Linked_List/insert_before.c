#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    // check if head is null or not
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // declare local reference pointer
    Slist *temp = *head;
    Slist *prev = NULL;

    // Check if the first node is the one to insert before
    if (temp->data == g_data)
    {
        Slist *new = malloc(sizeof(Slist));
        if (new == NULL)
        {
            return FAILURE;
        }
        new->data = ndata;
        new->link = temp;
        *head = new; // Update head to point to the new node
        return SUCCESS;
    }

    while (temp != NULL)
    {
        if (temp->data != g_data)
        {
            prev = temp;
            temp = temp->link;
        }
        else
        {
            Slist *new = malloc(sizeof(Slist));
            if (new == NULL)
            {
                return FAILURE;
            }
            new->data = ndata;
            new->link = temp;
            prev->link = new;
            return SUCCESS;
        }
    }

    return DATA_NOT_FOUND;
}
