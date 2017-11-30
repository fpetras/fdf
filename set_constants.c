/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_constants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 12:41:44 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/29 16:19:42 by fpetras          ###   ########.fr       */
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
	printf("min = %d\nmax = %d\n", min, max);
	printf("height_diff = %d\n", data->height_diff);
}

void		ft_set_constants(t_struct *data)
{
	get_height_diff(data);
	data->size = 30;
	data->height = 1;
	data->border_x = WIN_WIDTH / 3;
	data->border_y = WIN_HEIGHT / 3;
	if (data->map_height > 19 || data->map_width > 19)
	{
		data->border_x = WIN_WIDTH / 10;
		data->border_y = WIN_HEIGHT / 5;
		data->size = 20;
	}
	if (data->map_height > 49 || data->map_width > 49)
	{
		data->border_x = WIN_WIDTH / 10;
		data->border_y = WIN_HEIGHT / 10;
		data->size = 15;
	}
	if (data->map_height > 99 || data->map_width > 99)
		data->size = 10;
	if (data->map_height > 199 || data->map_width > 199)
		data->size = 5;
	if (data->height_diff > 99)
		data->height = 1;
}
