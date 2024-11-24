#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct s_stack
{
	int            nbr;
    int            index;
	struct s_stack	*next;
    struct s_stack  *prev;
} t_stack;

int	ft_stacksize(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int nbr);
int check_duplicate(t_stack *stack_a);
bool check_sorted(t_stack *stack_a);
t_stack *find_min(t_stack *stack_a);
t_stack *find_max(t_stack *stack_a);
void	ft_lstadd_front(t_stack **lst, t_stack **new);
int	atoi2(const char *str);
char	**ft_split(char const *s, char c);
void ft_error(int error_status);
void ft_free(t_stack **stack);
void ft_sort(t_stack **stack_a);
void ft_sa(t_stack **stack_a);