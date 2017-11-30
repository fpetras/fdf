/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpetras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 08:59:29 by fpetras           #+#    #+#             */
/*   Updated: 2017/11/30 17:09:57 by fpetras          ###   ########.fr       */
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
	free(str);
}

void		map_data(char *file, t_struct *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	data->fd = open(file, O_RDONLY);
	if (!(data->map = (int**)malloc(sizeof(int*) * data->map_height)))
		exit(write(2, "malloc failure\n", 15));
	while (get_next_line(data->fd, &data->line))
	{
		j = 0;
		if (!(data->values = ft_strsplit(data->line, ' ')))
			exit(write(2, "malloc failure\n", 15));
		free(data->line);
		if (!(data->map[i] = (int*)malloc(sizeof(int) * data->map_width)))
			exit(write(2, "malloc failure\n", 15));
		while (data->values[j] != 0)
		{
			data->map[i][j] = ft_atoi(data->values[j]);
			free(data->values[j]);
			j++;
		}
		free(data->values);
		i++;
	}
	close(data->fd);
}
