/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 06:28:28 by bmengouc          #+#    #+#             */
/*   Updated: 2023/10/25 06:28:29 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;
	int		st;

	if (!s1 || !s2)
		return (NULL);
	st = ft_strlen(s1) + ft_strlen(s2);
	join = malloc((st + 1) * sizeof(char));
	if (!join)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		join[j++] = s1[i++];
	i = 0;
	while (s2[i])
		join[j++] = s2[i++];
	join[j] = 0;
	free(s1);
	return (join);
}
