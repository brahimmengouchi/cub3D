/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:07:50 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/17 23:07:51 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texture_colors(uint32_t **texture, mlx_texture_t *img)
{
	int	y;
	int	x;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (i < (int)(img->height * img->width * img->bytes_per_pixel))
	{
		texture[x][y++] = ft_pixel(img->pixels[i], 
				img->pixels[i + 1], 
				img->pixels[i + 2], 
				img->pixels[i + 3]);
		i += 4;
		if (y == img->width)
		{
			y = 0;
			x++;
		}
	}
}

uint32_t	**mlxtorgb(t_cub3d *cub, mlx_texture_t *img, uint32_t **texture)
{
	int	i;

	i = 0;
	texture = NULL;
	texture = malloc(sizeof(uint32_t *) * img->height);
	if (!texture)
		return (0);
	while (i < (int)img->height)
	{
		texture[i] = malloc(sizeof(uint32_t) * img->width);
		if (!texture[i])
			return (0);
		i++;
	}
	texture_colors(texture, img);
	return (texture);
}

void	load_texture(t_cub3d *cub)
{
	cub->ea_texture = mlxtorgb(cub, cub->img_texture[0], cub->ea_texture);
	cub->so_texture = mlxtorgb(cub, cub->img_texture[1], cub->so_texture);
	cub->we_texture = mlxtorgb(cub, cub->img_texture[2], cub->we_texture);
	cub->no_texture = mlxtorgb(cub, cub->img_texture[3], cub->no_texture);
}

void	check_load_textures(t_cub3d *cub)
{
	int	i;

	i = 0;
	cub->img_texture = malloc(sizeof(mlx_texture_t *) * 4);
	while (i < 4)
	{
		cub->img_texture[i] = mlx_load_png(cub->dir_path[i]);
		free(cub->dir_path[i]);
		if (!cub->img_texture[i])
			ft_error(cub, "Error\nError loading texture\n");
		i++;
	}
	free(cub->dir_path);
	load_texture(cub);
}

void	putbackground(t_cub3d *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(cub->img, j, i, cub->cell);
			j++;
		}
		i++;
	}
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(cub->img, j, i, cub->floor);
			j++;
		}
		i++;
	}
}
