/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:06:21 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/02 10:16:49 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	endgame(t_game *game)
{
	killmap(game->map.map);
	mlx_destroy_image(game->mlx, game->collect_img.img);
	mlx_destroy_image(game->mlx, game->player_img.img);
	mlx_destroy_image(game->mlx, game->exit_img.img);
	mlx_destroy_image(game->mlx, game->floor_img);
	mlx_destroy_image(game->mlx, game->wall_img);
	mlx_destroy_image(game->mlx, game->exitopen_img.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	move(t_game *game, int keycode)
{
	t_point	pos;

	pos = game->map.player;
	if (keycode == KEY_LEFT && game->map.map[pos.y][pos.x - 1] != '1'
		&& game->map.map[pos.y][pos.x - 1] != 'E')
		pos.x--;
	if (keycode == KEY_RIGHT && game->map.map[pos.y][pos.x + 1] != '1'
		&& game->map.map[pos.y][pos.x + 1] != 'E')
		pos.x++;
	if (keycode == KEY_UP && game->map.map[pos.y - 1][pos.x] != '1'
		&& game->map.map[pos.y - 1][pos.x] != 'E')
		pos.y--;
	if (keycode == KEY_DOWN && game->map.map[pos.y + 1][pos.x] != '1'
		&& game->map.map[pos.y + 1][pos.x] != 'E')
		pos.y++;
	if (game->map.map[pos.y][pos.x] == 'C')
		game->map.nbcollect++;
	if (game->map.nbcollect == game->map.nbtocollect)
		game->map.map[game->map.exit.y][game->map.exit.x] = 'O';
	game->map.map[game->map.player.y][game->map.player.x] = '0';
	if (game->map.map[pos.y][pos.x] == 'O')
		endgame(game);
	game->map.map[pos.y][pos.x] = 'P';
	game->map.player = pos;
	print_gmap(game);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		endgame(game);
	game->nbmove++;
	ft_printf("Nombre de mouvement : %d\n", game->nbmove);
	if (keycode == KEY_LEFT)
		move(game, keycode);
	if (keycode == KEY_RIGHT)
		move(game, keycode);
	if (keycode == KEY_UP)
		move(game, keycode);
	if (keycode == KEY_DOWN)
		move(game, keycode);
	return (0);
}
