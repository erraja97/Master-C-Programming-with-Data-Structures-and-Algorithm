#include "stack.h"

/* Function for display the top of the element in Stack */
int Peek(Stack_t *s)
{

    // check Base Condition: Stack is empty or not
    if ((s->top) == -1)
    {
        return FAILURE;
    }


    // return top element
    return s->stack[s->top];
}