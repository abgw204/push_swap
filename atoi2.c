#include "stack.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	atoi2(const char *str, t_stack **a)
{
	long	res;
	int	sign;

	res = 0;
	sign = 1;
	if (!ft_strcmp(str, "-"))
		if_error_free_and_exit(a);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (!(*str >= '0' && *str <= '9'))
	{
		if (*str == '-')
			sign = -1;
		else if (*str != '+')
			if_error_free_and_exit(a);
		str++;
	}
	while (*str)
    {
        if (!ft_isdigit(*str))
            if_error_free_and_exit(a);
		res = res * 10 + (*str++ - 48);
    }
    if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		if_error_free_and_exit(a);
	return (res * sign);
}