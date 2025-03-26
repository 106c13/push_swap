#include "push_swap.h"

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

int	ft_list_size(char **list)
{
	int	size;

	size = 0;
	while (*list)
	{
		list++;
		size++;
	}
	return (size);
}

int	ft_get_len(t_list *stack)
{
	t_list	*tmp;
	int	size;

	size = 0;
	tmp = stack;
	do
	{
		size++;
		tmp = tmp->next;
	} while (tmp != stack && tmp->used);
	return (size);
}
