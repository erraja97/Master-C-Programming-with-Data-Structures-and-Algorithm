#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{
    // Check if the list is empty
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }

    // Declare local pointers
    Dlist *temp = *head;

    // Check if the element to be deleted is in the first node
    if (temp->data == data)
    {
        *head = temp->next;

        // If the list becomes empty after deletion, update tail to NULL
        if (*head == NULL)
        {
            *tail = NULL;
        }
        else
        {
            (*head)->prev = NULL;
        }

        free(temp);
        return SUCCESS;
    }

    // Traverse the list to find the element to be deleted
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            Dlist *prevNode = temp->prev;
            Dlist *nextNode = temp->next;

            // Update the next pointer of the previous node
            if (prevNode != NULL)
            {
                prevNode->next = nextNode;
            }
            else
            {
                // If prevNode is NULL, it means temp is the current head
                *head = nextNode;
            }

            // Update the previous pointer of the next node
            if (nextNode != NULL)
            {
                nextNode->prev = prevNode;
            }
            else
            {
                // If nextNode is NULL, it means temp is the current tail
                *tail = prevNode;
            }

            free(temp);
            return SUCCESS;
        }

        temp = temp->next;
    }

    // Element not found in the list
    return DATA_NOT_FOUND;
}
