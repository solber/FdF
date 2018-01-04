/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:08:04 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/22 12:28:15 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_getwidth(char *str)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
		{
			ret++;
			while ((ft_isdigit(str[i]) && str[i])
					|| str[i] == ',' || str[i] == 'x')
				i++;
		}
		else
			i++;
	}
	return (ret);
}

void			ft_map(t_map *map, t_coo ***cloud)
{
	int		y;
	int		x;
	char	**split_line;
	t_coo	**new;

	y = 0;
	map->width = ft_getwidth(map->map[y]);
	new = (t_coo**)malloc(sizeof(t_coo*) * map->height);
	while (y < map->height)
	{
		new[y] = (t_coo*)malloc(sizeof(t_coo) * map->width);
		x = 0;
		split_line = ft_strsplit(map->map[y], ' ');
		while (x < map->width)
		{
			new[y][x] = new_point(x, ft_atoi(split_line[x]), y);
			x++;
		}
		free(split_line);
		y++;
	}
	*cloud = new;
}

t_coo			**ft_mapcopy(t_map *map)
{
	int		l;
	int		c;
	t_coo	**new;

	l = 0;
	new = (t_coo**)malloc(sizeof(t_coo*) * map->height);
	while (l < map->height)
	{
		new[l] = (t_coo*)malloc(sizeof(t_coo) * map->width);
		c = 0;
		while (c < map->width)
		{
			new[l][c] = map->points[l][c];
			c++;
		}
		l++;
	}
	return (new);
}

void			free_map(t_map map)
{
	int		v;

	v = 0;
	while (v < map.height)
	{
		free(map.points[v]);
		v++;
	}
	free(map.points);
	map.points = NULL;
}
