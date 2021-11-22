/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:10:49 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/22 18:15:44 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_map(char* argv[], t_data* data)
{
	int		fd;
	int		loop;
	char	*line;

	data->map_data.y_len =0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("Map not found");
	while (ft_gnl(fd, &line))
	{
		data->map_data.y_len++;
		free(line);
	}
	fd = open(argv[1], O_RDONLY);
	data->map_data.map_mtrix = (char **)ft_calloc(sizeof(char *), data->map_data.y_len + 1);
	loop = 0;
	while (ft_gnl(fd, &line))
	{
		data->map_data.x_len = ft_strlen(line);
		data->map_data.map_mtrix[loop++] = line;
	}
	free(line);
	close(fd);
}

void read_img(t_data *data)
{
	int width;
	int height;
	
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "./img/Wall.xpm", &width, &height);
    data->img.ground = mlx_xpm_file_to_image(data->mlx, "./img/Ground.xpm", &width, &height);
	data->img.item = mlx_xpm_file_to_image(data->mlx, "./img/Apple.xpm", &width, &height);
    data->img.point = mlx_xpm_file_to_image(data->mlx, "./img/Goraphaduck.xpm", &width, &height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "./img/Water.xpm", &width, &height);
}

void initialize_data(char* argv[], t_data *data)
{
    data->mlx = mlx_init();
    read_map(argv, data);
    read_img(data);
}
