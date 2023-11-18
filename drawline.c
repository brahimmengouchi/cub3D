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

void	assign_draw(t_cub3d *cub, int *dx, int *dy)
{
	*dx = cub->a2 - cub->a1;
	*dy = cub->b2 - cub->b1;
	cub->ady = abs(*dy);
	cub->adx = abs(*dx);
	if (cub->a2 < cub->a1)
		cub->ix = -1;
	else
		cub->ix = 1;
	if (cub->b2 < cub->b1)
		cub->iy = -1;
	else
		cub->iy = 1;
	// cub->ix = (cub->rays[i].whx < cub->pdx) ? -1 : 1;
	// cub->iy = (cub->rays[i].why < cub->pdy) ? -1 : 1;
	cub->er = cub->adx - cub->ady;
}

void	draw_line(t_cub3d *cub)
{
	int	dx;
	int	dy;

	assign_draw(cub, &dx, &dy);
	while(cub->a1 != cub->a2 || cub->b1 != cub->b2)
	{
		cub->er1 = 2 * cub->er;
		if(cub->er1 > -cub->ady)
		{
			cub->er -= cub->ady;
			cub->a1 += cub->ix;
		}
		if (cub->er1 < cub->adx)
		{
			cub->er += cub->adx;
			cub->b1  += cub->iy;
		}
		mlx_put_pixel(cub->img,	cub->a1, cub->b1, 0x4bbe4bd9);
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