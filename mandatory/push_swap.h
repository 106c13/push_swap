/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:08:01 by haaghaja          #+#    #+#             */
/*   Updated: 2025/01/26 13:03:50 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				used;
	struct s_list	*next;
}	t_list;

// ft_utils.c
void	ft_put_operation(char *s, int sid);
int		ft_isnum(char *num);
int		ft_strcmp(char *s1, char *s2);

// ft_list_utils.c
void	ft_free_list(char **list);
long	ft_abc(long a, long b);
long	ft_abp(long a, long b);
int		ft_list_size(char **list);
int		ft_get_len(t_list *stack);

// ft_list_tools.c
t_list	*ft_create_list(char **arr, int size);
t_list	*ft_find_tail(t_list *n_stack);
t_list	*ft_sort_trio(t_list *stack, int sid);

// ft_commands.c
void	ft_swap(t_list *node, int sid);
void	ft_push(t_list **f_stack, t_list **s_stack, int sid);
void	ft_rotate(t_list **stack, int sid);
void	ft_rev_rotate(t_list **stack, int sid);

// ft_helpers.c
void	ft_fix_stack(t_list **stacki);
void	ft_move_b(t_list **a_stack, t_list **b_stack, int a_size);
int		ft_move_smaller(t_list **a_stack, t_list **b_stack, int pivoti);
int		ft_is_bigger(t_list *node, int i);
int		ft_is_smaller(t_list *node, int i);

// ft_atoi.c
long	ft_atoi(char *str);

// ft_sorter.c
t_list	*ft_large(t_list *a_stack, t_list *b_stack, int size);
t_list	*ft_short(t_list *a_stack, t_list *b_stack, int a_size);
t_list	*ft_middle(t_list *a_stack, t_list *b_stack, int a_size);

// ft_push_counter.c
void	ft_n_rotate(t_list **stack, int n, int sid);
int		ft_move_to_closest(t_list **a_stack, t_list **b_stack);

// ft_median_counter.c
int		ft_get_pivot(t_list *stack, int size);

// ft_split.c
char	**ft_split(char *str, char sep);
#endif
