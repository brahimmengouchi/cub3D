/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:52:51 by asebbar           #+#    #+#             */
/*   Updated: 2022/10/18 09:14:58 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delnt;

	while (*lst)
	{
		delnt = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = delnt;
	}
	*lst = NULL;
}
