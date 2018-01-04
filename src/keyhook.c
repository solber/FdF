/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:08:04 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/22 10:10:57 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_map *map)
{
	t_map	mapcpy;

	mapcpy = *map;
	mapcpy.points = ft_mapcopy(map);
	if (keycode == 53)
	{
		ft_putendl("Exiting AWESOME window !");
		exit(0);
	}
	return (0);
}
