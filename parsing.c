/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:11:10 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/02 11:38:35 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	checkcharacter(char *line, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'P'
				|| line[i] == 'C' || line[i] == 'E'))
			return (0);
		i++;
	}
	return (1);
}

int	checkline(char *line, int istop, int isbottom, int len)
{
	int	i;

	if (len != (int) ft_strlen(line) && isbottom == 0)
		return (ft_printf("Error\nInvalid line size\n"),0);
	if (len - 1 != (int) ft_strlen(line) && isbottom == 1)
		return (ft_printf("Error\nInvalid line size\n"),0);
	if (isbottom == 0 && istop == 0)
	{
		if (line[0] == '1' && line[len - 2] == '1' && checkcharacter(line, len))
			return (1);
		else
		{
			ft_printf("Error\nInvalid line\n");
			return (0);
		}
	}
	i = -1;
	while (line[++i] && i < len - 1)
	{
		if (line[i] != '1' && isbottom == 1)
			return (ft_printf("Error\nInvalid bottom line\n"), 0);
		if (line[i] != '1' && istop == 1)
			return (ft_printf("Error\nInvalid top line\n"), 0);
	}
	return (1);
}

char	**killmap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (NULL);
}

t_list	*createlistmap(int fd)
{
	int		len;
	char	*line;
	int		nb;
	char	*next;
	t_list	*map;

	nb = 0;
	line = get_next_line(fd);
	len = ft_strlen(line);
	map = NULL;
	while (line != NULL)
	{
		next = get_next_line(fd);
		if (checkline(line, nb == 0, next == NULL, len))
			ft_lstadd_back(&map, ft_lstnew(line));
		else
		{
			listmapcleaner(fd, map, line, next);
			return (NULL);
		}
		nb++;
		line = next;
	}
	return (map);
}

char	**createmap(t_list *lst)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc (sizeof(char *) * (ft_lstsize(lst) + 1));
	if (!map)
		return (NULL);
	while (lst)
	{
		map[i] = ft_strtrim((const char *)lst->content, "\n");
		lst = lst->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}
