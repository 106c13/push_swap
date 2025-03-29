/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:08:01 by haaghaja          #+#    #+#             */
/*   Updated: 2025/01/26 13:03:50 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_is_bigger(t_list *node, int i)
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
	if (value > node->value)
		return (1);
	return (0);
}

int	ft_move_smaller(t_list **a_stack, t_list **b_stack, int pivot)
{
	int	a_size;
	int	size;
	int	moves;

	a_size = ft_get_len(*a_stack);
	size = a_size;
	moves = 0;
	while (a_size > 0 && size > 3)
	{
		a_size--;
		if ((*a_stack)->value < pivot)
		{
			ft_push(a_stack, b_stack, 1);
			moves++;
			size--;
		}
		else
			ft_rotate(a_stack, 0);
	}
	return (moves);
}

void	ft_fix_stack(t_list **stack)
{
	int		i;
	int		size;
	t_list	*tmp;

	i = 1;
	tmp = *stack;
	size = ft_get_len(*stack);
	while (ft_is_smaller(tmp, 1))
	{
		i++;
		tmp = tmp->next;
	}
	if (i < size / 2)
		i = -1 * i;
	else
		i = size - i;
	ft_n_rotate(stack, i, 0);
}

void	ft_move_b(t_list **a_stack, t_list **b_stack, int a_size)
{
	int		pivot;
	int		pivot1;

	pivot = ft_get_pivot(*a_stack, (a_size * 28) / 100);
	pivot1 = ft_get_pivot(*a_stack, a_size);
	while (a_size > 0)
	{
		if ((*a_stack)->value > pivot1)
			ft_rotate(a_stack, 0);
		else
		{
			ft_push(a_stack, b_stack, 1);
			if ((*b_stack)->value < pivot)
				ft_rotate(b_stack, 1);
		}
		a_size--;
	}
}
