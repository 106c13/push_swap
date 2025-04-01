/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:08:01 by haaghaja          #+#    #+#             */
/*   Updated: 2025/03/25 18:38:55 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort(t_list *a_stack, t_list *b_stack, int size)
{
	if (size < 20)
		ft_short(a_stack, b_stack, size);
	else if (size >= 20 && size < 200)
		ft_middle(a_stack, b_stack, size);
	else
		ft_large(a_stack, b_stack, size);
}

int	ft_push_swap(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;

	if (!argv)
		return (0);
	a_stack = ft_create_list(argv, argc);
	if (!a_stack)
		return (0);
	b_stack = ft_create_list(NULL, argc);
	if (!b_stack)
	{
		free(a_stack);
		return (0);
	}
	if (!ft_is_sorted(a_stack))
		ft_sort(a_stack, b_stack, argc);
	free(a_stack);
	free(b_stack);
	return (1);
}

int	main(int argc, char **argv)
{
	int	allocated;

	if (argc == 1)
		return (0);
	allocated = 0;
	argv = &argv[1];
	if (argc == 2)
	{
		argv = ft_split(*argv, ' ');
		if (argv)
		{
			argc = ft_list_size(argv) + 1;
			allocated = 1;
		}
	}
	if (!ft_push_swap(argc - 1, argv))
		write(2, "Error\n", 6);
	if (allocated)
		ft_free_list(argv);
	return (0);
}
