/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmengouc <bmengouc@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:00:53 by bmengouc          #+#    #+#             */
/*   Updated: 2023/11/18 06:00:56 by bmengouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_hook(void *param)
{
	t_cub3d	*cub;

	cub = param;
	key_press(cub);
	cub->dx = cub->pdx;
	cub->dx = cub->pdx;
	updateposition(cub);
	checkmoving(cub);
	if (cub->dir != 0 || cub->dx != cub->pdx || cub->pdy != cub->dy)
	{
		drawback(cub);
		free(cub->rays);
		casting(cub);
		wallp(cub);
		cub->dir = 0;
	}
	cub->dir = 0;
}

void	ft_message(void)
{
	perror("ERROR\n");
	exit(1);
}

void	initia(t_cub3d *cub)
{
	cub->dir = 0;
	cub->mlx = mlx_init(WIDTH, HEIGHT, "MYW", true);
	cub->img = mlx_new_image(cub->mlx, WIDTH, HEIGHT);
	if (!cub->img)
	{
		mlx_close_window(cub->mlx);
		puts(mlx_strerror(mlx_errno));
		freepars(cub);
		exit(1);
	}
	cell_floor(cub);
	drawback(cub);
	cub->pdx = (cub->x_p * TZ) + 15;
	cub->pdy = (cub->y_p * TZ) + 15;
	cub->dy = cub->pdy;
	cub->dx = cub->pdx;
}

int	main(int ac, char **av)
{
	t_cub3d	cub;

	if (ac <= 1)
		ft_message();
	check_file_is_valid(av[1]);
	get_map(av[1], &cub);
	if (cub.map)
	{
		if (check_map_valid(&cub, av[1]))
		{
			initia(&cub);
			casting(&cub);
			wallp(&cub);
			mlx_image_to_window(cub.mlx, cub.img, 0, 0);
			mlx_loop_hook(cub.mlx, ft_hook, &cub);
			mlx_loop(cub.mlx);
			mlx_terminate(cub.mlx);
			freeall(&cub);
		}
	}
	return (EXIT_SUCCESS);
}
