/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 07:28:33 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/30 17:12:36 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_values	*ft_init_values(t_struct *data)
{
	t_values *v;

	if (!(v = (t_values*)malloc(sizeof(t_values))))
		exit(write(2, "malloc failure\n", 15));
	v->dx = abs(data->x2 - data->x1);
	v->dy = abs(data->y2 - data->y1) * -1;
	v->sx = (data->x2 > data->x1) ? 1 : -1;
	v->sy = (data->y2 > data->y1) ? 1 : -1;
	v->d = v->dx + v->dy;
	return (v);
}

static void		draw_line(t_struct *data)
{
	t_values *v;

	v = ft_init_values(data);
	while (data->x1 != data->x2 || data->y1 != data->y2)
	{
		mlx_pixel_put(data->mlx, data->win, data->x1, data->y1, 0xFFFFFF);
		v->d2 = 2 * v->d;
		if (v->d2 <= v->dx)
		{
			v->d += v->dx;
			data->y1 += v->sy;
		}
		if (v->d2 >= v->dx)
		{
			v->d += v->dy;
			data->x1 += v->sx;
		}
	}
}

#define SIZE		data->size
#define HEIGHT		data->height
#define BORDER_X	data->border_x
#define BORDER_Y	data->border_y

static void		ft_coordinates1(t_struct *data, int x, int y)
{
	if (x == 0)
		x++;
	data->x1 = BORDER_X + (SIZE * (x - 1));
	data->x1 += HEIGHT * data->map[y][x - 1];
	data->y1 = BORDER_Y + (SIZE * y);
	data->y1 += HEIGHT * data->map[y][x - 1];
	data->x2 = BORDER_X + (SIZE * x);
	data->x2 += HEIGHT * data->map[y][x];
	data->y2 = BORDER_Y + (SIZE * y);
	data->y2 += HEIGHT * data->map[y][x];
}

static void		ft_coordinates2(t_struct *data, int x, int y)
{
	if (y == 0)
		y++;
	data->x1 = BORDER_X + (SIZE * x);
	data->x1 += HEIGHT * data->map[y - 1][x];
	data->y1 = BORDER_Y + (SIZE * (y - 1));
	data->y1 += HEIGHT * data->map[y - 1][x];
	data->x2 = BORDER_X + (SIZE * x);
	data->x2 += HEIGHT * data->map[y][x];
	data->y2 = BORDER_Y + (SIZE * y);
	data->y2 += HEIGHT * data->map[y][x];
}

void			draw_map(t_struct *data)
{
	size_t		x;
	size_t		y;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			ft_coordinates1(data, x, y);
			draw_line(data);
			ft_coordinates2(data, x, y);
			draw_line(data);
			x++;
		}
		y++;
	}
}
