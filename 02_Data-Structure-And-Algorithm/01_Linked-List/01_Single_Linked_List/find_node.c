#include "sll.h"

int find_node(Slist *head, data_t data)
{
    if (head == NULL)
    {
        return FAILURE;
    }

    // create local pointer
    Slist *temp = head;

    // declare counter variable
    int counter = 1;

    while (temp != NULL)
    {

        if (temp->data == data)
        {

            return counter;
        }
        else
        {
            temp = temp->link;
            counter++;
        }
    }

    return FAILURE;
}
