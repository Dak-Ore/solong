/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 13:02:10 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/02 13:13:44 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

t_img	getimg(t_game *game, char type)
{
	if (type == 'P')
		return (game->player_img);
	if (type == 'C')
		return (game->collect_img);
	if (type == 'O')
		return (game->exitopen_img);
	return (game->exit_img);
}

void	put_image_with_transparency(t_game *game, char type, int offset_x,
	int offset_y)
{
	int		x;
	int		y;
	t_img	img;
	int		color;

	y = 0;
	img = getimg(game, type);
	while (y < IMG_SIZE)
	{
		x = 0;
		while (x < IMG_SIZE)
		{
			color = img.imgdata[y * (img.l_size / 4) + x];
			if ((color >> 24 & 0xFF) == 0)
				mlx_pixel_put(game->mlx, game->win, x + (offset_x * 32),
					y + (offset_y * 32), color);
			x++;
		}
		y++;
	}
}

t_img	init_img_data(t_game *game, char *str)
{
	int		img_w;
	int		img_h;
	t_img	myimg;

	img_w = IMG_SIZE;
	img_h = IMG_SIZE;
	myimg.bpp = 0;
	myimg.l_size = 0;
	myimg.endian = 0;
	myimg.img = mlx_xpm_file_to_image(game->mlx, str, &img_w, &img_h);
	myimg.imgdata = (int *)mlx_get_data_addr(myimg.img, &myimg.bpp,
			&myimg.l_size, &myimg.endian);
	return (myimg);
}

void	init_map(t_map *map, char **data)
{
	t_point	player;
	t_point	exit;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (data[y][x])
		x++;
	while (data[y])
		y++;
	map->width = x;
	map->height = y;
	player.x = -1;
	exit.x = -1;
	map->nbtocollect = count_element(data, &player, &exit);
	map->player = player;
	map->exit = exit;
	map->nbcollect = 0;
	map->map = data;
}

void	init_game(t_game *game)
{
	int	img_w;
	int	img_h;

	img_w = IMG_SIZE;
	img_h = IMG_SIZE;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * IMG_SIZE,
			game->map.height * IMG_SIZE, "SoLong");
	game->nbmove = 0;
	game->player_img = init_img_data(game, "textures/player.xpm");
	game->exit_img = init_img_data(game, "textures/exit.xpm");
	game->exitopen_img = init_img_data(game, "textures/exit2.xpm");
	game->collect_img = init_img_data(game, "textures/collect.xpm");
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm",
			&img_w, &img_h);
	game->floor_img = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm",
			&img_w, &img_h);
}
