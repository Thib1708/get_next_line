/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:17:18 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/17 12:03:57 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *save, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(save, buffer);
	free(save);
	return (temp);
}

char	*ft_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_next_line(char *save)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free (save);
		return (NULL);
	}
	next_line = ft_calloc(ft_strlen(save) - i + 1, sizeof(char));
	i++;
	j = 0;
	while (save[i])
	{
		next_line[j] = save[i++];
		j++;
	}
	free(save);
	return (next_line);
}

char	*read_buf(char *save, int fd)
{
	char	*buffer;
	int		size;

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	size = 1;
	while (size && !new_line(save))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size < 0)
		{
			free(save);
			return (NULL);
		}
		buffer[size] = '\0';
		save = ft_free(save, buffer);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*line;
	int			size;

	if (!save[fd])
		save[fd] = calloc(1, sizeof(char));
	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	size = 1;
	save[fd] = read_buf(save[fd], fd);
	if (!save[fd])
		return (NULL);
	line = ft_line(save[fd]);
	save[fd] = ft_next_line(save[fd]);
	return (line);
}
