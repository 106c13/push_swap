#include "push_swap.h"

static int	ft_abc(int a, int b)
{
	if (a < 0 && b < 0)
		a *= -1;
	a = a - b;
	if (a < 0)
		a *= -1;
	return (a);
}

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
