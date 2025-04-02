/* ************************************************************************** */
/*										*/
/*						:::	  ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: haaghaja <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/03/30 14:34:20 by haaghaja		  #+#	#+#			 */
/*   Updated: 2025/03/30 14:55:29 by haaghaja         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				value;
	int				used;
	struct s_list	*next;
}	t_list;

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
void	shift_buffer(char *buffer);	
int		ft_get_line(char **str, char *buffer);
int		ft_strjoin(char *str1, char *str2);
char	*new_str(char *str, ssize_t bytes_read);
char	*exit_gnl(char *str, char *buffer);

// ft_utils.c
void	ft_putstr(char *str);
void	ft_free_list(char **list);
int		ft_isnum(char *num);
int		ft_strcmp(char *s1, char *s2);

// ft_helpers.c
void	ft_rrotate(t_list **a_stack, t_list **b_stack);
void	ft_rrrotate(t_list **a_stack, t_list **b_stack);
int		ft_list_size(char **list);
int		ft_is_smaller(t_list *node, int i);
int		ft_is_sorted(t_list *stack);

// ft_list_tools.c
t_list	*ft_create_list(char **arr, int size);
t_list	*ft_find_tail(t_list *stack);

// ft_commands.c
void	ft_swap(t_list *node);
void	ft_push(t_list **f_stack, t_list **s_stack);
void	ft_rotate(t_list **stack);
void	ft_rev_rotate(t_list **stack);
void	ft_ss(t_list *a_stack, t_list *b_stack);

// ft_atoi.c
long	ft_atoi(char *str);

// ft_split.c
char	**ft_split(char *str, char sep);
#endif
