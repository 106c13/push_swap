/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:08:01 by haaghaja          #+#    #+#             */
/*   Updated: 2025/03/25 18:41:29 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_doubles(char **arr, char *num, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strcmp(arr[i], num) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_fill_stack(t_list *stack, char **arr, int size)
{
	long	num;

	stack[size - 1].next = &stack[0];
	while (size > 0)
	{
		size--;
		stack[size].used = 0;
		if (arr)
		{
			if (!ft_isnum(arr[size]))
				return (0);
			if (!ft_check_doubles(arr, arr[size], (size)))
				return (0);
			num = ft_atoi(arr[size]);
			if (num > INT_MAX || num < INT_MIN)
				return (0);
			stack[size].value = (int)num;
			stack[size].used = 1;
		}
		if (size != 0)
			stack[size - 1].next = &stack[size];
	}
	return (1);
}

t_list	*ft_create_list(char **arr, int size)
{
	t_list	*n_stack;

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
		if (b > c || a < c)
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
