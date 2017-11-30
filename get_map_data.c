/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 08:59:29 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/29 15:32:07 by fpetras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*file_to_string(char *file)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	buf[BUFF_SIZE + 1];
	char	*str;

	fd = open(file, O_RDONLY);
	str = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		str = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	if (ret == -1)
		exit(write(2, "read failure\n", 13));
	close(fd);
	return (str);
}

static void	validate_file(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != ' '
		&& str[i] && str[i] != '\n')
		{
			if (str[i] == ',')
				while (str[i] != ' ' && str[i + 1] != '\0')
					i++;
			else
				exit(write(2, "invalid file\n", 13));
		}
		i++;
	}
}

void		map_dimensions(char *file, t_struct *data)
{
	size_t	i;
	char	*str;

	i = 0;
	str = file_to_string(file);
	validate_file(str);
	data->map_width = 0;
	data->map_height = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (ft_isdigit(str[i]) || (str[i] == '-' && ft_isdigit(str[i + 1])))
		{
			data->map_width++;
			while (str[i] != ' ' && str[i + 1] != '\n' && str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			data->map_height++;
		i++;
	}
}

/*
** for testing purposes
*/

static void	print_map(t_struct *data)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	printf("map_x = %zu\nmap_y = %zu\n", data->map_width, data->map_height);
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			printf("%d ", data->map[i][j]);
			if (data->map[i][j] >= 0 && data->map[i][j] <= 9)
				printf(" ");
			j++;
		}
		printf("\n");
		i++;
	}
}

void		map_data(char *file, t_struct *data)
{
	int		fd;
	size_t	i;
	size_t	j;
	char	*line;
	char	**values;

	fd = open(file, O_RDONLY);
	i = 0;
	if (!(data->map = (int**)malloc(sizeof(int*) * data->map_height)))
		exit(write(2, "malloc failure\n", 15));
	while (get_next_line(fd, &line))
	{
		j = 0;
		if (!(values = ft_strsplit(line, ' ')))
			exit(write(2, "malloc failure\n", 15));
		if (!(data->map[i] = (int*)malloc(sizeof(int) * data->map_width)))
			exit(write(2, "malloc failure\n", 15));
		while (values[j] != 0)
		{
			data->map[i][j] = ft_atoi(values[j]);
			j++;
		}
		i++;
	}
	close(fd);
	print_map(data);
}
