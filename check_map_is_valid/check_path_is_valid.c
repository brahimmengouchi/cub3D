/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_is_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:16:04 by bmengouc          #+#    #+#             */
/*   Updated: 2023/10/23 04:16:06 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
}

char	**dup_map(t_cub3d *vars)
{
	int		i;
	char	**new;

	new = (char **)malloc(sizeof(char *) * (vars->win_h + 1));
	i = -1;
	while (++i < vars->win_h)
		new[i] = ft_strdup(vars->map3[i]);
	new[i] = NULL;
	return (new);
}

void	flood_fill(char **new, int y, int x, t_cub3d *vars)
{
	if (new[y][x] == 'V' || new[y][x] == '1')
		return ;
	if (x <= 0 || y <= 0 || y >= vars->win_h - 1 
		|| x >= vars->win_w_max || new[y][x] <= 32)
	{
		printf("Error\n");
		printf("Invalid Path\n");
		free_map(new);
		free_map(vars->map3);
		free_map(vars->map2);
		free_map(vars->map);
		exit(1);
	}
	new[y][x] = 'V';
	flood_fill(new, y, x + 1, vars);
	flood_fill(new, y, x - 1, vars);
	flood_fill(new, y - 1, x, vars);
	flood_fill(new, y + 1, x, vars);
}

void	check_path_is_valid(t_cub3d *vars)
{
	char	**new;

	new = dup_map(vars);
	flood_fill(new, vars->y_p, vars->x_p, vars);
	free_map(new);
}

int	check_is_num(char **arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (arr[i][j] < '0' || arr[i][j] > '9')
				return (0);
		}
	}
	return (1);
}
