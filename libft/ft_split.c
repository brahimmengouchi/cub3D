/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:54:26 by asebbar           #+#    #+#             */
/*   Updated: 2023/06/06 18:33:50 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wc(char const *s, char c)
{
	int	q;
	int	w;

	q = 0;
	w = 0;
	while (s[q])
	{
		while (s[q] == c)
			q++;
		if (s[q])
			w++;
		while (s[q] != c && s[q])
			q++;
	}
	return (w);
}

static char	*split_beg(char *dir, char *src, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dir[i] = src[i];
		i++;
	}
	dir[i] = '\0';
	return (dir);
}

char	**ft_split(char const *s, char c)
{
	char	**dst;
	char	*beg;
	int		w;
	int		cnt;

	if (!s)
		return (NULL);
	cnt = wc(s, c);
	dst = (char **)malloc((sizeof(char *) * (cnt + 1)));
	if (!dst)
		return (NULL);
	w = -1;
	while (++w < cnt)
	{
		while (*s++ == c)
			continue ;
		beg = (char *)s - 1;
		while (*s != c && *s)
			s++;
		dst[w] = (char *)malloc(sizeof(char) * (s - beg) + 1);
		dst[w] = split_beg(dst[w], beg, s - beg);
	}
	dst[w] = NULL;
	return (dst);
}
