#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
typedef struct s_list
{
	int		value;
	int		used;
	struct s_list	*next;
}	t_list;

// ft_utils.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_put_operation(char *s, int sid);
int	ft_isnum(char *num);
void	ft_free_list(char **list);

// ft_list_tools.c
t_list	*ft_create_list(char **arr, int size);
t_list	*ft_find_tail(t_list *n_stack);
void	ft_swap(t_list *node, int sid);
void	ft_sswap(t_list *a_stack, t_list *b_stack);
void	ft_push(t_list **f_stack, t_list **s_stack, int sid);
void	ft_rotate(t_list **stack, int sid);
void	ft_rev_rotate(t_list **stack, int sid);
t_list  *ft_sort_trio(t_list *stack, int sid);

// ft_atoi.c
int	ft_atoi(char *str);
void	ft_swap(t_list *node, int nid);

// ft_sorter.c
t_list	*ft_buble(t_list *a_stack, t_list *b_stack, int size); 
t_list  *ft_short(t_list *a_stack, t_list *b_stack, int a_size);
int	ft_is_smaller(t_list *node, int i);
int	ft_is_bigger(t_list *node, int i);
int	ft_get_len(t_list *stack);

// main.c
void	ft_print_list(t_list *a_stack);

// ft_push_counter.c
int     ft_abc(int a, int b);
int     ft_count_steps(int value, t_list *stack, int size);
int     ft_short_path(t_list **a_stack, t_list **b_stack);
void    ft_n_rotate(t_list **stack, int n, int sid);
int     ft_get_pivot(t_list *stack, int size);

// ft_split.c
char	**ft_split(char *str, char sep);
#endif
