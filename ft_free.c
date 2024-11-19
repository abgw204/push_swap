#include "stack.h"
void ft_free(t_stack **stack)
{
	t_stack	*aux;

	if (!stack)
		return ;
	while (*stack)
	{
		aux = (*stack)->next;
		free(*stack);
		*stack = aux;
	}
	*stack = NULL;
}