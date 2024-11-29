/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:11:26 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/29 08:56:45 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

typedef struct 	s_point {
    int 		x;			
    int 		y;
}	t_point;

char	**createmap(int fd);
int		checkmap(char **map);
char	**killmap(char **map, char *line, char *next);
char	*get_next_line(int fd);

#endif