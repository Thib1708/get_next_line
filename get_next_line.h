/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:11:19 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/16 20:44:01 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include<stdlib.h>
# include<stddef.h>

char	*get_next_line(int fd);
char	*read_buf(char *save, int fd);
char	*ft_line(char *save);
char	*ft_next_line(char *save);
char	*ft_free(char *save, char *buffer);
int		new_line(const char *s);
void	ft_bzero(void *b, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);

#endif
