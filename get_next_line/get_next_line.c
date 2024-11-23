/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:59:56 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/14 08:45:56 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	replace_buffer(char **buffer, int start)
{
	char	*tbuffer;

	tbuffer = *buffer;
	*buffer = ft_strdup(tbuffer + start + 1);
	free(tbuffer);
}

static int	read_a_line(char **buffer, int fd)
{
	char	*length;
	int		readed;
	char	content[BUFFER_SIZE + 1];

	length = ft_strchr(*buffer);
	readed = 1;
	while (length == NULL && readed > 0)
	{
		readed = read(fd, content, BUFFER_SIZE);
		if (readed == 0)
			break ;
		content[readed] = '\0';
		if (buffer && *buffer)
			*buffer = ft_strjoin(buffer, content);
		else
			*buffer = ft_strdup(content);
		length = ft_strchr(*buffer);
	}
	if (readed == 0)
		length = *buffer + ft_strlen(*buffer) - 1;
	return (length - *buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			length;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	length = read_a_line(&buffer, fd);
	if (length >= 0)
	{
		line = ft_substr(buffer, 0, length + 1);
		replace_buffer(&buffer, length);
	}
	else
	{
		line = NULL;
		if (buffer)
			free(buffer);
		buffer = NULL;
	}
	return (line);
}
