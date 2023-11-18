/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:57:53 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/18 01:57:55 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	fix_ang(float a)
{
	while (a > 2 * PI)
		a -= 2 * PI;
	while (a < 0)
		a += (2 * PI);
	return (a);
}

int	iswall(t_cub3d *cub, float xx, float yy)
{
	int	x;
	int	y;

	x = floor(xx / TZ);
	y = floor(yy / TZ);
	if (xx < 0 || x >= cub->win_w_max || yy < 0 || y >= cub->win_h)
		return (1);
	if (cub->map3[y][x] == 'N')
		return (0);
	if (cub->map3[y][x] == 'E')
		return (0);
	if (cub->map3[y][x] == 'W')
		return (0);
	if (cub->map3[y][x] == 'S')
		return (0);
	return (cub->map3[y][x] != '0');
}

int	dist(t_cub3d *cub, float x1, float y1)
{
	return (sqrt((x1 - cub->pdx) * (x1 - cub->pdx) 
			+ (y1 - cub->pdy) * (y1 - cub->pdy)));
}

void	assign(t_rd *ray, float ran)
{
	ray->ra = ran;
	ray->down = ran > 0 && ran < PI;
	ray->right = ran < (PI / 2) || ran > (3 * PI) / 2;
	ray->hv = 0;
	ray->whx = 0;
	ray->why = 0;
	ray->ds = INT_MAX;
}

void	v_equal_h(int i, t_cub3d *cub, t_rd veri, t_rd hori)
{
	int	j;

	if (i > 0)
	{
		j = i - 1;
		if ((cub->ran > PI && cub->ran <= 3 * PI / 2 && cub->rays[j].hv)
			|| (cub->ran > 0 && cub->ran <= PI && cub->rays[j].hv)
			|| (cub->ran > 3 * PI / 2 && cub->rays[j].hh))
			cub->rays[i] = veri;
		else
			cub->rays[i] = hori;
	}
	else
		cub->rays[i] = hori;
}
