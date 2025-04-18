FLAGS = -Wall -Wextra -Werror

FUNCTIONS = _push_swap.c \
			atoi2.c \
			ft_errors.c \
			ft_free.c \
			stack_utils.c \
			operations.c \
			check_duplicate.c \
			ft_split.c \
			check_sorted.c \
			find_min_and_max.c \
			ft_utils.c \
			sort_three.c \
			binary_radix.c \
			sort_five.c
 
OBJS = _push_swap.o \
		atoi2.o \
		ft_errors.o \
		ft_free.o \
		stack_utils.o \
		operations.o \
		check_duplicate.o \
		ft_split.o \
		check_sorted.o \
		find_min_and_max.o \
		ft_utils.o \
		sort_three.o \
		binary_radix.o \
		sort_five.o

LIB = push_swap.a

NAME = push_swap

.c.o:
	cc $(FLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(LIB) $(OBJS)
	cc $(FLAGS) _push_swap.c push_swap.a -o $(NAME)
clean:
	rm -f $(OBJS)
fclean:
	rm -f $(OBJS) $(LIB) $(NAME)

re: fclean all
