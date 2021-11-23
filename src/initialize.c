/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:10:49 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/23 17:54:24 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *argv[], t_data *data)
{
	int		fd;
	int		loop;
	char	*line;

	data->map_data.y_len = 0;
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

void	read_img(t_data *data)
{
	int	w;
	int	h;

	data->img.wall = mlx_xpm_file_to_image(data->mlx, "./img/Wall.xpm", &w, &h);
	data->img.ground = mlx_xpm_file_to_image(data->mlx, "./img/Ground.xpm", &w, &h);
	data->img.item = mlx_xpm_file_to_image(data->mlx, "./img/Apple.xpm", &w, &h);
	data->img.point = mlx_xpm_file_to_image(data->mlx, "./img/Goraphaduck.xpm", &w, &h);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "./img/Water.xpm", &w, &h);
}

void	read_game(t_data *data)
{
	int		loop_x;
	int		loop_y;
	char	key;

	loop_x = 0;
	loop_y = 0;
	while (loop_y < data->map_data.y_len)
	{
		loop_x = 0;
		while (loop_x < data->map_data.x_len)
		{
			key = data->map_data.map_mtrix[loop_y][loop_x];
			if (key == 'C')
				data->map_data.game_data.item_cnt++;
			else if (key == 'P')
			{
				data->map_data.game_data.point_cnt++;
				data->map_data.game_data.pos_data.x = loop_x;
				data->map_data.game_data.pos_data.y = loop_y;
			}
			else if (key == 'E')
				data->map_data.game_data.exit_cnt++;
			else if (key == '0' || key == '1')
			{	
				loop_x++;
				continue ;
			}
			else
				error("Wrong map Data\nPlease Check Map Data");
			loop_x++;
		}
		loop_y++;
	}
}

void	initialize_data(char *argv[], t_data *data)
{
	data->mlx = mlx_init();
	read_map(argv, data);
	read_game(data);
	read_img(data);
}
