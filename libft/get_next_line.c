/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:45:48 by asebbar           #+#    #+#             */
/*   Updated: 2023/06/12 22:34:07 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_lst	*checklst(t_lst *lst, int fd)
{
	if (!lst)
		return (ft_lstnews(fd));
	else
	{
		if (lst->fd != fd)
		{
			lst = freelst(lst);
			return (ft_lstnews(fd));
		}
	}
	return (lst);
}

char	*getln(char *sv)
{
	int		i;
	int		j;
	char	*ln;

	j = 0;
	while (sv[j] != '\n' && sv[j])
		j++;
	ln = (char *)malloc(j + 2);
	if (!ln)
		return (NULL);
	i = 0;
	while (sv[i] != '\n' && sv[i])
	{
		ln[i] = sv[i];
		i++;
	}
	if (sv[i] == '\n')
		ln[i++] = '\n';
	ln[i] = '\0';
	return (ln);
}

char	*afterln(char *left)
{
	int		i;
	char	*sv;
	int		k;

	i = 0;
	k = 0;
	while (left[i] != '\n' && left[i])
		i++;
	if (!left[i] || !left[i + 1])
	{
		free(left);
		return (NULL);
	}
	sv = (char *)malloc(stlen(left) - i + 1);
	if (!sv)
		return (NULL);
	while (left[++i])
		sv[k++] = left[i];
	sv[k] = '\0';
	free(left);
	return (sv);
}

char	*join(char *sv, int fd, ssize_t i)
{
	char	bf[BUFFER_SIZE + 1];

	while (i > 0)
	{
		i = read(fd, bf, BUFFER_SIZE);
		if (i == -1)
		{
			if (sv)
				free(sv);
			return (NULL);
		}
		bf[i] = '\0';
		sv = stjoin(sv, bf);
		if (!sv)
			return (NULL);
		if (stchr(bf, '\n'))
			break ;
	}
	if (!sv[0])
	{
		free(sv);
		return (NULL);
	}
	return (sv);
}

char	*get_next_line(int fd)
{
	static t_lst	*ln;
	char			*sv;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (ln)
			ln = freelst(ln);
		return (0);
	}
	ln = checklst(ln, fd);
	sv = ln->ssv;
	sv = join(sv, fd, 1);
	if (!sv)
	{
		return (NULL);
	}
	line = getln(sv);
	ln->ssv = afterln(sv);
	if (!ln->ssv)
		ln = freelst(ln);
	return (line);
}
