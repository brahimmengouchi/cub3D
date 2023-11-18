
#include "cub3d.h"


float FixAng(float a)
{ 
    while(a > 2 * PI)
        a -= 2 * PI;
    while(a < 0) 
        a += (2 * PI);
    return a;
}

int iswall(t_cub3d *cub,float xx, float yy) 
{
    int x;
    int y;

    x = floor(xx / TZ);
    y = floor(yy / TZ);
    if (xx < 0 || x >= cub->win_w_max || yy < 0 || y >= cub->win_h)
        return 1;
    if(cub->map3[y][x] == 'N')
        return 0;
    if(cub->map3[y][x] == 'E')
        return 0;
    if(cub->map3[y][x] == 'W')
        return 0;
     if(cub->map3[y][x] == 'S')
        return 0;
    return cub->map3[y][x] != '0';
}

int dist(t_cub3d *cub,float x1, float y1)
{
    return (sqrt((x1 - cub->pdx) * (x1 - cub->pdx) + 
        (y1 - cub->pdy ) * (y1 - cub->pdy)));
}

void assign(t_rd *ray, float ran){
    
    ray->ra = ran;    
    ray->down = ran > 0 && ran < PI;
    ray->right = ran < (PI / 2) || ran > (3 * PI) / 2;
    ray->hv = 0;
    ray->whx = 0;
    ray->why = 0;
    ray->ds = INT_MAX;
}

void castverray(t_cub3d *cub, t_rd *ver)
{
    float xt;
    float yt;
        while (ver->whx >= 0 && ver->whx <= cub->win_w_max * TZ && ver->why >= 0 && ver->why <= cub->win_h * TZ) {       
            xt = ver->whx;
        if(!ver->right)
            xt -= 1;
            yt = ver->why;
        if (iswall(cub, xt, yt)) 
		{
            ver->hv = 1;
            ver->ds = dist(cub,ver->whx,ver->why);
            break;
        } else 
		{
            ver->whx += ver->xs;
            ver->why += ver->ys;
        }
    }
}

t_rd    ver(t_cub3d *cub,float ran)
{
    t_rd ver;
    
    assign(&ver,ran);
      ver.xs = TZ;
    if(!ver.right)
        ver.xs *= -1;

    ver.ys = TZ * tan(ran);
    if(!ver.down && ver.ys > 0)
        ver.ys *= -1;
    if(ver.down && ver.ys < 0)
        ver.ys *= -1;

    // whx = cub->pdx - (int)(cub->pdx) % 48;
    ver.whx = floor(cub->pdx / TZ ) * TZ;
    if(ver.right)
        ver.whx += TZ;
    ver.why = cub->pdy + (ver.whx - cub->pdx) * tan(ran);
    castverray(cub,&ver);
    return ver;
    }

void casthorray(t_cub3d *cub, t_rd *hor)
{
    float xt;
    float yt; 
        while (hor->whx >= 0 && hor->whx <= cub->win_w_max * TZ && hor->why >= 0 && hor->why <= cub->win_h * TZ) {
         xt = hor->whx;
         yt = hor->why;
        if(!hor->down)
            yt -= 1;
        if (iswall(cub, xt, yt)) {
            hor->hh = 1;
            // hor.whx = whx;
            // hor.why = why;
            hor->ds = dist(cub,hor->whx,hor->why);
            break;
        } else {
            hor->whx += hor->xs;
            hor->why += hor->ys;
        }
    }
}

t_rd    hor(t_cub3d *cub,float ran)
{
    t_rd hor;

    assign(&hor,ran);
    hor.ys = TZ;
    if(!hor.down)
        hor.ys *= -1;
    hor.xs = TZ / tan(ran);
    if(!hor.right && hor.xs > 0)
        hor.xs *= -1;
    if(hor.right && hor.xs < 0)
        hor.xs *= -1;
    hor.why = floor(cub->pdy / TZ ) * TZ;
    if(hor.down)
        hor.why += TZ;
    hor.whx =  cub->pdx + (hor.why - cub->pdy) / tan(ran);
    casthorray(cub,&hor);
    return hor;
}

void	v_equal_h(int i, t_cub3d *cub, t_rd veri, t_rd hori)
{
	int j;

	if(i > 0)
	{
		j = i - 1;
		if( (cub->ran > PI && cub->ran <= 3 * PI / 2 && cub->rays[j].hv) || 
			(cub->ran > 0 && cub->ran <= PI && cub->rays[j].hv) 
			|| (cub->ran > 3 * PI /2 && cub->rays[j].hh))
			cub->rays[i] = veri;
		else
			cub->rays[i] = hori;
	}
	else
		cub->rays[i] = hori;  
}

void	casting(t_cub3d *cub) 
{
    t_rd veri;
    t_rd hori;
    int i;
    int j;

	i = -1;
	cub->ran = cub->player_dir - (cub->fov / 2);
    cub->rays = malloc(sizeof(t_rd) * WIDTH);
    while(++i < WIDTH) 
	{
        cub->ran = FixAng(cub->ran);
        veri = ver(cub,cub->ran);
        hori = hor(cub,cub->ran);
        if(floor(veri.ds) == floor(hori.ds))
			v_equal_h(i, cub, veri, hori);
        else
        {
            if(floor(veri.ds) <= floor(hori.ds))
                cub->rays[i] = veri;
            else
                cub->rays[i] = hori;
        }
        cub->ran += cub->fov / WIDTH;
    }
}

