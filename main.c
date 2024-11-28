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

int	main(int argc, char **argv)
{
	char	**map;
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
	map = createmap(fd);
	if (!map)
	{
		ft_printf("Error\n Failed to create the map.\n");
		close(fd);
		return (1);
	}
	print_map(map); // Nouvelle étape : affichage de la carte
	if (!checkmap(map))
	{
		ft_printf("Error\n Map validation failed.\n");
		killmap(map, NULL, NULL); // Libère la mémoire en cas d'erreur
		close(fd);
		return (1);
	}
	ft_printf("Map is valid and playable! Here is your map:\n");

	killmap(map, NULL, NULL); // Libération de la mémoire après usage
	close(fd);
	return (0);
}
