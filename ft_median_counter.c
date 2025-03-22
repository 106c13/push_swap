#include "push_swap.h"

int	ft_is_fine(t_list *stack, int pivot, int size)
{
	t_list	*node;
	int	smaller;

	smaller = 0;
	node = stack;
	do
	{
		//printf("%d %d %d\n", pivot, node->value, smaller);
		if (node->value < pivot)
			smaller++;
		node = node->next;
		if (smaller > size / 2)
			return (0);
	}
	while (node != stack && node->used);
	if (smaller < size / 4 || smaller == 0)
		return (0);
	return (1);
}

int	ft_get_pivot(t_list *stack, int size)
{
	int	pivot;
	t_list	*head;

	head = stack;
	pivot = stack->value;
	while (!ft_is_fine(head, pivot, size))
	{
		stack = stack->next;
		pivot = stack->value;
		if (stack == head)
			break ;
	}
	return (pivot);
}
