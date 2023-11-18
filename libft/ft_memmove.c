/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:13:47 by asebbar           #+#    #+#             */
/*   Updated: 2023/05/22 15:29:06 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	l;

	if (!dst && !src)
		return (0);
	l = len - 1;
	if (dst > src)
	{
		while (l >= 0)
		{
			((unsigned char *)dst)[l] = ((unsigned char *)src)[l];
			l--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
