/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 07:28:33 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/28 14:51:54 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_init_values(t_values *v, int x1, int y1, int x2, int y2)
{
	v->i = 0;
	v->x1 = x1;
	v->y1 = y1;
	v->x2 = x2;
	v->y2 = y2;
	v->x = v->x1;
	v->y = v->y1;
	v->dx = abs(v->x2 - v->x1);
	v->dy = abs(v->y2 - v->y1);
	if ((v->x2 - v->x1) > 0)
		v->sx = 1;
	else if ((v->x2 - v->x1) < 0)
		v->sx = -1;
	else
		v->sx = 0;
	if ((v->y2 - v->y1) > 0)
		v->sy = 1;
	else if ((v->y2 - v->y1) < 0)
		v->sy = -1;
	else
		v->sy = 0;
	v->swap = 0;
}

void		draw_line(t_struct *data, t_values *v)
{
	if (v->dy > v->dx)
	{
		ft_swap(&v->dx, &v->dy);
		v->swap = 1;
	}
	v->d = 2 * v->dy - v->dx;
	while (v->i < v->dx)
	{
		mlx_pixel_put(data->mlx, data->win, v->x, v->y, 0xFFFFFF);
		while (v->d >= 0)
		{
			v->d = v->d - 2 * v->dx;
			if (v->swap == 1)
				v->x += v->sx;
			else
				v->y += v->sy;
		}
		v->d = v->d + 2 * v->dx;
		if (v->swap == 1)
			v->y += v->sy;
		else
			v->x += v->sx;
		v->i++;
	}
}
