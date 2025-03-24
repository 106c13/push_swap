#include "checker.h"

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
