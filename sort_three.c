#include "stack.h"

void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = find_max(*a);
	if (max->prev == NULL && check_sorted(*a) != true)
	{
		ft_ra(a);
		if (check_sorted(*a) == true)
			return ;
		ft_sa(a);
	}
	else if (max->prev && max->next != NULL && check_sorted(*a) != true)
	{
		ft_rra(a);
		if (check_sorted(*a) == true)
			return ;
		ft_sa(a);
	}
	else
	{
		if (check_sorted(*a) == true)
			return ;
		ft_sa(a);
	}
}

/*int main(void)
{
	t_stack *a = NULL;

  ft_stackadd_back(&a, ft_stacknew(489));
  ft_stackadd_back(&a, ft_stacknew(42));
  ft_stackadd_back(&a, ft_stacknew(-350));

  sort_three(&a);
  printf("%d\n", a->nbr);
  a = a->next;
  printf("%d\n", a->nbr);
  a = a->next;
  printf("%d\n", a->nbr);
}*/