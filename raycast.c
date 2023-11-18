/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 01:53:12 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/18 01:53:13 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	castverray(t_cub3d *cub, t_rd *ver)
{
	float	xt;
	float	yt;

	while (ver->whx >= 0 && ver->whx <= cub->win_w_max * TZ && ver->why >= 0
		&& ver->why <= cub->win_h * TZ)
	{
		xt = ver->whx;
		if (!ver->right)
			xt -= 1;
		yt = ver->why;
		if (iswall(cub, xt, yt))
		{
			ver->hv = 1;
			ver->ds = dist(cub, ver->whx, ver->why);
			break ;
		}
		else
		{
			ver->whx += ver->xs;
			ver->why += ver->ys;
		}
	}
}

t_rd	ver(t_cub3d *cub, float ran)
{
	t_rd	ver;

	assign(&ver, ran);
	ver.xs = TZ;
	if (!ver.right)
		ver.xs *= -1;
	ver.ys = TZ * tan(ran);
	if (!ver.down && ver.ys > 0)
		ver.ys *= -1;
	if (ver.down && ver.ys < 0)
		ver.ys *= -1;
	ver.whx = floor(cub->pdx / TZ) * TZ;
	if (ver.right)
		ver.whx += TZ;
	ver.why = cub->pdy + (ver.whx - cub->pdx) * tan(ran);
	castverray(cub, &ver);
	return (ver);
}

void	casthorray(t_cub3d *cub, t_rd *hor)
{
	float	xt;
	float	yt;

	while (hor->whx >= 0 && hor->whx <= cub->win_w_max * TZ && hor->why >= 0
		&& hor->why <= cub->win_h * TZ)
	{
		xt = hor->whx;
		yt = hor->why;
		if (!hor->down)
			yt -= 1;
		if (iswall(cub, xt, yt))
		{
			hor->hh = 1;
			hor->ds = dist(cub, hor->whx, hor->why);
			break ;
		}
		else
		{
			hor->whx += hor->xs;
			hor->why += hor->ys;
		}
	}
}

t_rd	hor(t_cub3d *cub, float ran)
{
	t_rd	hor;

	assign(&hor, ran);
	hor.ys = TZ;
	if (!hor.down)
		hor.ys *= -1;
	hor.xs = TZ / tan(ran);
	if (!hor.right && hor.xs > 0)
		hor.xs *= -1;
	if (hor.right && hor.xs < 0)
		hor.xs *= -1;
	hor.why = floor(cub->pdy / TZ) * TZ;
	if (hor.down)
		hor.why += TZ;
	hor.whx = cub->pdx + (hor.why - cub->pdy) / tan(ran);
	casthorray(cub, &hor);
	return (hor);
}

void	casting(t_cub3d *cub)
{
	t_rd	veri;
	t_rd	hori;
	int		i;

	i = -1;
	cub->ran = cub->player_dir - (cub->fov / 2);
	cub->rays = malloc(sizeof(t_rd) * WIDTH);
	while (++i < WIDTH)
	{
		cub->ran = fix_ang(cub->ran);
		veri = ver(cub, cub->ran);
		hori = hor(cub, cub->ran);
		if (floor(veri.ds) == floor(hori.ds))
			v_equal_h(i, cub, veri, hori);
		else
		{
			if (floor(veri.ds) <= floor(hori.ds))
				cub->rays[i] = veri;
			else
				cub->rays[i] = hori;
		}
		cub->ran += cub->fov / WIDTH;
	}
}
