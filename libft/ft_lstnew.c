/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 06:16:43 by asebbar           #+#    #+#             */
/*   Updated: 2023/04/05 23:21:21 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_serie	*ft_lstnew(int content)
{
	t_serie	*nlst;

	nlst = (t_serie *)malloc(sizeof(t_serie));
	if (!nlst)
		return (0);
	nlst->nbr = content;
	nlst->rpos = 0;
	nlst->next = NULL;
	nlst->prev = NULL;
	return (nlst);
}
