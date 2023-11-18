/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 00:48:09 by asebbar           #+#    #+#             */
/*   Updated: 2023/05/25 17:21:33 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		l1;
	int		l2;
	char	*str;

	if (!s2)
		return ((char *)(s1));
	if (!s1)
		return ((char *)(s2));
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (l1 + l2) + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, l1 + 1);
	ft_strlcat(str + l1, s2, l2 + 1);
	return (str);
}
