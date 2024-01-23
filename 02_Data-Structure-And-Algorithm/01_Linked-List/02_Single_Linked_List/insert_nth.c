#include "sll.h"

int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    // declare counter variable
    int counter = 0;

    if (*head == NULL && n > 1)
    {
        return LIST_EMPTY;
    }
    else if (*head == NULL || n == 1)
    {
        // Insert at the beginning
        Slist *new = malloc(sizeof(Slist));

        if (new == NULL)
        {
            return FAILURE;
        }

        new->data = data;
        new->link = *head;
        *head = new;

        return SUCCESS;
    }
    else
    {
        // declare local pointers
        Slist *temp = *head;
        Slist *prev = NULL;

        while (temp != NULL && n > counter)
        {
            counter++;

            if (counter != n)
            {
                prev = temp;
                temp = temp->link;
            }
            else
            {
                // Insert at the specified position
                Slist *new = malloc(sizeof(Slist));

                if (new == NULL)
                {
                    return FAILURE;
                }

                new->data = data;
                new->link = temp;
                prev->link = new;

                return SUCCESS;
            }
        }

        // Insert at the end of the list
        if (n == counter + 1)
        {
            Slist *new = malloc(sizeof(Slist));

            if (new == NULL)
            {
                return FAILURE;
            }

            new->data = data;
            new->link = NULL;
            prev->link = new;

            return SUCCESS;
        }
    }

    return POSITION_NOT_FOUND;
}
