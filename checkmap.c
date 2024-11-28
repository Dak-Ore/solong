/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:18:56 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/28 14:19:29 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	findexit(char **map, t_point cur, t_point exit, int *find)
{
	if (cur.x == exit.x && cur.y == exit.y)
		find[0] = 1;
	if (map[cur.y][cur.x] == '1' || find[0] == 1
		|| (find[1] != find[2] && cur.x == exit.x && cur.y == exit .y))
		return ;
	findexit(map, (t_point){cur.x - 1, cur.y}, exit, find);
	findexit(map, (t_point){cur.x + 1, cur.y}, exit, find);
	findexit(map, (t_point){cur.x, cur.y - 1}, exit, find);
	findexit(map, (t_point){cur.x, cur.y + 1}, exit, find);
}

int	checkexit(char **map, t_point player, t_point exit)
{
	int	*find;

	find[0] = 0;
	find[1] = 0;
	find[2] = count_element(map);
	findexit(map, player, exit, find);
	return (find[0]);
}

int	*count_element(char **map)
{
	int	count[3];
	int	x;
	int	y;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				count[0]++;
			if (map[y][x] == 'E')
				count[1]++;
			if (map[y][x] == 'C')
				count[2]++;
			x++;
		}
		y++;
	}
	return (count);
}

int	checkmap(char **map)
{
	int	count[3];

	count = count_element(map);
	if (count[0] != 1)
		return (printerror("Error\n Invalid map, incorrect player (P) number"));
	if (count[1] != 1)
		return (printerror("Error\n Invalid map, incorrect exit (E) number"));
	if (count[0] < 1)
		return (printerror("Error\n Invalid map, no collectible (C)"));
	checkexit(map);
}
