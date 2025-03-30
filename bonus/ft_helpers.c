/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:38:06 by haaghaja          #+#    #+#             */
/*   Updated: 2025/03/30 14:59:19 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_list_size(char **list)
{
	int	size;

	size = 0;
	while (*list)
	{
		list++;
		size++;
	}
	return (size);
}

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

int	ft_is_sorted(t_list *stack)
{
	t_list	*node;

	node = stack;
	while (node->next != stack)
	{
		if (!ft_is_smaller(node, 1))
			return (0);
		node = node->next;
	}
	return (1);
}
