#include "sll.h"

int sl_delete_element(Slist **head, data_t data)
{
    // check if list is empty or not
    if (*head == NULL)
    {
        return FAILURE;
    }

    // declare local pointers
    Slist *temp = *head;
    Slist *prev = NULL;

    // check if element is present in fisrt node
    if (temp->data == data)
    {
        *head = temp->link;
        free(temp);
        return SUCCESS;
    }
    else
    {
        prev = temp;
        temp = temp->link;

        while (temp != NULL)
        {

            if (temp->data == data)
            {

                prev->link = temp->link;
                free(temp);
                return SUCCESS;
            }
            else
            {
                prev = temp;
                temp = temp->link;
            }
        }
    }

    return DATA_NOT_FOUND;
}