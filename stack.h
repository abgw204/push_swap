#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_stack
{
	int            nbr;
    int            index;
    bool            have_index;
	struct s_stack	*next;
    struct s_stack  *prev;
} t_stack;

int	ft_stacksize(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int nbr);
void	*ft_calloc(size_t num, size_t size);
void	sort_three(t_stack **a);
void binary_radix(t_stack **a, t_stack **b);
void print_stacks(t_stack *a, t_stack *b);
void ft_sa(t_stack **a);
void ft_sb(t_stack **b);
void ft_ra(t_stack **a);
void ft_rb(t_stack **b);
void ft_rra(t_stack **a);
void ft_rrb(t_stack **b);
void ft_rrr(t_stack **a, t_stack **b);
void ft_pa(t_stack **stack1, t_stack **stack2);
void ft_pb(t_stack **stack1, t_stack **stack2);
int check_duplicate(t_stack *stack_a);
bool check_sorted(t_stack *stack_a);
t_stack *find_min(t_stack *stack_a);
t_stack *find_max(t_stack *stack_a);
void	ft_stackadd_front(t_stack **lst, t_stack **new);
t_stack *ft_stacklast(t_stack *stack);
int	atoi2(const char *str);
char	**ft_split(char const *s, char c);
void ft_error(int error_status);
void ft_free(t_stack **stack);
void ft_sa(t_stack **stack_a);