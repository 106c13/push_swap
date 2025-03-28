#include "push_swap.h"

int	ft_count_steps(int value, t_list *node, int size)
{
	long	min;
	int		steps;
	int		min_step;

	steps = 0;
	min = LONG_MAX;
	while (node->used)
	{
		if (min > ft_abc(value, node->value))
		{
			min = ft_abc(value, node->value);
			min_step = steps;
			if (node->value < value)
				min_step++;
		}
		steps++;
		node = node->next;
	}
	if (size - min_step > min_step)
		return (-1 * min_step);
	return (size - min_step);
}

void	ft_count_closest(t_list *a_stack, t_list *b_stack, int *min_a, int *min_b)
{
	t_list	*node;
	int		ar;
	int		br;
	int		a_size;
	int		b_size;

	node = b_stack;
	a_size = ft_get_len(a_stack);
	b_size = ft_get_len(b_stack);
	br = 0;
	while (node->used)
	{
		if (br < 0 && -1 * br > b_size / 2)
			br = b_size + br;
		ar = ft_count_steps(node->value, a_stack, a_size);
		if (ft_abp(ar, br) < ft_abp(*min_a, *min_b))
		{
			*min_a = ar;
			*min_b = br;
			if (ft_abc(*min_a, *min_b) == 0)
				break ;
		}
		br--;
		node = node->next;
	}
}

int	ft_move_to_closest(t_list **a_stack, t_list **b_stack)
{
	int	min_a;
	int	min_b;

	min_a = INT_MAX;
	min_b = INT_MAX;
	ft_count_closest(*a_stack, *b_stack, &min_a, &min_b);
	ft_n_rotate(a_stack, min_a, 0);
	ft_n_rotate(b_stack, min_b, 1);
	ft_push(b_stack, a_stack, 0);
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
