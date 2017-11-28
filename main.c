/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:09:45 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/28 15:04:21 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_hook_funct(int keycode, t_struct *data)
{
	(void)data;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

void	wireframe(char *file, t_struct *data)
{
	t_values *v;

	v = (t_values*)malloc(sizeof(t_values));
	map_dimensions(file, data);
	map_data(file, data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	ft_init_values(v, WIN_WIDTH / 2, WIN_HEIGHT, WIN_WIDTH / 2, 0);
	draw_line(data, v);
	ft_init_values(v, 50, 100, 500, 480);
	draw_line(data, v);
	mlx_key_hook(data->win, my_key_hook_funct, data);
	mlx_loop(data->mlx);
}

int		main(int ac, char **av)
{
	t_struct *data;

	if (!(data = (t_struct*)malloc(sizeof(t_struct))))
		exit(write(2, "malloc failure\n", 15));
	if (ac == 2)
		wireframe(av[1], data);
	else
		ft_putendl_fd("usage: ./fdf filename", 2);
	return (0);
}
