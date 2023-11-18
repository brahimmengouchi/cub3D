/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 02:59:44 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/18 02:59:45 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pos(t_cub3d *cub)
{
	if (cub->s)
	{
		cub->dx -= cos(cub->player_dir) * 2;
		cub->dy -= sin(cub->player_dir) * 2;
	}
	if (cub->d)
	{
		cub->dx -= cos(cub->player_dir - (PI / 2)) * 2;
		cub->dy -= sin(cub->player_dir - (PI / 2)) * 2;
	}
	if (cub->w)
	{
		cub->dx += cos(cub->player_dir) * 2;
		cub->dy += sin(cub->player_dir) * 2;
	}
	if (cub->a)
	{
		cub->dx += cos(cub->player_dir - (PI / 2)) * 2;
		cub->dy += sin(cub->player_dir - (PI / 2)) * 2;
	}
}

void	freepars(t_cub3d *cub)
{
	free_map(cub->map3);
	free_map(cub->map2);
	free_map(cub->map);
	free(cub->img_texture);
	free(cub->ea_texture);
	cub->ea_texture = NULL;
	free(cub->so_texture);
	free(cub->we_texture);
	free(cub->no_texture);
}

void	freeall(t_cub3d *cub)
{
	int	i;
	int	z;

	i = 0;
	free(cub->rays);
	while (i < 4)
	{
		z = 0;
		while (z < (int)cub->img_texture[i]->height)
		{
			printf("lol\n");
			if (i == 0)
				free(cub->ea_texture[z]);
			if (i == 1)
				free(cub->so_texture[z]);
			if (i == 2)
				free(cub->we_texture[z]);
			if (i == 3)
				free(cub->no_texture[z]);
			z++;
		}
		mlx_delete_texture(cub->img_texture[i]);
		i++;
	}
	freepars(cub);
}

void	updateposition(t_cub3d *cub)
{
	cub->player_dir = fix_ang(cub->player_dir);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
	{
		freeall(cub);
		mlx_close_window(cub->mlx);
		exit(0);
	}
	if (cub->left)
	{
		cub->player_dir -= 0.03;
		cub->dir = 5;
	}
	if (cub->right)
	{
		cub->player_dir += 0.03;
		cub->dir = 5;
	}
	if (cub->pdx > 0 && cub->pdx < cub->win_w_max * TZ && cub->pdy > 0
		&& cub->pdy < cub->win_h * TZ)
		pos(cub);
}

void	key_press(t_cub3d *cub)
{
	cub->w = mlx_is_key_down(cub->mlx, MLX_KEY_W);
	cub->s = mlx_is_key_down(cub->mlx, MLX_KEY_S);
	cub->a = mlx_is_key_down(cub->mlx, MLX_KEY_A);
	cub->d = mlx_is_key_down(cub->mlx, MLX_KEY_D);
	cub->right = mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT);
	cub->left = mlx_is_key_down(cub->mlx, MLX_KEY_LEFT);
}
