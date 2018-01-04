/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:08:04 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/22 10:08:31 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coo		new_point(int x, int y, int z)
{
	t_coo	new;

	new.x = x;
	new.y = y;
	new.z = z;
	if (new.y > 0)
		new.col = 1;
	else
		new.col = 0;
	return (new);
}

void		translate_point(int x, int y, int z, t_map *map)
{
	int	i;
	int	k;

	i = 0;
	while (i < map->height)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x += x;
			map->points[i][k].z += z;
			map->points[i][k].y += y;
			k++;
		}
		i++;
	}
}

void		scale_points(t_map *map, int scale_x, int scale_y)
{
	int i;
	int	k;

	i = 0;
	while (i < map->height)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x *= scale_x;
			map->points[i][k].y *= scale_y;
			map->points[i][k].z *= scale_x;
			k++;
		}
		i++;
	}
}
