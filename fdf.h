/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:10:45 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/29 15:46:06 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <math.h>
# include "mlx.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"

# define WIN_WIDTH	1280
# define WIN_HEIGHT	720

typedef struct	s_struct
{
	void		*mlx;
	void		*win;
	void		*img;
	char		**av;
	int			**map;
	size_t		map_width;
	size_t		map_height;
	int			height_diff;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			size;
	int			height;
	int			border_x;
	int			border_y;
}				t_struct;

typedef struct	s_values
{
	int			i;
	int			x1;
	int			y1;
	int			x2;
	int			y2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			d;
	int			d2;
	int			swap;
}				t_values;

typedef struct	s_coords
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_coords;

void			map_dimensions(char *file, t_struct *data);
void			map_data(char *file, t_struct *data);
void			ft_set_constants(t_struct *data);
void			draw_map(t_struct *data);

#endif
