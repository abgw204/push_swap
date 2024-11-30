#include "stack.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	atoi2(const char *str, int *error)
{
	long	res;
	int	sign;

	res = 0;
	sign = 1;
	if (!ft_strcmp(str, "-"))
		*error = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (!(*str >= '0' && *str <= '9'))
	{
		if (*str == '-')
			sign = -1;
		else if (*str != '+')
			*error = 1;
		str++;
	}
	while (*str)
    {
        if (!ft_isdigit(*str))
            *error = 1;
		res = res * 10 + (*str++ - 48);
    }
    if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
		*error = 1;
	return (res * sign);
}