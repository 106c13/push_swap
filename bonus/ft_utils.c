#include "checker.h"


int     ft_strcmp(char *s1, char *s2)
{
        unsigned int    i;  

        i = 0;
        while (s1[i] != '\0' || s2[i] != '\0')
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
                i++;
        }
        return (0);
}

int	ft_isnum(char *num)
{
	if (*num == '-')
		num++;
	if (*num == 0)
		return (0);
	while (*num)
	{
		if (*num < 48 || *num > 57)
			return (0);
		num++;
	}
	return (1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
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
