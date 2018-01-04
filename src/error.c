/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnoth <wnoth@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:08:04 by wnoth             #+#    #+#             */
/*   Updated: 2017/12/01 10:29:50 by wnoth            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_argcheck(int argc, char **argv)
{
	if (argc == 2)
		return (2);
	if (argc != 4)
	{
		ft_putstr("Usage : ./fdf <filename> [ case_size high_size ]\n");
		return (-1);
	}
	else
	{
		if ((ft_atoi(argv[2]) == 0) || (ft_atoi(argv[3]) == 0))
		{
			ft_putstr("Usage : ./fdf <filename> [ case_size high_size ]\n");
			return (-1);
		}
	}
	return (0);
}
