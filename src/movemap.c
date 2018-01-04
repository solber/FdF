/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movemap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:08:04 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/27 13:46:27 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_centremap(t_map *map)
{
	int	i;
	int	k;
	int	offset_x;
	int	offset_y;

	i = 0;
	offset_x = map->points[map->height / 2][map->width / 2].x;
	offset_y = map->points[map->height / 2][map->width / 2].z;
	while (i < map->height)
	{
		k = 0;
		while (k < map->width)
		{
			map->points[i][k].x -= offset_x;
			map->points[i][k].x += WINDOW_WIDTH / 2;
			map->points[i][k].z -= offset_y;
			map->points[i][k].z += WINDOW_HEIGHT / 2;
			k++;
		}
		i++;
	}
}
