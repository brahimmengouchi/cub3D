/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:00:49 by asebbar           #+#    #+#             */
/*   Updated: 2022/10/20 12:40:40 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	l;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i] && i <= len)
	{
		l = 0;
		while (haystack[i + l] == needle[l] && needle[l] && (i + l < len))
			l++;
		if (needle[l] == '\0')
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
