#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
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
void	ft_put_operation(char *s, int sid);
void	ft_free_list(char **list);
int	ft_isnum(char *num);
int	ft_strcmp(char *s1, char *s2);

// ft_list_tools.c
t_list	*ft_create_list(char **arr, int size);
t_list	*ft_find_tail(t_list *n_stack);
t_list	*ft_sort_trio(t_list *stack, int sid);

// ft_commands.c
void	ft_swap(t_list *node, int sid);
void	ft_push(t_list **f_stack, t_list **s_stack, int sid);
void	ft_rotate(t_list **stack, int sid);
void	ft_rev_rotate(t_list **stack, int sid);

// ft_atoi.c
long	ft_atoi(char *str);

// ft_sorter.c
t_list	*ft_large(t_list *a_stack, t_list *b_stack, int size); 
t_list  *ft_short(t_list *a_stack, t_list *b_stack, int a_size);
t_list	*ft_middle(t_list *a_stack, t_list *b_stack, int a_size);
int	ft_get_len(t_list *stack);

// main.c
void	ft_print_list(t_list *a_stack);

// ft_push_counter.c
int     ft_short_path(t_list **a_stack, t_list **b_stack);
void    ft_n_rotate(t_list **stack, int n, int sid);
int     ft_get_pivot(t_list *stack, int size);

// ft_split.c
char	**ft_split(char *str, char sep);
#endif
