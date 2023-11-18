/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 07:36:10 by asebbar           #+#    #+#             */
/*   Updated: 2023/04/05 23:21:44 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_serie **lst, t_serie *nw)
{
	if (!*lst)
	{
		*lst = nw;
		return ;
	}
	while ((*lst)->prev)
		*lst = (*lst)->prev;
	nw->next = *lst;
	(*lst)->prev = nw;
	*lst = nw;
}
