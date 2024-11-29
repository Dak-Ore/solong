/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:29:15 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/17 16:11:07 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	puthexa(unsigned long nb, int ismaj);
int	putunbrs(unsigned int n);
int	putnbrs(int n);
int	putchars(int c);
int	putstrs(char *s);
int	ft_printf(const char *str, ...);

#endif