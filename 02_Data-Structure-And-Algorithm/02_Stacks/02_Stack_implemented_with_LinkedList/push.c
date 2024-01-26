#include "stack.h"

int Push(Stack_t **top, data_t data)
{
    // create a node
    Stack_t *new = malloc(sizeof(Stack_t));

    // check if node is NULL or not
    if (new == NULL)
    {
        return FAILURE;
    }

    // update data and link of node
    new->data = data;
    new->link = NULL;

    // if stack is empty or not
    if (*top == NULL)
    {
        // if stack is empty top will point to new node
        *top = new;
        return SUCCESS;
    }
    else
    {
        // if stack is not empty top need to be updated to new node and update links of prev node
        new->link = *top;
        *top = new;
    }
    return SUCCESS;
}