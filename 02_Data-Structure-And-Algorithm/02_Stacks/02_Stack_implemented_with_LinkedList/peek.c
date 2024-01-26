#include "stack.h"

int Peek(Stack_t **top)
{
    if (*top == NULL)
    {
        return FAILURE;
    }

    // print top element
    return (*top)->data;
}