#include "stack.h"

/* Fuction for inserting the element */
int Push(Stack_t *s, int element)
{

    // Base Condition: check if stack is full or not
    if ((s->top) == (s->capacity - 1))
    {
        return FAILURE;
    }

    // if stack not empty update top
    //  s->top = ++(s->top);
    s->top = (s->top) + 1;

    // push element to stack
    s->stack[s->top] = element;

    return SUCCESS;
}