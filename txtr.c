/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   txtr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:02:07 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/18 00:02:09 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	txtcolorh(t_cub3d *cub, int fromtop, int wsh, int i)
{
	uint32_t	texture;

	if (!((int)cub->rays[i].whx % TZ) && cub->rays[i].right)
	{
		cub->ofy = fromtop * ((float)cub->img_texture[0]->height / wsh);
		texture = cub->ea_texture[(int)cub->ofy][(int)cub->ofx];
	}
	else
	{
		cub->ofy = fromtop * ((float)cub->img_texture[2]->height / wsh);
		texture = cub->we_texture[(int)cub->ofy][(int)cub->ofx];
	}
	return (texture);
}

uint32_t	txtcolorv(t_cub3d *cub, int fromtop, int wsh, int i)
{
	uint32_t	texture;

	if (!((int)cub->rays[i].why % TZ) && !cub->rays[i].down)
	{
		cub->ofy = fromtop * ((float)cub->img_texture[3]->height / wsh);
		texture = cub->no_texture[(int)cub->ofy][(int)cub->ofx];
	}
	else
	{
		cub->ofy = fromtop * ((float)cub->img_texture[1]->height / wsh);
		texture = cub->so_texture[(int)cub->ofy][(int)cub->ofx];
	}
	return (texture);
}

void	drawtexture(t_cub3d *cub, int up, int dw, int wsh)
{
	int			fromtop;
	uint32_t	texture;

	if (cub->rays[cub->i].hv)
		cub->ofx = (int)cub->rays[cub->i].why % TZ;
	else
		cub->ofx = (int)cub->rays[cub->i].whx % TZ;
	while (dw < up)
	{
		fromtop = dw + (wsh / 2) - (HEIGHT / 2);
		if (cub->rays[cub->i].hv)
			texture = txtcolorh(cub, fromtop, wsh, cub->i);
		else
			texture = txtcolorv(cub, fromtop, wsh, cub->i);
		mlx_put_pixel(cub->img, cub->i, dw, texture);
		dw++;
	}
}

void	wallp(t_cub3d *cub)
{
	int	wheight;
	int	uppoint;
	int	downpoint;

	cub->i = 0;
	while (cub->i < WIDTH)
	{
		cub->pds = cub->rays[cub->i].ds * cos(cub->rays[cub->i].ra
				- cub->player_dir);
		cub->dspp = (WIDTH / 2) / tan(cub->fov / 2);
		cub->pwh = (TZ / cub->pds) * cub->dspp;
		wheight = (int)cub->pwh;
		uppoint = (HEIGHT / 2) - (wheight / 2);
		if (uppoint < 0)
			uppoint = 0;
		downpoint = (HEIGHT / 2) + (wheight / 2);
		if (downpoint > HEIGHT)
			downpoint = HEIGHT;
		drawtexture(cub, downpoint, uppoint, wheight);
		cub->i++;
	}
}

void	cell_floor(t_cub3d *cub)
{
	cub->floor = rgb_to_hex(cub->f_value);
	cub->cell = rgb_to_hex(cub->c_value);
}
