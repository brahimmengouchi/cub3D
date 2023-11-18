/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:55:00 by asebbar           #+#    #+#             */
/*   Updated: 2022/10/20 19:35:47 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	b;
	size_t	a;

	b = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	a = lendst;
	if (dstsize == 0)
		return (lensrc);
	while (src[b] && a < dstsize - 1)
		dst[a++] = src[b++];
	dst[a] = '\0';
	if (dstsize < lendst)
		return (lensrc + dstsize);
	else
		return (lensrc + lendst);
}
