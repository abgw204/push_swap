#include "stack.h"

void if_error_free_and_exit(t_stack **a)
{
        ft_free(a);
        write(2, "Error\n", 6);
        exit(1);
}