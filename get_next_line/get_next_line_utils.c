/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 08:59:53 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/14 08:41:06 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (&s[i]);
	return (NULL);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char **s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(*s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while ((*s1)[i])
	{
		str[i] = (*s1)[i];
		i++;
	}
	free(*s1);
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strdup(char *s)
{
	char	*nstr;
	int		i;

	nstr = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (nstr == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		nstr[i] = s[i];
		i++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	slen;

	slen = ft_strlen(s);
	if (start >= slen)
		len = 0;
	else if (len + start > slen)
		len = slen - start;
	str = malloc(len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
