/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:46:19 by asebbar           #+#    #+#             */
/*   Updated: 2022/10/18 10:35:41 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*sstr;
	int				len;

	i = 0;
	len = ft_strlen(s);
	sstr = (char *)malloc(len + 1);
	if (!(sstr))
		return (0);
	while (s[i])
	{
		sstr[i] = f(i, s[i]);
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}
