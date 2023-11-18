/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:58:10 by asebbar           #+#    #+#             */
/*   Updated: 2022/10/22 13:09:35 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ishere(char s2, char const *set1)
{
	int	i;

	i = 0;
	while (set1[i])
	{
		if (s2 == set1[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		l;
	int		k;
	char	*str;

	if (!s1 || !set)
		return (0);
	l = 0;
	i = 0;
	k = ft_strlen(s1);
	while (ishere(s1[i], set) && s1[i])
		i++;
	while (ishere(s1[k - 1], set) && k > i)
		k--;
	str = (char *)malloc((k - i) + 1);
	if (!str)
		return (0);
	while (i < k)
		str[l++] = s1[i++];
	str[l] = '\0';
	return (str);
}
