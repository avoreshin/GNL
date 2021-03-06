/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlamonic <jlamonic@student.42.fr> >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:16:22 by jlamonic          #+#    #+#             */
/*   Updated: 2021/11/25 21:57:18 by jlamonic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
/*//# define BUFFER_SIZE 10*/
/*//# endif*/

typedef struct s_struct
{
	char		*str;
	ssize_t		count;
	int			fd;
	char		*buffer;
	char		*onestr;
	char		*leaks;
	char		*pointer;
}				t_struct;

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
//void	*ft_calloc(size_t count, size_t size);
//void	ft_bzero(void *s, size_t n);
//void	*ft_memset(void *b, int c, size_t len);

# endif