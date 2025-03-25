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

int	ft_exit(int errId, void *ptr)
{
	if (ptr)
		free(ptr);
	if (errId == 1)
		write(2, "Error\n", 6);
	return (0);
}

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

void	ft_print_list(t_list *a_stack)
{
	t_list	*node;

	node = a_stack;
	do
	{
	if (!node->used)
		break ;
	printf("%d ", node->value);
	node = node->next;
	}
	while (node != a_stack);
	printf("\n");
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

	a_stack = ft_create_list(argv, argc);
	if (!a_stack)
		return (0);
	b_stack = ft_create_list(NULL, argc);
	if (!b_stack)
	{
		free(a_stack);
		return (0);
	}
	ft_sort(a_stack, b_stack, argc);
	free(a_stack);
	free(b_stack);
	return (1);
}

int	main(int argc, char **argv)
{
	int	allocated;

	allocated = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		argc = ft_list_size(argv) + 1;
		allocated = 1;
	}
	else
		argv = &argv[1];
	if (argc > 1)
	{
		if (!ft_push_swap(argc - 1, argv))
			write(2, "Error\n", 6);
		if (allocated)
			ft_free_list(argv);
	}
	return (0);
}
