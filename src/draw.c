/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:08:04 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/22 10:08:22 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_instruct(t_map map)
{
	int	col;

	col = 0x00FFFFFF;
	mlx_string_put(map.mlx, map.win, 5, 5, col, "Autor : wnoth");
	mlx_string_put(map.mlx, map.win, 5, 20, col, "V1.0");
}

void		ft_draw_map(t_map map)
{
	int		u;
	int		v;

	v = 0;
	while (v < map.height)
	{
		u = 0;
		while (u < map.width)
		{
			if (v < map.height - 1)
				draw_line(map.points[v][u], map.points[v + 1][u], &map);
			if (u < map.width - 1)
				draw_line(map.points[v][u], map.points[v][u + 1], &map);
			u++;
		}
		v++;
	}
	ft_draw_instruct(map);
}

void		ft_init_map(t_map *map)
{
	t_map mapcpy;

	map->rot_x = 245;
	map->rot_y = 110;
	map->rot_z = -125;
	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	scale_points(&mapcpy, map->scale_x, map->scale_y);
	rotate_x(map->rot_x, &mapcpy);
	rotate_y(map->rot_y, &mapcpy);
	rotate_z(map->rot_z, &mapcpy);
	ft_centremap(&mapcpy);
	ft_draw_map(mapcpy);
	free_map(mapcpy);
}
