#include "push_swap.h"

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

int	ft_is_bigger(t_list *node, int i)
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
	if (value > node->value)
		return (1);
	return (0);
}

int	ft_find_biggest(t_list *stack)
{
	t_list	*node;
	int	value;

	value = INT_MIN;
	node = stack;
	do
	{
		if (value < node->value)
			value = node->value;
		node = node->next;
		if (!node->used)
			break ;
	}
	while (node != stack);
	return (value);
}

int	ft_find_smallest(t_list *stack)
{
	t_list	*node;
	int	value;

	value = INT_MAX;
	node = stack;
	do
	{
		if (value > node->value)
			value = node->value;
		node = node->next;
		if (!node->used)
			break ;
	}
	while (node != stack);
	return (value);
}

int	ft_get_len(t_list *stack)
{
	t_list	*tmp;
	int	size;

	size = 0;
	tmp = stack;
	do
	{
		size++;
		tmp = tmp->next;
	} while (tmp != stack && tmp->used);
	return (size);
}

int	ft_get_mean(t_list *stack, int n)
{
	t_list	*tmp;
	int	mean;
	int	size;

	mean = 0;
	size = 0;
	tmp = stack;
	if (n == -1)
		n = ft_get_len(stack);
	do
	{
		n--;
		size++;
		mean += tmp->value;
		tmp = tmp->next;
	} 
	while (tmp != stack && tmp->used && n > 0);
	return (mean / size);
}


int	ft_push_b_smaller(t_list **a_stack, t_list **b_stack, int pivot)
{
	int	a_size;
	int	size;
	int	moves;

	a_size = ft_get_len(*a_stack);
	size = a_size;
	moves = 0;
	while (a_size > 0 && size > 3)
	{
		a_size--;
		if ((*a_stack)->value < pivot)
		{
			ft_push(a_stack, b_stack, 1);
			moves++;
			size--;
		}
		else
			ft_rotate(a_stack, 0);
	}
	return (moves);
}

int	ft_sort_by_len_n(t_list **f_stack, t_list **s_stack, int mid, int sid, int n)
{
	int	f_size;
	int	moves;

	f_size = ft_get_len(*f_stack);
	moves = 0;
	while (f_size > 0 && 0 < n)
	{
		f_size--;
		n--;
		if ((*f_stack)->value < mid && sid == 0)
		{
			ft_push(f_stack, s_stack, sid? 0 : 1);
			moves++;
		}
		else if ((*f_stack)->value > mid && sid == 1)
		{
			ft_push(f_stack, s_stack, sid? 0 : 1);
			moves++;
		}
		else
			ft_rotate(f_stack, sid);
	}
	return (moves);
}

t_list	*ft_buble(t_list *a_stack, t_list *b_stack, int a_size)
{
	int	i;
	int	b_size;
	int	pivot;
	int	min;
	int	max;
	int	mid;
	int	moves;
	t_list	*tmp;


	moves = 0;
	max = ft_find_biggest(a_stack);
	while (a_size > 3)
	{
		pivot = ft_get_pivot(a_stack, a_size);
		moves = ft_push_b_smaller(&a_stack, &b_stack, pivot);
		a_size -= moves;
	}
	a_size = ft_get_len(a_stack);
	b_size = ft_get_len(b_stack);

	a_stack = ft_sort_trio(a_stack, 0);

	//return (a_stack);
	/*
		if (ft_is_smaller(b_stack, 1))
		{
				if (ft_is_bigger(b_stack, 2))
					ft_swap(b_stack, 1);
				else
					ft_rotate(&b_stack, 1);
		}
		if (a_stack->value == max)
		{
			ft_rotate(&a_stack, 0);
			continue ;
		}
		
		if (ft_is_bigger(a_stack, 1))
		{
			if (ft_is_bigger(a_stack, 2))
			{
				ft_rotate(&a_stack, 0);
				continue ;
			}
			else
				ft_swap(a_stack, 0);
		}*/
		
		/*
		if (b_size < a_size)
		{	
			moves = ft_count_moves_(a_stack->value, b_stack);		
			if (moves < 0)
			{
				while (moves < 0)
				{
					ft_rotate(&b_stack, 1);
					moves++;
				}
			}
			else
			{	
				while (moves > 0)
				{
					ft_rev_rotate(&b_stack, 1);
					moves--;
				}
			}
		}
		ft_push(&a_stack, &b_stack, 1);
		a_size--;
		b_size++;
		if (ft_is_smaller(b_stack, 1))
		{
				if (ft_is_bigger(b_stack, 2))
					ft_swap(b_stack, 1);
				else
					ft_rotate(&b_stack, 1);
		}
		*/
		//ft_putstr("A stack: ");
		//ft_print_list(a_stack);
		//ft_putstr("B stack: ");
		//ft_print_list(b_stack);
	//ft_putstr("======== TRIO =======\n");
	//ft_putstr("======== END ========\n");
	//ft_putstr("A stack: ");
	//ft_print_list(a_stack);
	//ft_putstr("B stack: ");
	//ft_print_list(b_stack);

	
	while (b_stack->used)
	{
		//ft_putstr("============================\n");
		ft_short_path(&a_stack, &b_stack);
		ft_push(&b_stack, &a_stack, 0);
		a_size++;
	}
	
	i = 1;
	tmp = a_stack;
	while (ft_is_smaller(tmp, 1))
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp->next == a_stack)
		return (a_stack);
	if (i > a_size / 2)
	{
		i = a_size - i;
		while (i > 0)
		{
			ft_rev_rotate(&a_stack, 0);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			ft_rotate(&a_stack, 0);
			i--;
		}
	}
	return (a_stack);
}

t_list	*ft_short(t_list *a_stack, t_list *b_stack, int a_size)
{
	return (a_stack);
}

/*
t_list	*ft_short(t_list *a_stack, t_list *b_stack, int a_size)
{
	int	i;
	int	b_size;
	int	moves;
	t_list	*tmp;

	i = ft_find_biggest(a_stack);
	b_size = 0;
	while (a_stack->next->used && a_size > 3)
	{
		if (a_stack->value == i)
		{
			ft_rotate(&a_stack, 0);
			continue ;
		}
		if (ft_is_bigger(a_stack, 1))
		{
			if (ft_is_bigger(a_stack, 2))
				ft_rotate(&a_stack, 0);
			else
				ft_swap(a_stack, 0);
		}
		ft_push(&a_stack, &b_stack, 1);
		a_size--;
		b_size++;
		if (ft_is_smaller(b_stack, 1))
		{
				if (ft_is_bigger(b_stack, 2))
					ft_swap(b_stack, 1);
				else
					ft_rotate(&b_stack, 1);
		}
	}
	if (a_size == 3)
		a_stack = ft_sort_trio(a_stack, 0);
	while (b_stack->used)
	{
		if (ft_is_smaller(b_stack, 1))
		{	
			if (ft_is_bigger(b_stack, 2))
				ft_swap(b_stack, 1);
			else
				ft_rotate(&b_stack, 1);
		}
		moves = ft_count_moves(b_stack->value, a_stack);
		if (moves < 0)
		{
			while (moves < 0)
			{
				ft_rotate(&a_stack, 0);
				moves++;
			}
		}
		else
		{	
			while (moves > 0)
			{
				ft_rev_rotate(&a_stack, 0);
				moves--;
			}
		}
		ft_push(&b_stack, &a_stack, 0);
		a_size++;
		b_size--;
	}
	return (a_stack);
}*/
