#include "push_swap.h"

int	ft_get_median(t_list *stack, int n)
{
	t_list	*tmp;
	int	mean;
	int	size;

	mean = 0;
	size = 0;
	tmp = stack;
	do
	{
		n--;
		size++;
		mean += tmp->value;
		tmp = tmp->next;
	} 
	while (tmp != stack && tmp->used && n != 0);
	return (mean / size);
}

int	ft_divide(t_list *stack, int n)
{
	int	smaller;
	int	size;
	t_list	*node;

	smaller = 0;
	node = stack;
	do
	{
		if (node->value < n)
			smaller++;
		size++;
		node = node->next;
	}
	while (node != stack && node->used);
	if (smaller < size / 20)
		return (0);
	if (smaller > size / 10)
		return (2);
	return (1);
}

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
		if (smaller > size/4)
			return (0);
	}
	while (node != stack && node->used);
	if (smaller < size/10 || smaller == 0)
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



int	ft_find_separator(t_list *stack, int size)
{
	int	mid;
	int	prev_mid;
	int	is_good;

	is_good = 0;
	while (!is_good)
	{
		mid = ft_get_median(stack, size);
		is_good = ft_divide(stack, mid);
		if (is_good == 0)
			mid = mid + mid/10;
		else if (is_good == 2)
			mid = mid - mid/10;
	}
	return (mid);
}
