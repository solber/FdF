/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:08:04 by wnoth             #+#    #+#             */
/*   Updated: 2017/11/28 10:15:56 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Calcul de la hauteur de la carte AkA nbr de ligne
*/

int				count_lines(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	lines = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
	{
		ft_putstr("Error : Can't open file.\n");
		exit(-1);
	}
	if (!(get_next_line(fd, &line)))
	{
		ft_putendl("Error : Empty map.");
		exit(0);
	}
	while (get_next_line(fd, &line))
	{
		lines++;
		free(line);
		line = NULL;
	}
	close(fd);
	return (lines);
}

/*
** Lecture de la carte
*/

t_map			read_map(char *filename)
{
	char		*line;
	t_map		file;
	int			fd;
	int			i;

	i = 0;
	file.height = 0;
	file.map = NULL;
	if (!(fd = open(filename, O_RDONLY)))
		return (file);
	file.height = count_lines(filename) + 1;
	file.map = (char**)malloc(sizeof(char*) * file.height);
	while (i < file.height)
	{
		get_next_line(fd, &line);
		file.map[i++] = line;
	}
	close(fd);
	return (file);
}

static int		ft_len(char **str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
** verification du formatage en X de la carte
*/

int				read_len(char *filename)
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
		if (!base_size)
			base_size = ft_len(splited);
		if (base_size != ft_len(splited))
			return (-1);
		free(line);
		free(splited);
	}
	close(fd);
	return (base_size);
}

/*
** Nettoyage des preuves
*/

void			free_file(t_map map)
{
	int		l;

	l = 0;
	while (l < map.height)
	{
		free(map.map[l]);
		l++;
	}
	free(map.map);
}
