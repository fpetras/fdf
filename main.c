/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 09:09:45 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/29 15:32:43 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	my_key_hook_funct(int keycode, t_struct *data)
{
	(void)data;
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

static void	wireframe(char *file, t_struct *data)
{
	map_dimensions(file, data);
	map_data(file, data);
	ft_set_constants(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF");
	draw_map(data);
	mlx_key_hook(data->win, my_key_hook_funct, data);
	mlx_loop(data->mlx);
}

int			main(int ac, char **av)
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
