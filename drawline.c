/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 03:08:51 by asebbar           #+#    #+#             */
/*   Updated: 2023/06/12 22:45:02 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	assign_draw(t_cub3d *cub, int *dx int *dy, int i)
{
	*dx = cub->rays[i].whx - cub->pdx;
	*dy = cub->rays[i].why - cub->pdy;
	cub->ady = abs(*dy);
	cub->adx = abs(*dx);
	if (cub->rays[i].whx < cub->pdx)
		cub->ix *= -1;
	if (cub->rays[i].why < cub->pdy)
		cub->iy *= -1;
	// cub->ix = (cub->rays[i].whx < cub->pdx) ? -1 : 1;
	// cub->iy = (cub->rays[i].why < cub->pdy) ? -1 : 1;
	cub->er = cub->adx - cub->ady;
}

void	draw_line(t_cub3d *cub, int i)
{
	int	dx;
	int	dy;

	assign_draw(cub, &dx, &dy, i);
	while(cub->pdx != cub->rays[i].whx || cub->pdy != cub->rays[i].why)
	{
		cub->er1 = 2 * cub->er;
		if(cub->er1 > -cub->ady)
		{
			cub->er -= cub->ady;
			cub->pdx += cub->ix;
		}
		if (cub->er1 < cub->adx)
		{
			cub->er += cub->adx;
			cub->pdy  += cub->iy;
		}
		mlx_put_pixel(cub->img,	cub->pdx, cub->pdx, 0x4bbe4bd9);
	}
}


// int main(void)
// {
// 	t_cord cord;
// 	t_cub3d *cub;

// 	cord.x0 = 10;
// 	cord.x1 = -1;
// 	cord.y0 = -11;
// 	cord.y1 = 1;
// 	draw_line(cub,cord);
// 	return 0;
// }