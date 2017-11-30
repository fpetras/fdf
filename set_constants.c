/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_constants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:41:44 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/30 19:13:20 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_height_diff(t_struct *data)
{
	size_t	i;
	size_t	j;
	int		min;
	int		max;

	i = 0;
	min = data->map[0][0];
	max = data->map[0][0];
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			if (min > data->map[i][j])
				min = data->map[i][j];
			if (max < data->map[i][j])
				max = data->map[i][j];
			j++;
		}
		i++;
	}
	data->height_diff = max - min;
}

static void	ft_set_constants2(t_struct *data)
{
	if (data->height_diff > 19)
		data->height = 3;
	if (data->height_diff > 49)
		data->height = 1;
	if (data->map_height > data->map_width)
	{
		data->border_y = WIN_HEIGHT / 20;
		data->size = 20;
	}
	if (data->map_width == 19 && data->map_height == 11)
	{
		data->border_x = WIN_WIDTH / 5;
		data->border_y = WIN_WIDTH / 10;
		data->size = 42;
		data->height = 2;
	}
}

void		ft_set_constants(t_struct *data)
{
	get_height_diff(data);
	data->size = 50;
	data->height = 15;
	data->border_x = WIN_WIDTH / 3;
	data->border_y = WIN_HEIGHT / 6;
	if (data->map_height >= 19 || data->map_width >= 19)
		data->size = 20;
	if (data->map_height >= 48 || data->map_width >= 48)
	{
		data->border_x = WIN_WIDTH / 10;
		data->border_y = WIN_HEIGHT / 20;
		data->size = 10;
		data->height = 2;
	}
	if (data->map_height > 99 || data->map_width > 99)
	{
		data->size = 6;
		data->height = 1;
	}
	if (data->map_height > 199 || data->map_width > 199)
		data->size = 5;
	ft_set_constants2(data);
}
