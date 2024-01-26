#include "stack.h"

int Pop(Stack_t **top)
{

    // check if list is empty or not also check if we have more than 1 node or not
    if (*top == NULL)
    {
        return FAILURE;
    }

    // declare local pointer
    Stack_t *temp = *top;

    // point head to 2nd node
    *top = temp->link;

    // free first node
    free(temp);

    return SUCCESS;
}