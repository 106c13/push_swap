#include <stdlib.h>
#include "push_swap.h"

t_list	*ft_create_list(char **arr, int size)
{
	t_list	*n_stack;
	int	i;

	i = 0;
	n_stack = malloc(sizeof(t_list) * size);
	if (!n_stack)
		return (NULL);
	while (i < size)
	{
		// Todo: Find more easier way;
		n_stack[i].used = 0;
		if (arr)
		{
			if (!ft_isnum(arr[i]))
				return(NULL);
			n_stack[i].value = ft_atoi(arr[i]);
			n_stack[i].used = 1;
		}
		if (i != 0)
			n_stack[i - 1].next = &n_stack[i];
		i++;
		if (i == size)
			n_stack[i - 1].next = &n_stack[0];	
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

void	ft_swap(t_list *node, int sid)
{
	int	tmp;

	if (node->next == node)
		return ;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
	ft_put_operation("s", sid);
}

// top of the F -> top of the S
void	ft_push(t_list **f_stack, t_list **s_stack, int sid)
{
	t_list	*s_tail;

	s_tail = ft_find_tail(*s_stack);
	s_tail->value = (*f_stack)->value;
	*s_stack = s_tail;
	(*s_stack)->used = 1;
	(*f_stack)->used = 0;
	*f_stack = (*f_stack)->next;
	ft_put_operation("p", sid);
}

void	ft_rotate(t_list **stack, int sid)
{
	t_list	*prev_head;
	t_list	*node;

	prev_head = *stack;
	if (!(*stack)->next->used)
		return ;	
	*stack = (*stack)->next;
	prev_head->used = 0;
	node = *stack;
	while (node->used)
		node = node->next;
	node->used = 1;
	node->value = prev_head->value;
	ft_put_operation("r", sid);
}

void	ft_rev_rotate(t_list **stack, int sid)
{
	t_list	*prev_head;
	t_list	*empty_node;

	prev_head = *stack;
	while ((*stack)->next->used && prev_head != (*stack)->next)
		*stack = (*stack)->next;
	empty_node = *stack;
	while (!empty_node->next->used && empty_node->next != prev_head)
		empty_node = empty_node->next;
	if (empty_node != *stack)
	{
		empty_node->value = (*stack)->value;
		(*stack)->used = 0;
		*stack = empty_node;
		(*stack)->used = 1;
	}		
	ft_put_operation("rr", sid);
}

t_list	*ft_sort_trio(t_list *stack, int sid)
{
	int	a;
	int	b;
	int	c;

	a = stack->value;
	b = stack->next->value;
	c = stack->next->next->value;
	if (a > b && b > c)
	{
		ft_rotate(&stack, sid);
		ft_swap(stack, sid);
	}
	else if (a > b)
	{
		if (a < c)
			ft_swap(stack, sid);
		else
			ft_rotate(&stack, sid);
	}
	else if (b > c)
	{
		ft_rev_rotate(&stack, sid);
		if (a < c)
			ft_swap(stack, sid);
	}
	return (stack);
}
