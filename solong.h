/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:11:26 by rsebasti          #+#    #+#             */
/*   Updated: 2024/12/01 14:52:50 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include ".minilibx-linux/mlx.h"

# define IMG_SIZE 32

typedef struct s_point
{
	int		x;			
	int		y;
}	t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_point	player;
	t_point	exit;
	int		nbcollect;
	int		nbtocollect;
	char	**map;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_size;
	int		endian;
	int		*imgdata;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		nbmove;
	t_img	player_img;
	t_img	exit_img;
	t_img	exitopen_img;
	t_img	collect_img;
	void	*wall_img;
	void	*floor_img;
}	t_game;

typedef enum e_keyhook
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	KEY_LEFT = 97,
	KEY_RIGHT = 100,
	KEY_ESC = 65307
}	t_keyhook;

int		key_hook(int keycode, t_game *game);
void	put_image_with_transparency(t_game *game, char type, int offset_x,
			int offset_y);
void	init_map(t_map *map, char **data);
void	init_game(t_game *game);
int		count_element(char **map, t_point *player, t_point *exit);
char	**createmap(t_list *lst);
t_list	*createlistmap(int fd);
int		checkmap(char **map);
char	**killmap(char **map);
char	*get_next_line(int fd);
void	print_gmap(t_game *game);

#endif