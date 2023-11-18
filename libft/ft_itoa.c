/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:14:46 by asebbar           #+#    #+#             */
/*   Updated: 2022/10/22 13:14:11 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	nrc(int n)
{
	int				c;
	unsigned int	u;

	c = 1;
	u = -n * (n < 0) + n * (n > 0);
	if (n < 0)
		c += 2;
	else
		c++;
	while (u >= 10)
	{
		u /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int				c;
	unsigned int	s;
	char			*nbr;

	s = n * (n > 0) - n * (n < 0);
	c = nrc(n);
	nbr = (char *)malloc(sizeof(char) * c);
	if (!nbr)
		return (0);
	if (n < 0)
		nbr[0] = '-';
	c--;
	nbr[c] = '\0';
	while (c > 0)
	{
		c--;
		nbr[c] = (s % 10) + 48;
		s /= 10;
		if (n < 0 && c == 1)
			break ;
	}
	return (nbr);
}
