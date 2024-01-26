#include "stack.h"

/* Function for Poping the element */
int Pop(Stack_t *s)
{
    // Base Condition: check if stack is empty or not
    if ((s->top) == -1)
    {
        return FAILURE;
    }

    // decrement top
    s->top = (s->top) - 1;

    return SUCCESS;
}