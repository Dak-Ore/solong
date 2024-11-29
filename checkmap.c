/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:18:56 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/29 10:43:19 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	count_element(char **map, t_point *player, t_point *exit)
{
	int	count;
	t_point	pos;

	count = 0;
	pos.y = -1;
	while (map[++pos.y])
	{
		pos.x = -1;
		while (map[pos.y][++pos.x])
		{
			if ((map[pos.y][pos.x] == 'P' && player->x != -1) || (map[pos.y][pos.x] == 'E' && exit->x != -1))
				return (0);
			if (map[pos.y][pos.x] == 'P')
				*player = pos;
			if (map[pos.y][pos.x] == 'E')
				*exit = pos;
			if (map[pos.y][pos.x] == 'C')
				count++;
		}
	}
	return (count);
}

int	printerror(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	return (0);
}
void	findexit(char **map, t_point cur, t_point exit, int *find, int *count)
{
	if (cur.x == exit.x && cur.y == exit.y)
		*find = 1;
	if (map[cur.y][cur.x] == '1' || (*find == 1 && *count == 0)
		|| (*count != 0 && cur.x == exit.x && cur.y == exit .y))
		return ;
	if (map[cur.y][cur.x] == 'C')
		*count = *count - 1;
	map[cur.y][cur.x] = '1';
	findexit(map, (t_point){cur.x - 1, cur.y}, exit, find, count);
	findexit(map, (t_point){cur.x + 1, cur.y}, exit, find, count);
	findexit(map, (t_point){cur.x, cur.y - 1}, exit, find, count);
	findexit(map, (t_point){cur.x, cur.y + 1}, exit, find, count);
}

int	checkexit(char **map, t_point player, t_point exit, int count)
{
	int	find;
	int	tcount;

	find = 0;
	tcount = count;
	ft_printf("%d - %d\n", tcount, find);
	findexit(map, player, exit, &find, &tcount);
	ft_printf("%d - %d\n", tcount, find);
	return (find && tcount == 0);
}

int	checkmap(char **map)
{
	int	count;
	t_point	player;
	t_point	exit;

	player.x = -1;
	exit.x = -1;
	count = count_element(map, &player, &exit);
	if (player.x == -1)
		return (printerror("Error\nInvalid map, incorrect player (P) number"));
	if (exit.x == -1)
		return (printerror("Error\nInvalid map, incorrect exit (E) number"));
	if (count < 1)
		return (printerror("Error\nInvalid map, no collectible (C)"));
	if (!checkexit(map, player, exit, count))
		return (printerror("Error\nMap is not solvable."));
	return (1);
}

