/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:09:49 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/27 14:18:30 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define SCALE 20
# define ANGLE 5
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

typedef struct		s_coo
{
	int	x;
	int	y;
	int	z;
	int	col;
}					t_coo;

typedef struct		s_map
{
	char	**map;
	int		height;
	int		width;
	int		points_num;
	void	*mlx;
	void	*win;
	t_coo	**points;
	int		scale_x;
	int		scale_y;
	float	rot_x;
	float	rot_y;
	float	rot_z;
	int		ori_x;
	int		ori_y;
}					t_map;

t_coo				new_point(int x, int y, int z);
void				scale_points(t_map *map, int scale_x, int scale_y);
void				rotate_x(float angle, t_map *map);
void				rotate_y(float angle, t_map *map);
void				rotate_z(float angle, t_map *map);
t_map				read_map(char *filename);
void				ft_map(t_map *map, t_coo ***cloud);
void				ft_init_map(t_map *mapinfo);
int					ft_argcheck(int argc, char **argv);
void				draw_line(t_coo v1, t_coo v2, t_map *m);
void				ft_movemap(t_map *map, int offset_x, int offset_y);
void				ft_centremap(t_map *map);
void				ft_draw_map(t_map map);
int					key_hook(int keycode, t_map *map);
t_coo				**ft_mapcopy(t_map *map);
void				free_map(t_map map);
void				free_file(t_map map);
int					read_len(char *filename);
int					count_lines(char *filename);

#endif
