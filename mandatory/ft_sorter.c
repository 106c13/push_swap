#include "push_swap.h"


t_list	*ft_middle(t_list *a_stack, t_list *b_stack, int a_size)
{
	int		pivot;
	int		pivot1;

	pivot = ft_get_pivot(a_stack, a_size / 2);
	pivot1 = ft_get_pivot(a_stack, a_size);
	while (a_size > 0)
	{
		if (a_stack->value > pivot1)
			ft_rotate(&a_stack, 0);
		else
		{
			ft_push(&a_stack, &b_stack, 1);
			if (b_stack->value > pivot)
				ft_rotate(&b_stack, 1);
		}
		a_size--;
	}
	a_size = ft_get_len(a_stack);
	pivot1 = ft_get_pivot(a_stack, a_size);
	while (a_size > 3)
	{
		ft_push(&a_stack, &b_stack, 1);
		if (b_stack->value < pivot1)
			ft_rotate(&b_stack, 1);
		a_size--;
	}
	if (a_size == 3)
		a_stack = ft_sort_trio(a_stack, 0);
	while (b_stack->used)
		ft_move_to_closest(&a_stack, &b_stack);
	ft_fix_stack(&a_stack);
	return (a_stack);
}

t_list	*ft_large(t_list *a_stack, t_list *b_stack, int a_size)
{
	int		pivot;

	while (a_size > 3)
	{
		pivot = ft_get_pivot(a_stack, a_size);
		a_size -= ft_move_smaller(&a_stack, &b_stack, pivot);
	}
	a_stack = ft_sort_trio(a_stack, 0);
	while (b_stack->used)
		ft_move_to_closest(&a_stack, &b_stack);
	ft_fix_stack(&a_stack);
	return (a_stack);
}

t_list	*ft_short(t_list *a_stack, t_list *b_stack, int a_size)
{
	while (a_size > 3)
	{
		if (ft_is_bigger(a_stack, 1))
		{
			if (ft_is_bigger(a_stack, 2))
				ft_rotate(&a_stack, 0);
			else
				ft_swap(a_stack, 0);
		}
		ft_push(&a_stack, &b_stack, 1);
		a_size--;
		if (ft_is_smaller(b_stack, 1))
		{
			if (ft_is_bigger(b_stack, 2))
				ft_swap(b_stack, 1);
			else
				ft_rotate(&b_stack, 1);
		}
	}
	a_stack = ft_sort_trio(a_stack, 0);
	while (b_stack->used)
		ft_move_to_closest(&a_stack, &b_stack);
	ft_fix_stack(&a_stack);
	return (a_stack);
}
