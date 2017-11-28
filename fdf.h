/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:10:45 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/28 14:53:18 by fpetras          ###   ########.fr       */
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
}				t_struct;

typedef struct	s_values
{
	void		*mlx;
	void		*win;
	int			i;
	int			x;
	int			x1;
	int			x2;
	int			dx;
	int			sx;
	int			y;
	int			y1;
	int			y2;
	int			dy;
	int			sy;
	int			swap;
	int			d;
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
void			draw_line(t_struct *data, t_values *v);
void			ft_init_values(t_values *v, int x1, int y1, int x2, int y2);

#endif
