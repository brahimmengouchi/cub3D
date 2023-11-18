/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:57:27 by asebbar           #+#    #+#             */
/*   Updated: 2022/10/22 10:25:24 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	l;
	unsigned char	*k;

	i = 0;
	l = (unsigned char)c;
	k = (unsigned char *)s;
	while (i < n)
	{
		if (k[i] == l)
			return (k + i);
		i++;
	}
	return (0);
}
