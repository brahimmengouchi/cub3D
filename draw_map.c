/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:10:57 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/18 02:10:58 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawback(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT / 2)
	{
		while (j < WIDTH)
		{
			mlx_put_pixel(cub->img, j, i, cub->cell);
			j++;
		}
		j = 0;
		i++;
	}
	while (i < HEIGHT)
	{
		while (j < WIDTH)
		{
			mlx_put_pixel(cub->img, j, i, cub->floor);
			j++;
		}
		j = 0;
		i++;
	}
}

void	putcell(t_draw maze, t_cub3d *cub)
{
	int	x;
	int	y;

	y = maze.y;
	while (y < maze.y + maze.celh)
	{
		x = maze.x;
		while (x < maze.x + maze.celw)
		{
			mlx_put_pixel(cub->img, x, y, 0xaabbcc);
			x++;
		}
		y++;
	}
}

void	putspace(t_draw maze, t_cub3d *cub)
{
	int	x;
	int	y;

	y = maze.y;
	while (y < maze.y + maze.celh)
	{
		x = maze.x;
		while (x < maze.x + maze.celw)
		{
			mlx_put_pixel(cub->img, x, y, 0x6a);
			x++;
		}
		y++;
	}
}

void	drawmap2(t_cub3d *cub, t_draw maze, int i, int j)
{
	if (cub->map3[i][j] == '1')
		putcell(maze, cub);
	else if (cub->map3[i][j] == 'N' || cub->map3[i][j] == 'S'
			|| cub->map3[i][j] == 'W' || cub->map3[i][j] == 'E'
			|| cub->map3[i][j] == '0' || cub->map3[i][j] == ' ')
	{
		cub->x_p = j;
		cub->y_p = i;
		putspace(maze, cub);
	}
}

void	drawmap(t_cub3d *cub)
{
	t_draw	maze;
	int		i;
	int		j;

	i = 0;
	j = 0;
	maze.celh = TZ * M_FAC;
	maze.celw = TZ * M_FAC;
	maze.y = 0;
	while (i < cub->win_h)
	{
		j = 0;
		maze.x = 0;
		while (j < cub->win_w_max)
		{
			drawmap2(cub, maze, i, j);
			maze.x += maze.celw;
			j++;
		}
		maze.y += maze.celh;
		i++;
	}
}
