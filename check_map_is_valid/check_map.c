/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:15:23 by bmengouc          #+#    #+#             */
/*   Updated: 2023/10/23 04:15:24 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	check_surrounded_by_walls(t_cub3d *vars)
{
	int		i;
	char	*err;
	int		j;
	int		len;
	int		k;

	err = "Error\nError in the map !!\n";
	i = get_height(vars->map3) - 1;
	if (check_line(vars->map3[0]) || check_line(vars->map3[i]))
		ft_error(vars, err);
	j = 1;
	while (j < i)
	{
		k = 0;
		len = ft_strlen(vars->map3[j]) - 1;
		while (ft_isspace(vars->map3[j][k]))
			k++;
		while (ft_isspace(vars->map3[j][len]))
			len--;
		if (vars->map3[j][k] != '1' ||
			vars->map3[j][len] != '1')
			ft_error(vars, err);
		j++;
	}
}

int	ft_strlen_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	copy_map(t_cub3d *vars)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	vars->map3 = malloc(sizeof(char *) * (ft_strlen_array(vars->map2) + 1));
	while (vars->map2[++i])
	{
		vars->map3[i] = malloc(sizeof(char) * (vars->win_w_max + 1));
		j = 0;
		while (vars->map2[i][j])
		{
			if (vars->map2[i][j] == 'N' || vars->map2[i][j] == 'S'
				|| vars->map2[i][j] == 'W' || vars->map2[i][j] == 'E')
				vars->p_dir = vars->map2[i][j];
			vars->map3[i][j] = vars->map2[i][j];
			j++;
		}
		while (j < vars->win_w_max)
			vars->map3[i][j++] = ' ';
		vars->map3[i][j] = 0;
	}
	vars->map3[i] = 0;
}

int	check_map_valid(t_cub3d *vars, char *av)
{
	if (check_map_not_first(vars->map))
	{
		free_map(vars->map);
		return (0);
	}
	if (!check_floor_and_ciel(vars->map))
	{
		free_map(vars->map);
		return (0);
	}
	get_map2(av, vars);
	initialization(vars);
	copy_map(vars);
	initialization2(vars);
	check_surrounded_by_walls(vars);
	check_elements(vars);
	check_path_is_valid(vars);
	check_load_textures(vars);
	return (1);
}
