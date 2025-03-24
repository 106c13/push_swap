/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 13:47:22 by haaghaja          #+#    #+#             */
/*   Updated: 2025/02/20 14:15:19 by haaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_get_line(char **str, char *buffer)
{
	ssize_t	size;
	int		flag;

	flag = 0;
	size = 0;
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	*str = new_str(*str, size);
	if (!(*str))
		return (1);
	flag = ft_gstrjoin(*str, buffer);
	return (flag);
}

int	ft_gstrjoin(char *str1, char *str2)
{
	int	flag;

	flag = 0;
	while (*str1)
		str1++;
	while (*str2 && *str2 != '\n')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	if (*str2 == '\n')
	{
		*str1 = '\n';
		str1++;
		flag = 1;
	}
	*str1 = '\0';
	return (flag);
}

char	*new_str(char *str, ssize_t bytes_read)
{
	ssize_t	len;
	char	*temp;

	len = 0;
	temp = str;
	if (str)
	{
		while (*str)
		{
			len++;
			str++;
		}
	}
	str = malloc((bytes_read + len + 1) * sizeof(char));
	if (str == NULL)
		return (exit_gnl(temp, NULL));
	str[0] = 0;
	if (temp)
		ft_gstrjoin(str, temp);
	free(temp);
	return (str);
}

char	*exit_gnl(char *str, char *buffer)
{
	if (str)
		free(str);
	if (buffer != NULL)
		*buffer = 0;
	return (NULL);
}

void	shift_buffer(char *buffer)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (!buffer)
		return ;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		while (buffer[i] != '\0')
			buffer[j++] = buffer[i++];
		buffer[j] = '\0';
	}
}
