#include "push_swap.h"

int	ft_count_limit_max(int size)
{
	if (size >= 0 && size <= 200)
		return (2);
	if (size > 200 && size <= 1000)
		return (2);
	return (2);
}

int	ft_count_limit_min(int size)
{
	if (size > 0 && size <= 200)
		return (2);
	if (size > 200)
		return (10);
	return (1);
}

int	ft_is_fine(t_list *stack, int pivot, int size)
{
	t_list	*node;
	int	smaller;
	int	limit;

	smaller = 0;
	limit = ft_count_limit_max(size);
	node = stack;
	do
	{
		if (node->value < pivot)
			smaller++;
		node = node->next;
		if (smaller > size / limit)
			return (0);
	}
	while (node != stack && node->used);
	limit = ft_count_limit_min(size);
	if (smaller < size / limit)
		return (0);
	return (1);
}

int	ft_get_pivot(t_list *stack, int size)
{
	int	pivot;
	int	biggest;
	t_list	*head;

	head = stack;
	biggest = INT_MIN;
	pivot = stack->value;
	while (!ft_is_fine(head, pivot, size))
	{
		if (stack->value > biggest)
			biggest = stack->value;
		stack = stack->next;
		pivot = stack->value;
		if (stack == head)
			return (biggest);
	}
	return (pivot);
}
