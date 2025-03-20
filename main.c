#include "push_swap.h"

int	ft_exit(int errId)
{
	if (errId == 1)
		ft_putstr("Error44\n");
	return (0);
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
	//int	argc;
	//char	*argv[] = {"a.out", "87", "-33", "21", "65", "-72", "5", "-11", "92", "-44", "56", "-17", "3", "-28", "74", "-88", "19", "8", "-66", "41", "53", "-52", "29", "9"};
	t_list	*a_stack;
	t_list	*b_stack;

	//argc = 24;
	if (argc > 1)
	{
		a_stack = ft_create_list(&argv[1], argc - 1);
		b_stack = ft_create_list(NULL, argc - 1);
		if (!a_stack)
		{
			ft_putstr("Error\n");
			return (0);
		}

		//ft_putstr("A stack: ");
		//ft_print_list(a_stack);
		//ft_putchar('\n');
		//ft_putstr("B stack: ");
		//ft_print_list(b_stack);
		//ft_putchar('\n');
		if (argc > 20)
			a_stack = ft_buble(a_stack, b_stack, argc - 1);
		else
			a_stack = ft_short(a_stack, b_stack, argc - 1);
		//ft_putstr("A stack: ");
		//ft_print_list(a_stack);
	}
	//ft_putchar('\n');
	return (0);
}
