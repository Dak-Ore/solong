/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:29:54 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/19 13:05:27 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	listmapcleaner(int fd, t_list *map, char *line, char *next)
{
	char	*toread;

	if (next)
		free(next);
	if (line)
		free(line);
	ft_lstclear(&map, free);
	toread = get_next_line(fd);
	while (toread)
	{
		free(toread);
		toread = get_next_line(fd);
	}
}
