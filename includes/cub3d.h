/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:55:41 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/06 04:56:17 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define FOV 0.66
# define WALKING_SPEED 0.030f
# define TURNSPEED 0.03f

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx-macos/mlx.h"
# include "../src/libft/libft.h"

typedef struct s_vectord
{
	double	x;
	double	y;
}	t_vectord;

typedef struct s_vectori
{
	int		x;
	int		y;
}	t_vectori;

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			keyleft;
	int			keyright;
}	t_keys;

typedef struct s_map
{
	char	**map;
	size_t	x;
	size_t	y;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_textures
{
	int		top;
	int		bot;
	t_data	*xpm[4];
	t_data	*sprite[5];
}	t_textures;

typedef struct s_chararacter
{
	t_vectord	pos;
	t_vectord	dir;
	t_vectord	plane;
	double		angle;
}	t_character;

typedef struct s_draw
{
	int			wall;
	int			color;
	int			lineheight;
	double		step;
	double		texpos;
	double		wallx;
	double		perpwalldist;
	t_vectori	tex;
	t_vectori	drawwall;
}	t_draw;

typedef struct s_raycast
{
	int			hit;
	int			side;
	t_draw		draw;
	t_vectord	pos;
	t_vectord	dir;
	t_vectord	plane;
	t_vectord	raydir;
	t_vectord	deltadist;
	t_vectord	sidedist;
	t_vectori	step;
	t_vectori	map;
}	t_raycast;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_data		*img;
	t_keys		key;
	t_raycast	raycast;
	t_textures	texture;
	t_character	*player;
}	t_cub3d;

int					main(int argc, char **argv);
/*initialize.c*/
int					initialize(t_cub3d *game_init, char **argv);
int					init_keys(t_cub3d *game);
int					initialize_image(t_cub3d *game);
/*create_map.c*/
int					create_map(t_cub3d *game, char *file);
int					loadsprites(int fd, t_cub3d *game);
char				**get_map(t_cub3d *game, int fd);
char				*get_map_text(int fd);
int					fill_mapspaces(char **map, int xlen, int i);
/*importxpm.c*/
int					import_xpm(t_cub3d *game, char *line);
/*map_check.c*/
int					map_check(char **map);
int					player_check(char **map);
/*player_init.c*/
void				player_plane(t_cub3d *game, char c);
void				player_dir(t_cub3d *game, char c);
int					initialize_player(t_cub3d *game);
/*finish.c*/
int					finish(t_cub3d *game);
/*draw_utils.c*/
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
size_t				get_texture_color(t_data *texture, int pixel_x, \
	int pixel_y);
/*draw_main.c*/
void				drawvertical(int x, t_cub3d *game, t_raycast *ray);
/*raycast_utils.c*/
t_raycast			getwalllength(t_cub3d *game, t_raycast *ray);
double				getperpwalldist(t_raycast *ray);
t_raycast			setwall(t_cub3d *game, t_raycast *ray);
/*move_utils.c*/
int					retmove(t_cub3d *game);
void				turn(t_cub3d *game);
void				setpos(t_cub3d *game, double newposx, \
	double newposy, char mod);
void				set_pos2(t_cub3d *game, double newposx, \
	double newposy, char mod);
/*move.c*/
int					move(t_cub3d *game);
int					move_loop(t_cub3d *game);
void				getscreen(t_cub3d *game);
/*keys.c*/
int					key_up(int keycode, t_cub3d *game);
int					key_down(int keycode, t_cub3d *game);
/*raycast_loopstart.c*/
t_raycast			raycastloopstart(t_raycast *ray, int x);
double				dabs(double n);
/*raycast.c*/
t_raycast			raycastloopstart(t_raycast *ray, int x);
void				raycast(t_cub3d *game);
t_raycast			summonray(t_cub3d *game, t_raycast *ray);
#endif