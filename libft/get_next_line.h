/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 00:44:10 by asebbar           #+#    #+#             */
/*   Updated: 2023/05/25 15:59:21 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

typedef struct tv_list
{
	int		fd;
	char	*ssv;
}			t_lst;

char		*get_next_line(int fd);
t_lst		*checklst(t_lst *lol, int fd);
t_lst		*freelst(t_lst *lst);
int			stlen(const char *s);
char		*join(char *sv, int fd, ssize_t i);
char		*stjoin(char *s1, char const *s2);
t_lst		*ft_lstnews(int content);
char		*getln(char *sv);
char		*afterln(char *left);
int			stchr(const char *s, int c);

#endif
