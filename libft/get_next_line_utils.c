/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:41:38 by asebbar           #+#    #+#             */
/*   Updated: 2023/04/05 23:20:25 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*ft_lstnews(int content)
{
	t_lst	*nlst;

	nlst = (t_lst *)malloc(sizeof(t_lst));
	if (!nlst)
	{
		free(nlst);
		return (0);
	}
	nlst->fd = content;
	nlst->ssv = NULL;
	return (nlst);
}

int	stlen(const char *s)
{
	int	j;

	j = 0;
	if (!s)
		return (0);
	while (s[j] != '\0')
		j++;
	return (j);
}

t_lst	*freelst(t_lst *lst)
{
	if (lst)
	{
		if (lst->ssv)
			free(lst->ssv);
		free(lst);
	}
	return (NULL);
}

char	*stjoin(char *s1, char const *s2)
{
	int		j;
	char	*str;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (stlen(s1) + stlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	free(s1);
	return (str);
}

int	stchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}
