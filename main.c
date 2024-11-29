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

int render_square(d_vars *vars)
{
    int x;
    int y;

    x = 350;
    y = 350;
    mlx_clear_window(vars->mlx, vars->win);
    while(x < 450)
    {
        while(y < 450)
        {
        mlx_pixel_put(vars->mlx, vars->win, x + vars->x, y + vars->y, 0xFFDDFF);
        y++;
    }
    y = 350;
    x++;
    }
    mlx_do_sync(vars->mlx);
    return(1);
}

int	main(int argc, char **argv)
{
	char	**map;
	t_list	*lmap;
	int		fd;

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
		killmap(map, NULL, NULL); // Libère la mémoire en cas d'erreur
		close(fd);
		return (1);
	}
	ft_printf("Map is valid and playable! Here is your map:\n");
	print_map(map);
	killmap(map, NULL, NULL); // Libération de la mémoire après usage
	close(fd);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	return (0);
}
