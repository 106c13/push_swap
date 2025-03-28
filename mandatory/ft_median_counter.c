/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_counter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:08:01 by haaghaja          #+#    #+#             */
/*   Updated: 2025/03/25 18:41:29 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_limit_min(int size)
{
	if (size > 0 && size <= 200)
		return (2);
	if (size > 200)
		return (8);
	return (1);
}

int	ft_is_fine(t_list *stack, int pivot, int size)
{
	t_list	*node;
	int		smaller;

	smaller = 0;
	node = stack;
	while (node->used)
	{
		if (node->value < pivot)
			smaller++;
		node = node->next;
		if (smaller > size / 2)
			return (0);
		if (node == stack)
			break ;
	}
	if (smaller < size / ft_count_limit_min(size))
		return (0);
	return (1);
}

int	ft_get_pivot(t_list *stack, int size)
{
	int		pivot;
	int		biggest;
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
