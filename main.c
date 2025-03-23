#include "push_swap.h"

int	ft_exit(int errId, void *ptr)
{
	if (ptr)
		free(ptr);
	if (errId == 1)
		ft_putstr("Error\n");
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
	t_list *node;


	node = a_stack;
	do
	{
		if (!node->used)
			break ;
		printf("%d ", node->value);
		node = node->next;
	} while (node != a_stack);
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_list	*a_stack;
	t_list	*b_stack;
	int	allocated;

	allocated = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
			return (ft_exit(1, NULL));
		argc = ft_list_size(argv) + 1;
		allocated = 1;
	}
	else
		argv = &argv[1];
	if (argc > 1)
	{
		a_stack = ft_create_list(argv, argc - 1);
		if (!a_stack)
			return (ft_exit(1, NULL));
		b_stack = ft_create_list(NULL, argc - 1);
		if (!b_stack)
			return (ft_exit(1, a_stack));
		if (argc > 20)
			ft_buble(a_stack, b_stack, argc - 1);
		else
			ft_short(a_stack, b_stack, argc - 1);
		if (allocated)
			ft_free_list(argv);
		free(a_stack);
		free(b_stack);
	}
	return (0);
}
