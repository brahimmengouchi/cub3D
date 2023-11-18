/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:28:52 by asebbar           #+#    #+#             */
/*   Updated: 2023/10/27 08:29:52 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"



void pos(t_cub3d *cub)
{
		if(cub->s)
		{
			cub->dx -= cos(cub->player_dir) * 2 ;
			cub->dy -= sin(cub->player_dir) * 2 ;
		}
		if(cub->d)
		{
			cub->dx -= cos(cub->player_dir - (PI / 2)) * 2;
			cub->dy -= sin(cub->player_dir - (PI / 2)) * 2;
		}
		if(cub->w)
		{
			cub->dx += cos(cub->player_dir) * 2 ;
			cub->dy += sin(cub->player_dir) * 2;
		}
		if(cub->a)
		{
			cub->dx += cos(cub->player_dir - (PI / 2)) * 2;
			cub->dy += sin(cub->player_dir - (PI / 2)) * 2;
		}
}

void freepars(t_cub3d *cub)
{
	free_map(cub->map3);
	free_map(cub->map2);
	free_map(cub->map);
	free(cub->img_texture);
	free(cub->ea_texture);
	free(cub->so_texture);
	free(cub->we_texture);
	free(cub->no_texture);
}
void freeall(t_cub3d* cub)
{
	int i = 0;
	int j = 0;
	int z;
	
	free(cub->rays);
	while(i < 4)
	{
		z = 0;
		while (z < cub->img_texture[i]->height)
		{
			if(i == 0)
				free(cub->ea_texture[z]);
			if(i == 1)
				free(cub->so_texture[z]);
			if(i == 2)
				free(cub->we_texture[z]);
			if(i == 3)
				free(cub->no_texture[z]);
			z++;
		}
		free(cub->img_texture[i]);
		i++;
	}
	freepars(cub);
}

void	updateposition(t_cub3d *cub)
{
	cub->player_dir = FixAng(cub->player_dir);

	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
	{
		freeall(cub);
        mlx_close_window(cub->mlx);
		exit(1);
	}

	if (cub->left) {
        cub->player_dir -= 0.03;
		// cub->turnsign = -1;
		cub->dir = 5;
    }
	if (cub->right) {
        cub->player_dir += 0.03;
		// cub->turnsign = +1;
		cub->dir = 5;
    }
	if (cub->pdx > 0 && cub->pdx < cub->win_w_max * TZ && cub->pdy > 0 && cub->pdy < cub->win_h * TZ) {
		// todo cheki dir wach -1 -2 1 2
		pos(cub);
	}
	}




void	key_press(t_cub3d *cub)
{
	cub->w = mlx_is_key_down(cub->mlx,MLX_KEY_W);
	cub->s = mlx_is_key_down(cub->mlx,MLX_KEY_S);
	cub->a = mlx_is_key_down(cub->mlx,MLX_KEY_A);
	cub->d = mlx_is_key_down(cub->mlx,MLX_KEY_D);
	cub->right = mlx_is_key_down(cub->mlx,MLX_KEY_RIGHT);
	cub->left = mlx_is_key_down(cub->mlx,MLX_KEY_LEFT);
}



void drawrays(t_cub3d *cub)
{
	int i = 0;
	while(i < WIDTH)
	{
		cub->pdx *= M_fac;
		cub->rays[i].whx *= M_fac;
		cub->pdy *= M_fac;
		cub->rays[i].why *= M_fac;
		draw_line(cub, i);
		i++;
	}
}


void checkmoving(t_cub3d *cub) {
    if (cub->dx > 0 && cub->dx < cub->win_w_max * TZ && cub->dy > 0 && cub->dy < cub->win_h * TZ) {
    	int cellx = floor(cub->dx / TZ);
    	int celly = floor(cub->dy / TZ);

    if(cub->map3[(int)floor((cub->dy + 2) / TZ)][(int)floor((cub->dx + 2) / TZ)] != '1' && 
	 cub->map3[(int)floor((cub->dy - 2) / TZ)][(int)floor((cub->dx - 2) / TZ)] != '1' && 
	 cub->map3[(int)floor((cub->dy + 2) / TZ)][(int)floor((cub->dx - 2) / TZ)] != '1' &&
	 cub->map3[(int)floor((cub->dy - 2) / TZ)][(int)floor((cub->dx + 2) / TZ)] != '1' &&
	 cub->map3[celly][cellx] != ' ' )
	{
		if(cub->pdx  != cub->dx || cub->pdy  != cub->dy)
			cub->dir = 5;
		cub->pdx  = cub->dx ;
		cub->pdy  = cub->dy ;
		 
	}else
	{
		cub->dx = cub->pdx;
		cub->dy = cub->pdy;
	}
	}else
	{
		cub->dx = cub->pdx;
		cub->dy = cub->pdy;
	}
}


void ft_hook(void* param)
{
    t_cub3d *cub = param;
	
	key_press(cub);
	cub->dx = cub->pdx;
	cub->dx = cub->pdx;

	updateposition(cub);
	checkmoving(cub);
	if( cub->dir != 0 || cub->dx != cub->pdx || cub->pdy != cub->dy)
	{
		// printf("mooor lfree x  %f  dx %f  y %f dy %f\n",cub->pdx,cub->dx,cub->pdy,cub->dy);
		// putbackground(cub);
		drawback(cub);
		
		free(cub->rays);
		casting(cub);
		wallp(cub);
		drawmap(cub);
		drawrays(cub);
			// drawspace(cub);
			// printf("%2f\n",cub->pdx);
			

			// drawagain(cub);
			// castRays(cub);
			// raycast(cub);
			// rcasting(cub);
			// printf("lol");
			// drawmap(cub);
			// mlx_image_to_window(cub->mlx,cub->cf_img,0,0);
			
			
			
			// printf("lol\n");
			// mlx_image_to_window(cub->mlx,cub->cf_img,0,0);
			

			cub->dir = 0;
	}
	cub->dir = 0;	
}

// void drawspace(t_cub3d *cub)
// {
// 	int i;
// 	int j;
// 	t_draw maze;
	
// 	i = 0;
// 	maze.celh = TZ * M_fac;
// 	maze.celw = TZ * M_fac;
// 	maze.y = 0;
// 	while (i < cub->win_h)
// 	{
// 		j = 0;
// 		maze.x = 0;
// 		while (j < cub->win_w_max)
// 		{
// 			if (cub->map3[i][j] == '0' || cub->map3[i][j] == ' ' || cub->map3[i][j] == '\t' || cub->map3[i][j] == 'N'
// 			|| cub->map3[i][j] == 'S' || cub->map3[i][j] == 'W'
// 			|| cub->map3[i][j] == 'E')
// 				putspace(maze,cub);
				
// 			maze.x += maze.celw;
// 			j++;
// 		}
// 		maze.y += maze.celh;
// 		i++;	
// 	}	
// }

void	ft_message(void)
{
	perror("ERROR\n");
	exit(1);
}

float	torad(float	degree)
{
	return (degree * PI / 180);
}

int main(int ac, char** av)
{
	t_cub3d cub;

	if (ac <= 1)
		ft_message();
	check_file_is_valid(av[1]);
	get_map(av[1], &cub);
	if (cub.map)
	{
		if (check_map_valid(&cub, av[1]))
		{
			cub.dir = 0;
			cub.mlx = mlx_init(WIDTH, HEIGHT, "MYW", true);
			if (!(cub.img = mlx_new_image(cub.mlx, WIDTH, HEIGHT)))
				{
					mlx_close_window(cub.mlx);
					puts(mlx_strerror(mlx_errno));
					exit(1);
				}
			cell_floor(&cub);
			drawback(&cub);
			cub.pdx = (cub.x_p * TZ) + 15;
    		cub.pdy = (cub.y_p * TZ) + 15;
			cub.dy = cub.pdy;
			cub.dx = cub.pdx;
			casting(&cub);
			wallp(&cub);			
			mlx_put_pixel(cub.img,(cub.x_p * TZ + 15) * M_fac,(cub.y_p * TZ + 15) * M_fac,0xaabbcc);
			drawmap(&cub);
			drawrays(&cub);
			mlx_image_to_window(cub.mlx, cub.img, 0, 0);		
			mlx_loop_hook(cub.mlx, ft_hook, &cub);
			mlx_loop(cub.mlx);
			mlx_terminate(cub.mlx);
			freeall(&cub);
		}
	}
	
	return (EXIT_SUCCESS);
}
