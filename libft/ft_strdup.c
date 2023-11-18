/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:49:41 by asebbar           #+#    #+#             */
/*   Updated: 2022/10/21 12:29:51 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// char	*ft_strdup(const char *s1)
// {
// 	char	*dup;
// 	int		i;

// 	if (!s1)
// 		return (NULL);
// 	i = -1;
// 	dup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
// 	if (!dup)
// 		return (NULL);
// 	while (s1[++i])
// 		dup[i] = s1[i];
// 	dup[i] = 0;
// 	return (dup);
// }

char	*ft_strdup(const char *s1)
{
	int		j;
	int		len;
	char	*dest;

	len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		dest[j] = s1[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
