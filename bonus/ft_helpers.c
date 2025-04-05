#include "checker.h"

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

int	ft_is_smaller(t_list *node, int i)
{
	int	value;

	value = node->value;
	while (i > 0)
	{
		i--;
		node = node->next;
		if (!node->used)
			return (0);
	}
	if (value < node->value)
		return (1);
	return (0);
}

int	ft_is_sorted(t_list *stack)
{
	t_list	*node;

	node = stack;
	while (node->next != stack)
	{
		if (!ft_is_smaller(node, 1))
			return (0);
		node = node->next;
	}
	return (1);
}

void	ft_rrotate(t_list **a_stack, t_list **b_stack)
{
	ft_rotate(a_stack);
	ft_rotate(b_stack);
}

void	ft_rrrotate(t_list **a_stack, t_list **b_stack)
{
	ft_rev_rotate(a_stack);
	ft_rev_rotate(b_stack);
}
