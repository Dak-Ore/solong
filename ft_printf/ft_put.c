/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:25:05 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/12 09:31:48 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchars(int c)
{
	write(1, &c, 1);
	return (1);
}

int	putstrs(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (putstrs("(null)"));
	while (s[i])
	{
		putchars(s[i]);
		i++;
	}
	return (i);
}

int	putnbrs(int n)
{
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		i += putchars('-');
		nb = -nb;
	}
	if (nb > 9)
		i += putnbrs(nb / 10);
	i += putchars(nb % 10 + 48);
	return (i);
}

int	putunbrs(unsigned int n)
{
	int		i;

	i = 0;
	if (n > 9)
		i += putnbrs(n / 10);
	i += putchars(n % 10 + 48);
	return (i);
}

int	puthexa(unsigned long nb, int ismaj)
{
	char	*hexa;
	int		i;

	i = 0;
	hexa = "0123456789abcdef";
	if (nb > 15)
		i += puthexa(nb / 16, ismaj);
	if (nb % 16 > 9 && ismaj == 1)
		i += putchars(hexa[nb % 16] - 32);
	else
		i += putchars(hexa[nb % 16]);
	return (i);
}
