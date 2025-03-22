#include <stdlib.h>
#include "push_swap.h"


int	ft_fill_stack(t_list *stack, char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		stack[i].used = 0;
		if (arr)
		{
			if (!ft_isnum(arr[i]))
				return(0);
			stack[i].value = ft_atoi(arr[i]);
			stack[i].used = 1;
		}
		if (i != 0)
			stack[i - 1].next = &stack[i];
		i++;
		if (i == size)
			stack[i - 1].next = &stack[0];	
	}
	return (1);
}


t_list	*ft_create_list(char **arr, int size)
{
	t_list	*n_stack;
	int	i;

	i = 0;
	n_stack = malloc(sizeof(t_list) * size);
	if (!n_stack)
		return (NULL);
	if (!ft_fill_stack(n_stack, arr, size))
	{
		free(n_stack);
		return (NULL);
	}
	return (n_stack);
}

t_list	*ft_find_tail(t_list *stack)
{
	t_list	*node;
	node = stack->next;
	while (node->next != stack)
	{
		node = node->next;
	}
	return (node);
}

t_list	*ft_sort_trio(t_list *stack, int sid)
{
	int	a;
	int	b;
	int	c;

	a = stack->value;
	b = stack->next->value;
	c = stack->next->next->value;
	if (a > b)
	{
		if (a > c)
			ft_rotate(&stack, sid);
		if (b > c)
			ft_swap(stack, sid);
	}
	else if (b > c)
	{
		ft_rev_rotate(&stack, sid);
		if (a < c)
			ft_swap(stack, sid);
	}
	return (stack);
}
