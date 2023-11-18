/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:27:00 by asebbar           #+#    #+#             */
/*   Updated: 2022/10/21 18:58:43 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*k;
	unsigned char	*l;

	i = 0;
	k = (unsigned char *)s1;
	l = (unsigned char *)s2;
	while (i < n)
	{
		if (k[i] != l[i])
			return (k[i] - l[i]);
		i++;
	}
	return (0);
}
