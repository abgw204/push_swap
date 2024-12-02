#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct s_stack
{
	int            nbr;
    int            index;
    bool            have_index;
    bool            is_min;
    bool            is_max;
	struct s_stack	*next;
    struct s_stack  *prev;
} t_stack;

int	ft_stacksize(t_stack *stack);
void	ft_stackadd_back(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int nbr);
void	*ft_calloc(size_t num, size_t size);
void	sort_three(t_stack **a);
void sort_five(t_stack **a, t_stack **b);
void binary_radix(t_stack **a, t_stack **b);
void ft_swap(t_stack **a, char a_b);
void ft_ra(t_stack **a);
void ft_rb(t_stack **b);
void ft_rra(t_stack **a);
void ft_push(t_stack **stack1, t_stack **stack2, char a_b);
int check_duplicate(t_stack *stack_a);
bool check_sorted(t_stack *stack_a);
t_stack *find_min_and_next(t_stack *stack_a);
t_stack *find_min(t_stack *stack_a);
void is_min(t_stack *stack_a);
void is_max(t_stack *stack_a);
t_stack *find_max(t_stack *stack_a);
void	ft_stackadd_front(t_stack **lst, t_stack **new);
t_stack *ft_stacklast(t_stack *stack);
int	atoi2(const char *str, t_stack **a);
char	**ft_split(char const *s, char c);
int ft_strcmp(const char *s1, char *s2);
void ft_free(t_stack **stack);
void ft_free_split(char **argv);
void if_error_free_and_exit(t_stack **a);