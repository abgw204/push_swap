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

void ft_free_split(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}