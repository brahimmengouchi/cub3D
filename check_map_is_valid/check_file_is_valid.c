/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_is_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:11:02 by bmengouc          #+#    #+#             */
/*   Updated: 2023/10/23 04:11:03 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(t_cub3d *vars, char *err)
{
	free_map(vars->map3);
	free_map(vars->map2);
	free_map(vars->map);
	printf("%s", err);
	exit(1);
}

char	*ft_err_message(t_map_vars *map)
{
	if (map->n + map->s + map->w + map->e == 0)
		return ("Error\nError in the map !!\n");
	if (map->n + map->s + map->w + map->e > 1)
		return ("Error\nError in the map !!\n");
	return ("Error\nError in the map !!\n");
}

int	find(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (to_find[i])
	{
		if (to_find[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

void	check_file_is_valid(char *file)
{
	while (*file)
	{
		if (*file == '.')
		{
			if (find(file, ".cub"))
				return ;
		}
		file++;
	}
	printf("Error\nfile is not valid\n");
	exit(1);
}

int	check_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (1);
	}
	return (0);
}
