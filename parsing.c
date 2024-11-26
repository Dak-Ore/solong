/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:11:10 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/26 17:02:17 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*addrow(char *line, char ***map, int nb)
{
	int		i;
	char	**newmap;

	newmap = malloc((sizeof(char *) * nb + 1));
	if (newmap == NULL)
		return (NULL);
	i = 0;
	while ((*map)[i])
	{
		newmap[i] = (*map)[i];
		i++;
	}
	newmap[i] = line;
	free(map);
	return (newmap);
}

int		checkline(char *line, int islimit)
{
	int	i;

	i = 0;
	if (islimit == 0)
	{
		if (line[0] && line[ft_strlen])
			return (1);
		else
		{
			ft_printf("Error\n Invalid line\n");
			return (0);
		}
	}
	else
	{
		while (line[i])
		{
			if (line[i] != '1')
			{
				ft_printf("Error\n Invalid top or bottom line\n");
				return (0);
			}
			i++;
		}
	}
}

char	**createmap(int fd)
{
	int		len;
	char	*line;
	int		nb;
	char	*next;
	char	**map;

	nb = 0;
	line = get_next_line(fd);
	len = ft_strlen(line);
	while (line != NULL)
	{
		next = get_next_line(fd);
		if (checkline(line, (nb == 0 || !next)))
			addrow(line, &map,)
		else
			return (NULL);
		nb++;
		line = next;
	}
	return (map);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("Error\n Invalid argument number \n");
		return(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n Can't read map");
		return (0);
	}
	return (0);
}
