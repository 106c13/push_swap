#include "checker.h"
#include <stdio.h>

int     ft_list_size(char **list)
{
        int     size;

        size = 0;
        while (*list)
        {
                list++;
                size++;
        }
        return (size);
}

int     ft_is_smaller(t_list *node, int i)
{
        int     value;

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

int	ft_run_command(char *move, t_list **a_stack, t_list **b_stack)
{
	if (ft_strcmp(move, "sa\n") == 0)
	{
		if ((*a_stack)->next->used)
			ft_swap(*a_stack);
		else
			return (0);
	}
	else if (ft_strcmp(move, "sb\n") == 0)
	{
		if ((*b_stack)->next->used)
			ft_swap(*b_stack);
		else
			return (0);
	}
	else if (ft_strcmp(move, "pa\n") == 0)
	{
		if ((*b_stack)->used)
			ft_push(b_stack, a_stack);
		else
			return (0);
	}
	else if (ft_strcmp(move, "pb\n") == 0)
	{
		if ((*a_stack)->used)
			ft_push(a_stack, b_stack);
		else
			return (0);
	}
	else if (ft_strcmp(move, "ra\n") == 0)
	{
		if ((*a_stack)->used)
			ft_rotate(a_stack);
		else
			return (0);
	}
	else if (ft_strcmp(move, "rb\n") == 0)
	{
		if ((*b_stack)->used)
			ft_rotate(b_stack);
		else
			return (0);
	}
	else if (ft_strcmp(move, "rra\n") == 0)
	{
		if ((*a_stack)->used)
			ft_rev_rotate(a_stack);
		else
			return (0);
	}
	else if (ft_strcmp(move, "rrb\n") == 0)
	{
		if ((*b_stack)->used)
			ft_rev_rotate(b_stack);
		else
			return (0);
	}
	else
		return (0);
	return (1);
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

int	ft_check(t_list *a_stack, t_list *b_stack)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!ft_run_command(move, &a_stack, &b_stack))
			return (0);
		free(move);
		move = get_next_line(0);
	}
	if (ft_is_sorted(a_stack) && !b_stack->used)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	return (1);
}

int	ft_checker(int argc, char **argv)
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
	if (!ft_check(a_stack, b_stack))
		ft_putstr("Error\n");
	free(a_stack);
	free(b_stack);
	return (1);
}

int     main(int argc, char **argv)
{
        int     allocated;

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
	if (!ft_checker(argc - 1, argv))
		ft_putstr("Error\n");
	if (allocated)
		ft_free_list(argv);
	return (0);	
}
