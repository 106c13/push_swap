#include "push_swap.h"

// Use mid, run while loop and find how much is under the mid, this will fix 1 2 3 4 100000 problem

int	ft_abc(int a, int b)
{
	if (a < 0 && b < 0)
		a *= -1;
	a = a - b;
	if (a < 0)
		a *= -1;
	return (a);
}

int	ft_abp(int a, int b, int a_size, int b_size)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (b > b_size / 2)
		b = b_size - b;
	a = a + b;
	return (a);
}

int	ft_count_steps(int value, t_list *stack, int size)
{
	t_list	*head;
	int	steps;
	int	min;
	int	min_step;
	int	min_val;

	steps = 0;
	min = INT_MAX;
	steps = 0;
	head = stack;
	min_val=777;
	do
	{
		if (min > ft_abc(value, stack->value))
		{
			min = ft_abc(value, stack->value);
			min_step = steps;
			min_val = stack->value;
			if (stack->value < value)
				min_step++;
		}
		steps++;
		stack = stack->next;
	}
	while (head != stack && stack->used);
	//printf("\n-- SIZ: %d MS: %d V: %d MV: %d S: %d\n", size, min_step, value, min_val, steps);
	if (size - min_step > min_step)
		return (-1 * min_step);
	return (size - min_step);
}


int	ft_short_path(t_list **a_stack, t_list **b_stack)
{
	int	min_a;
	int	min_b;
	int	ar;
	int	br;
	int	min;
	int	a_size;
	int	b_size;
	t_list	*node;
	
	min_a = INT_MAX;
	min_b = INT_MAX;
	min = INT_MAX;
	node = *b_stack;
	a_size = ft_get_len(*a_stack);
	b_size = ft_get_len(*b_stack);
	br = 0;
	do
	{
		//printf("=== %d\n", node->value);
		ar = ft_count_steps(node->value, *a_stack, a_size);
		if (ft_abp(ar, br, a_size, b_size) < min)
		{
			min = ft_abp(ar, br, a_size, b_size);
			min_a = ar;
			min_b = br;
			if (min == 0)
				break ;
		}
		//printf("\n+++%d %d %d\n", min, ar, br);
		br--;
		node = node->next;
	}
	while (node != *b_stack && node->used);
	if (min_b < 0 && -1 * min_b > b_size / 2)	
		min_b = b_size + min_b;

	//printf("================ A: %d B: %d==============================\n", min_a, min_b);
	ft_n_rotate(a_stack, min_a, 0);
	ft_n_rotate(b_stack, min_b, 1);
	return (1);
}

void	ft_n_rotate(t_list **stack, int n, int sid)
{
	while (n != 0)
	{
		if (n < 0)
		{
			ft_rotate(stack, sid);
			n++;
		}
		else
		{
			ft_rev_rotate(stack, sid);
			n--;
		}
	}
}
