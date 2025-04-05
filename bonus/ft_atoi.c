#include "checker.h"

long	ft_atoi(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
