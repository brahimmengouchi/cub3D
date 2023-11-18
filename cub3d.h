/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebbar <asebbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 08:28:40 by asebbar           #+#    #+#             */
/*   Updated: 2023/10/27 05:59:20 by asebbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include <fcntl.h>
# include "gnl/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include "./MLX42/include/MLX42/MLX42.h"
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define WIDTH 1056
#define HEIGHT 528
#define PI 3.141593
#define TZ 64

#define M_fac 1/8

#define NORTH 'N'
#define SOUTH 'S'
#define EAST 'E'
#define WEST 'W'


typedef struct rd
{

	float	ra;
	float   xs;
    float   ys;
	float	whx;
	float	why;
	float	ds;
	int 	hv;
	int 	hh;
	int		up;
	int		down;
	int		left;
	int		right;

	// char 	*ps;
	// char 	*pn;
	// char 	*pe;
	// char 	*pw;
}			t_rd;


typedef struct s_cub3d
{
    mlx_t*			mlx;
    mlx_image_t* 	img;
	char	**map;
	char	**map2;
	char	**map3;

	int		win_w;
	int		win_w_max;
	int		win_h;
	int		w;
	int		h;
	// int		movement;
	int		x_p;
	int		y_p;
	float   dx;
	float   dy;
	float	pdx;
	float	pdy;
	bool	s;
	bool	a;
	bool	d;
	bool	left;
	bool	right;
	// bool	esc;
	int 	dir;
	float 	player_dir;
	double  fov;
	// int turnsign;
	// float speed;
	// float speedturn;
	float ofx;
	float ofy;
	float pds;
    float dspp;
    float pwh;
	int i;
	// float faco[4];
	uint32_t floor;
	uint32_t cell;

	char	**dir_path;
	char 	*f_value;
	char 	*c_value;

	int		fd;
	char	*line;
	char	*all_lines;
	char 	*tmp;
	t_rd	*rays;

	mlx_texture_t** img_texture;
	uint32_t **ea_texture;
	uint32_t **no_texture;
	uint32_t **so_texture;
	uint32_t **we_texture;
	char p_dir;

	float ran;
	

	int ix;
	int iy;
	float er1;
	float er;
	int ady;
	int adx;


}t_cub3d;



typedef struct s_map_vars
{
	int		c;
	int		p;
	int		x;
	int		y;

	int		n;
	int		s;
	int		w;
	int		e;	

}			t_map_vars;

typedef struct s_draw
{
    int celh;
	int celw;
	int x;
	int y;
}t_draw;


void ddaLine(t_cub3d *cub,int x1, int y1, int x2, int y2);


void	check_elements(t_cub3d *vars);
void	check_path_is_valid(t_cub3d *vars);
int 	check_map_not_first(char **map);
int 	check_floor_and_ciel(char **map);

int		get_height(char **map);
void	ft_error(t_cub3d *vars, char *err);
char	*ft_err_message(t_map_vars *map);
char 	*trim(char *str);
int		ft_strcmp(char *s1, char *s2);
void	free_map(char **map);
int		check_line(char *line);
void 	putbackground(t_cub3d *cub);
void	key_press(t_cub3d *cub);

void	check_file_is_valid(char *file);
void	get_map(char *fmap, t_cub3d *vars);
void	get_map2(char *fmap, t_cub3d *vars);
int		check_map_valid(t_cub3d *vars, char *av);


void	render_map(t_cub3d *vars);
void 	drawmap(t_cub3d *cub);

void	initialization(t_cub3d *vars);
void	initialization2(t_cub3d *vars);

void 	key_hook(mlx_key_data_t keydata, void* param);
void 	castRays(t_cub3d *cub);
void 	drawagain(t_cub3d *cub);
void 	drawspace(t_cub3d *cub);
void	draw_line(t_cub3d *cub, int i);
t_rd 	raycast(t_cub3d *cub,float ran);
float	torad(float	degree);
float 	degree(float *degree);
void 	rcasting(t_cub3d *cub);

int 	ft_isspace(char c);
int 	ft_isonlyspace(char *line);
void	free_map_and_exit(char **map);
char 	*trim(char *str);
char 	*get_value(t_cub3d *cub3d, char *key);
int		check_is_num(char **arr);

void		check_load_textures(t_cub3d *cub);
uint32_t	rgb_to_hex(char *str);
char		*get_value(t_cub3d *cub3d, char *key);
void		cell_floor(t_cub3d *cub);
void	drawmap(t_cub3d *cub);
void	putspace(t_draw maze ,t_cub3d *cub);
void	message_error(void);
float FixAng(float a);
void casting(t_cub3d *cub);
void wallp(t_cub3d *cub);
uint32_t ft_pixel(int r, int g, int b, int a);
void drawback(t_cub3d *cub);

# endif