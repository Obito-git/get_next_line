/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyroshn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:16:56 by amyroshn          #+#    #+#             */
/*   Updated: 2021/12/14 12:26:02 by amyroshn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_felement	*init_elem(int fd)
{
	t_felement	*elem;

	elem = (t_felement *) malloc(sizeof(t_felement));
	if (!elem)
		return (NULL);
	elem->buffer = ft_strdup("");
	if (!elem->buffer)
	{
		free(elem);
		return (NULL);
	}
	elem->line = NULL;
	elem->fd = fd;
	return (elem);
}

int	get_nlpos(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str != NULL && str[length])
		length++;
	return (length);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	if (!src)
		return (NULL);
	dest = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *to, char *from, size_t size)
{
	char	*res;
	size_t	i;
	size_t	to_len;

	res = (char *) malloc(ft_strlen(from) + ft_strlen(to) + 1);
	if (!res || !from || !to)
		return (NULL);
	i = 0;
	to_len = ft_strlen(to);
	while (i < to_len)
	{
		res[i] = to[i];
		i++;
	}
	i = 0;
	while (from[i] && i < size)
	{
		res[to_len + i] = from[i];
		i++;
	}
	res[to_len + i] = 0;
	free(to);
	return (res);
}
