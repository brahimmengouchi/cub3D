/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_and_ciel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:12:30 by bmengouc          #+#    #+#             */
/*   Updated: 2023/10/23 04:12:41 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	message_error(void)
{
	printf("ERROR\n");
	exit(1);
}

int	check_is_between(char **arr)
{
	int	i;
	int	num;

	i = -1;
	while (arr[++i])
	{
		num = ft_atoi(arr[i]);
		if (num > 255 || num < 0)
			return (0);
	}
	return (1);
}

int	myfunc2(char *str, int i)
{
	char	*new;
	char	**arr;

	new = ft_substr(str, i, ft_strlen(str));
	arr = ft_split(new, ',');
	i = 0;
	while (arr[i])
		i++;
	if (i != 3 || !check_is_num(arr) || !check_is_between(arr))
	{
		free(new);
		free_map(arr);
		return (0);
	}
	free(new);
	free_map(arr);
	return (1);
}

int	process_line(char *str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	while (str[i] && ft_isspace(str[i]))
		i++;
	j = i;
	count = 0;
	while (str[j])
	{
		if (str[j] == ',')
			count++;
		j++;
	}
	if (count > 2)
		return (0);
	if (!myfunc2(str, i))
		return (0);
	return (1);
}

int	check_floor_and_ciel(char **map)
{
	int		i;
	char	*line;
	int		count;

	count = 0;
	i = -1;
	while (map[++i])
	{
		line = trim(map[i]);
		if (!ft_strcmp("F", line) || !ft_strcmp("C", line))
		{
			if (!process_line(map[i]))
			{
				printf("Error\nError in the map !!\n");
				free(line);
				return (0);
			}
			count++;
		}
		free(line);
		if (count == 2)
			break ;
	}
	return (1);
}
