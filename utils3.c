/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:58:50 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/18 02:58:52 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drawrays(t_cub3d *cub)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		cub->a1 = cub->pdx * M_FAC;
		cub->a2 = cub->rays[i].whx * M_FAC;
		cub->b1 = cub->pdy * M_FAC;
		cub->b2 = cub->rays[i].why * M_FAC;
		draw_line(cub);
		i++;
	}
}

void	checkmoving2(t_cub3d *cub, int cx, int cy)
{
	int	j;
	int	i;
	int	k;
	int	l;

	i = floor((cub->dy + 2) / TZ);
	j = floor((cub->dy - 2) / TZ);
	k = floor((cub->dx + 2) / TZ);
	l = floor((cub->dx - 2) / TZ);
	if (cub->map3[i][k] != '1' && cub->map3[j][l] != '1'
		&& cub->map3[i][l] != '1' && cub->map3[j][k] != '1'
		&& cub->map3[cy][cx] != ' ')
	{
		if (cub->pdx != cub->dx || cub->pdy != cub->dy)
			cub->dir = 5;
		cub->pdx = cub->dx;
		cub->pdy = cub->dy;
	}
	else
	{
		cub->dx = cub->pdx;
		cub->dy = cub->pdy;
	}
}

void	checkmoving(t_cub3d *cub)
{
	int	cellx;
	int	celly;

	if (cub->dx > 0 && cub->dx < cub->win_w_max * TZ && cub->dy > 0
		&& cub->dy < cub->win_h * TZ)
	{
		cellx = floor(cub->dx / TZ);
		celly = floor(cub->dy / TZ);
		checkmoving2(cub, cellx, celly);
	}
	else
	{
		cub->dx = cub->pdx;
		cub->dy = cub->pdy;
	}
}
