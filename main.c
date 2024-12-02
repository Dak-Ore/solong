/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:57:05 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/02 10:57:46 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	print_gmap(t_game *game)
{
	int		i;
	int		j;
	void	*img;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '1')
				img = game->wall_img;
			if (game->map.map[i][j] == '0' || game->map.map[i][j] == 'P'
				|| game->map.map[i][j] == 'E' || game->map.map[i][j] == 'C'
				|| game->map.map[i][j] == 'O')
				img = game->floor_img;
			mlx_put_image_to_window(game->mlx, game->win, img, j * IMG_SIZE,
				i * IMG_SIZE);
			if (game->map.map[i][j] == 'P' || game->map.map[i][j] == 'E'
				|| game->map.map[i][j] == 'C' || game->map.map[i][j] == 'O')
				put_image_with_transparency(game, game->map.map[i][j], j, i);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	**map;
	t_list	*lmap;
	int		fd;
	t_game	game;
	t_map	gmap;

	if (argc != 2)
	{
		ft_printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error opening file");
		return (1);
	}
	lmap = createlistmap(fd);
	if (!lmap)
	{
		ft_printf("Error\n Failed to create the list map.\n");
		close(fd);
		return (1);
	}
	map = createmap(lmap);
	if (!map)
	{
		ft_printf("Error\n Failed to create the map.\n");
		close(fd);
		return (1);
	}
	print_map(map);
	if (!checkmap(map))
	{
		ft_printf("Error\n Map validation failed.\n");
		print_map(map);
		killmap(map);
		close(fd);
		return (1);
	}
	ft_printf("Map is valid and playable! Here is your map:\n");
	print_map(map);
	killmap(map);
	close(fd);
	map = createmap(lmap);
	init_map(&gmap, map);
	game.map = gmap;
	init_game(&game);
	ft_lstclear(&lmap, free);
	print_gmap(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, endgame, &game);
	mlx_loop(game.mlx);
	return (0);
}
