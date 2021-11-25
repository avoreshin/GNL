/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:14:27 by jlamonic          #+#    #+#             */
/*   Updated: 2021/11/25 22:01:30 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(t_struct *fun)
{
	fun->buffer = malloc(sizeof(char) * BUFFER_SIZE + 1 );
	if (!fun->buffer)
		return (NULL);
	fun->count = read(fun->fd, fun->buffer, BUFFER_SIZE);
	if (fun->count < 1)
		return (NULL);
	fun->buffer[fun->count] = '\0';
	fun->leaks = fun->buffer;
	fun->str = ft_strdup(fun->buffer);
	free(fun->leaks);
	return (fun->str);
}

static char	*ft_unjoin(char **remainer, t_struct *fun)
{
	if (ft_strlen(*remainer) == 0)
	{
		free(*remainer);
		*remainer = NULL;
		return (NULL);
	}
	fun->pointer = ft_strchr(*remainer, '\n');
	if (fun->pointer == 0)
	{
		fun->str = ft_strdup(*remainer);
		free(*remainer);
		*remainer = NULL;
		return (fun->str);
	}
	*fun->pointer = '\0';
	fun->str = ft_strjoin(*remainer, "\n");
	fun->pointer++;
	fun->leaks = *remainer;
	*remainer = ft_strdup(fun->pointer);
	free (fun->leaks);
	return (fun->str);
}

static void	ft_join(char **remainder, t_struct *fun)
{
	while (ft_strchr(*remainder, '\n') == 0)
	{
		fun->str = ft_read(fun);
		fun->leaks = *remainder;
		if (fun->str == 0)
			break ;
		else
			*remainder = ft_strjoin(*remainder, fun->str);
		free(fun->leaks);
		free(fun->str);
	}
}

char	*get_next_line(int fd)
{
	t_struct	fun;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	fun.fd = fd;
	if (remainder == 0)
	{
		remainder = ft_read(&fun);
		if (remainder == 0)
			return (NULL);
	}
	ft_join(&remainder, &fun);
	fun.onestr = ft_unjoin(&remainder, &fun);
	if (!remainder)
		free(fun.buffer);
	return (fun.onestr);
}
