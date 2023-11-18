/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:14:35 by bmengouc          #+#    #+#             */
/*   Updated: 2023/10/23 04:14:36 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*unknown_element(t_cub3d *vars, char c)
{
	free_map(vars->map3);
	free_map(vars->map2);
	free_map(vars->map);
	printf("Error\nUnknown element %c\n", c);
	exit(1);
}

void	init(t_map_vars *map, int *i)
{
	*i = 1;
	map->n = 0;
	map->s = 0;
	map->w = 0;
	map->e = 0;
}

int	is_equal(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

void	myfunc4(t_cub3d *vars, int i, int j, t_map_vars *map)
{
	if (is_equal(vars->map3[i][j]))
	{
		vars->x_p = j;
		vars->y_p = i;
	}
	if (vars->map3[i][j] == 'N')
		map->n++;
	else if (vars->map3[i][j] == 'S')
		map->s++;
	else if (vars->map3[i][j] == 'E')
		map->e++;
	else if (vars->map3[i][j] == 'W')
		map->w++;
	else if (vars->map3[i][j] != '1' &&
				vars->map3[i][j] != '0' &&
				vars->map3[i][j] != ' ' &&
				vars->map3[i][j] != '\t')
		unknown_element(vars, vars->map3[i][j]);
}

void	check_elements(t_cub3d *vars)
{
	t_map_vars	map;
	int			i;

	init(&map, &i);
	map.y = get_height(vars->map3) - 1;
	while (i < map.y)
	{
		map.x = 0;
		while (vars->map3[i][map.x])
		{
			myfunc4(vars, i, map.x, &map);
			map.x++;
		}
		i++;
	}
	if (map.n + map.s + map.w + map.e == 0)
		ft_error(vars, ft_err_message(&map));
	else if (map.n + map.s + map.w + map.e > 1)
		ft_error(vars, ft_err_message(&map));
}
