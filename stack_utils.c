#include "stack.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		ft_error(3);
	new_node->nbr = content;
	new_node->next = NULL;
	return (new_node);
}

int	ft_stacksize(t_stack *stack)
{
	size_t	i;
	t_stack	*temp;

	i = 0;
	if (stack == NULL)
		return (0);
	temp = stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*current;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
	new->prev = current;
}

void	ft_lstadd_front(t_stack **lst, t_stack **new)
{
	if (lst == NULL || new == NULL)
		return ;
	(*new)->next = *lst;
	(*new)->prev = NULL;
	*lst = *new;
}