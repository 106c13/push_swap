/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commands.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:27:45 by haaghaja          #+#    #+#             */
/*   Updated: 2025/03/30 14:37:15 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_swap(t_list *node)
{
	int	tmp;

	if (node->next == node)
		return ;
	if (!node->next->used)
		return ;
	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
}

void	ft_ss(t_list *a_stack, t_list *b_stack)
{
	ft_swap(a_stack);
	ft_swap(b_stack);
}

void	ft_push(t_list **f_stack, t_list **s_stack)
{
	t_list	*s_tail;

	s_tail = ft_find_tail(*s_stack);
	s_tail->value = (*f_stack)->value;
	*s_stack = s_tail;
	(*s_stack)->used = 1;
	(*f_stack)->used = 0;
	*f_stack = (*f_stack)->next;
}

void	ft_rotate(t_list **stack)
{
	t_list	*prev_head;
	t_list	*node;

	prev_head = *stack;
	if (!(*stack)->used && !(*stack)->next->used)
		return ;
	*stack = (*stack)->next;
	prev_head->used = 0;
	node = *stack;
	while (node->used)
		node = node->next;
	node->used = 1;
	node->value = prev_head->value;
}

void	ft_rev_rotate(t_list **stack)
{
	t_list	*prev_head;
	t_list	*empty_node;

	prev_head = *stack;
	if (!(*stack)->used)
		return ;
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
}
