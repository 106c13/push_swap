#include "checker.h"

int	ft_isnum(char *num)
{
	if (*num == '-')
		num++;
	while (*num)
	{
		if (*num < 48 || *num > 57)
			return (0);
		num++;
	}
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_put_operation(char *s, int sid)
{
	ft_putstr(s);
	if (sid == 0)
		ft_putstr("a\n");
	else
		ft_putstr("b\n");
}

void	ft_free_list(char **list)
{
	char	**tmp;

	tmp = list;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(list);
}
