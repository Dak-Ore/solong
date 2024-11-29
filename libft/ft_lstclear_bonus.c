/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 05:53:37 by rsebasti          #+#    #+#             */
/*   Updated: 2024/11/06 06:21:36 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*i;

	if (!lst || !*lst)
		return ;
	i = *lst;
	while (i)
	{
		temp = i->next;
		ft_lstdelone(i, del);
		i = temp;
	}
	*lst = NULL;
}
