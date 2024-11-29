/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:11:10 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/29 10:24:37 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// char	**addrow(char *line, char ***map, int nb)
// {
// 	int		i;
// 	char	**newmap;

// 	newmap = malloc((sizeof(char *) * nb + 1));
// 	if (newmap == NULL)
// 		return (NULL);
// 	i = 0;
// 	if (*map)
// 	{
// 		while ((*map)[i])
// 		{
// 			newmap[i] = ft_strdup((*map)[i]);
// 			i++;
// 		}
// 	}
// 	newmap[i] = line;
// 	if (*map)
// 		free(*map);
// 	*map = newmap;
// 	return (newmap);
// }

int		checkline(char *line, int islimit, int len)
{
	int	i;

	if (islimit == 0)
	{
		if (line[0] == '1' && line[len - 2] == '1')
			return (1);
		else
		{
			ft_printf("Error\nInvalid line\n");
			return (0);
		}
	}
	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '\n')
		{
			ft_printf("Error\nInvalid top or bottom line\n");
			return (0);
		}
		i++;
	}
	return (1);
}

char	**killmap(char **map, char *line, char *next)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	if (next)
		free(next);
	if (line)
		free(line);
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
		if (checkline(line, (nb == 0 || next == NULL), len))
			ft_lstadd_back(&map, ft_lstnew(line));
		else
		{
			ft_lstclear(&map, free);
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
		return(NULL);
	while (lst)
	{
		map[i] = ft_strtrim((const char *)lst->content, "\n");
		lst = lst->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

// int	main(int argc, char **argv)
// {
// 	int	fd;

// 	if (argc != 2)
// 	{
// 		ft_printf("Error\n Invalid argument number \n");
// 		return(0);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	if (fd == -1)
// 	{
// 		ft_printf("Error\n Can't read map");
// 		return (0);
// 	}
// 	return (0);
// }
