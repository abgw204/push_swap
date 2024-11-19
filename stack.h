#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_stack
{
	int            nbr;
    int            index;
    int             push_cost;
    bool            above_mediam;
    bool            cheapest;
    struct s_stack  *target_node;
	struct s_stack	*next;
    struct s_stack  *prev;
} t_stack;

int	ft_stacksize(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int nbr);
int check_duplicate(t_stack *stack_a);
bool check_sorted(t_stack *stack_a);
int	atoi2(const char *str);
char	**ft_split(char const *s, char c);
void ft_error(int error_status);
void ft_free(t_stack **stack);
void ft_sort(t_stack **stack_a);
void ft_sa(t_stack **stack_a);