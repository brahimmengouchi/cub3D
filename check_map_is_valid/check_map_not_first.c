/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_not_first.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:13:56 by bmengouc          #+#    #+#             */
/*   Updated: 2023/10/23 04:13:59 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' 
		|| c == '\f' || c == '\r');
}

int	ft_isonlyspace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

char	*trim(char *str)
{
	int		i;
	char	*new;

	new = malloc(sizeof(char) * ((int)ft_strlen(str) + 1));
	i = -1;
	while (str[++i])
	{
		if (!ft_isspace(str[i]) && str[i])
			new[i] = str[i];
		else
		{
			new[i] = 0;
			return (new);
		}
	}
	new[i] = 0;
	return (new);
}

int	check_map_not_first(char **map)
{
	int		i;
	char	*line;

	i = -1;
	while (map[++i])
	{
		line = trim(map[i]);
		if (!line[0])
		{
			printf("Error\n");
			return (1);
		}
		if (ft_strcmp("NO", line) != 0 && ft_strcmp("SO", line) != 0
			&& ft_strcmp("WE", line) != 0 && ft_strcmp("EA", line) != 0
			&& ft_strcmp("F", line) != 0 && ft_strcmp("C", line) != 0)
		{
			printf("Error\nError in the map !!\n");
			return (1);
		}
		free(line);
		if (i == 5)
			break ;
	}
	return (0);
}
