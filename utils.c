/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 22:57:54 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/17 22:57:55 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	ft_pixel(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

uint32_t	rgb_to_hex(char *str)
{
	char	**values;
	int		red;
	int		green;
	int		blue;

	values = ft_split(str, ',');
	red = ft_atoi(values[0]);
	green = ft_atoi(values[1]);
	blue = ft_atoi(values[2]);
	free_map(values);
	free(str);
	return (ft_pixel(red, green, blue, 255));
}

char	*get_value(t_cub3d *cub3d, char *key)
{
	size_t	key_len;
	int		i;
	char	*line;
	int		j;

	key_len = ft_strlen(key);
	i = -1;
	while (cub3d->map[++i])
	{
		j = 0;
		if (ft_strncmp(cub3d->map[i], key, key_len) == 0)
		{
			line = ft_substr(cub3d->map[i], key_len, ft_strlen(cub3d->map[i]));
			while (ft_isspace(line[j]))
				j++;
			free(line);
			line = ft_substr(cub3d->map[i], key_len + j,
					ft_strlen(cub3d->map[i]));
			return (line);
		}
	}
	return (NULL);
}

void	initialization2(t_cub3d *vars)
{
	if (vars->p_dir == 'S')
		vars->player_dir = PI / 2;
	else if (vars->p_dir == 'E')
		vars->player_dir = 0;
	else if (vars->p_dir == 'W')
		vars->player_dir = PI;
	else if (vars->p_dir == 'N')
		vars->player_dir = 3 * PI / 2;
	vars->fov = 60.0 * (PI / 180);
	vars->dir = 0;
	vars->w = false;
	vars->a = false;
	vars->s = false;
	vars->d = false;
	vars->left = false;
	vars->right = false;
}

void	initialization(t_cub3d *vars)
{
	int	y_map;
	int	win_w;

	y_map = -1;
	vars->win_h = get_height(vars->map2);
	win_w = ft_strlen(vars->map2[0]);
	while (++y_map < vars->win_h)
	{
		vars->win_w = ft_strlen(vars->map2[y_map]);
		if (win_w < vars->win_w)
			win_w = vars->win_w;
	}
	vars->win_w_max = win_w;
	vars->dir_path = malloc(sizeof(char *) * 4);
	vars->dir_path[0] = get_value(vars, "EA");
	vars->dir_path[1] = get_value(vars, "SO");
	vars->dir_path[2] = get_value(vars, "WE");
	vars->dir_path[3] = get_value(vars, "NO");
	vars->f_value = get_value(vars, "F");
	vars->c_value = get_value(vars, "C");
}
