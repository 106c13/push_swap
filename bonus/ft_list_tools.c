#include "checker.h"

int     ft_check_doubles(char **arr, char *num, int size)
{
        int     i;

        i = 0;
        while (i < size)
        {
                if (ft_strcmp(arr[i], num) == 0)
                        return (0);
                i++;
        }
        return (1);
}

int     ft_fill_stack(t_list *stack, char **arr, int size)
{
        int     i;

        i = 0;
        while (i < size)
        {
                stack[i].used = 0;
                if (arr)
                {
                        if (!ft_check_doubles(&arr[i + 1], arr[i], (size - i - 1)))
                                return (0);
                        if (!ft_isnum(arr[i]))
                                return(0);
                        stack[i].value = ft_atoi(arr[i]);
                        stack[i].used = 1;
                }
                if (i != 0)
                        stack[i - 1].next = &stack[i];
                i++;
                if (i == size)
                        stack[i - 1].next = &stack[0];
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

t_list  *ft_find_tail(t_list *stack)
{
        t_list  *node;
        node = stack->next;
        while (node->next != stack)
        {
                node = node->next;
        }
        return (node);
}
