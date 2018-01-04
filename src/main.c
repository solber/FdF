/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:08:04 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/27 14:19:53 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	read_max_high(char *filename)
{
	int		i;
	char	*line;
	int		fd;
	char	**splited;
	int		base_size;

	base_size = 0;
	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		splited = ft_strsplit(line, ' ');
		i = 0;
		while (splited[i])
		{
			if (ft_atoi(splited[i]) > base_size)
				base_size = ft_atoi(splited[i]);
			i++;
		}
		free(line);
		free(splited);
	}
	close(fd);
	return (base_size);
}

static void	get_scale_x(t_map **map, char **argv)
{
	int size;
	int size_y;

	size = count_lines(argv[1]);
	size_y = read_max_high(argv[1]);
	if (size >= 100)
		(*map)->scale_x = size / 10 / 2 / 2;
	else
	{
		if (size_y > 10)
		{
			if (size_y > 40)
				(*map)->scale_x = size_y / 10;
			else
				(*map)->scale_x = size_y / 2;
		}
		else
			(*map)->scale_x = size_y;
	}
	(*map)->scale_y = (*map)->scale_x;
}

static void	init_map(t_map *map, char **argv, int err)
{
	if (err != 2)
	{
		map->scale_x = ft_atoi(argv[2]);
		map->scale_y = ft_atoi(argv[3]);
	}
	else
	{
		get_scale_x(&map, argv);
	}
	map->ori_x = map->scale_x;
	map->ori_y = map->scale_y;
	map->points_num = map->height * map->width;
}

int			main(int argc, char **argv)
{
	t_map		map;
	int			err;

	map = read_map(argv[1]);
	err = (ft_argcheck(argc, argv));
	if (err == -1)
		return (0);
	if (read_len(argv[1]) == -1)
	{
		ft_putendl("Error : Incorrect map format.");
		return (0);
	}
	init_map(&map, argv, err);
	ft_map(&map, &map.points);
	free_file(map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, argv[1]);
	ft_init_map(&map);
	mlx_key_hook(map.win, key_hook, &map);
	mlx_loop(map.mlx);
	return (0);
}
