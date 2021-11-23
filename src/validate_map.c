/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:31:00 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/23 20:50:45 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_data *data)
{
	int		loop_y;
	int		loop_x;

	loop_y = 0;
	while (loop_y < data->map_data.x_len)
	{
		loop_x = 0;
		if (loop_y == 0 || loop_y == (data->map_data.y_len - 1))
		{
			while (data->map_data.map_mtrix[loop_y][loop_x])
			{
				if (data->map_data.map_mtrix[loop_y][loop_x] != '1')
					error("Invalid map: top or bottom is not surrounded by wall");
				loop_x++;
			}
		}
		if (data->map_data.map_mtrix[loop_y][0] != '1'
			|| data->map_data.map_mtrix[loop_y][data->map_data.x_len - 1] != '1')
			error("Invalid map: side wall is not surrounded by wall");
		loop_y++;
	}
	return (1);
}

int check_has(t_data *data)
{
	if (data->map_data.game_data.exit_cnt == 0)
		error("Invalid map: No Exit");
	if (data->map_data.game_data.item_cnt == 0)
		error("Invalid map: No Item");
	if (data->map_data.game_data.point_cnt == 0)
		error("Invalid map: No Character");
	if (data->map_data.game_data.point_cnt > 1)
		error("Invalid map: Too many Character");
	return (1);
}

int	check_ret(t_data *data)
{
	int		loop_y;

	loop_y = 0;
	while (loop_y < data->map_data.y_len)
	{
		if (data->map_data.x_len != (int)ft_strlen(data->map_data.map_mtrix[loop_y]))
			error("Invalid map: not a retangle");
		loop_y++;
	}
	return (1);
}

int	check_char(t_data *data)
{
	int		loop_y;
	int		loop_x;
    char    check;

	loop_y = 0;
	while (loop_y < data->map_data.y_len)
	{
		loop_x = 0;
		while (data->map_data.map_mtrix[loop_y][loop_x])
		{
			check = data->map_data.map_mtrix[loop_y][loop_x];
			if (ft_strchr(item_key, check) == NULL)
				error("Invalid map: unknown char");
			loop_x++;
		}
		loop_y++;
	}
	return (1);
}

int check_can_go(t_data *data)
{
	char	**cpy_map;
	int		loop_y;
	int		loop_x;

	cpy_map = (char **)ft_calloc(sizeof(char), data->map_data.y_len + 1);
	loop_y = 0;
	while (loop_y < data->map_data.y_len)
	{
		cpy_map[loop_y] = ft_calloc(sizeof(char), data->map_data.x_len + 1);
		ft_strcat(cpy_map[loop_y], data->map_data.map_mtrix[loop_y]);
		loop_y++;
	}
	return (1)l
}

int	check_map(t_data *data)
{
	check_walls(data);
	check_has(data);
	check_ret(data);
	check_char(data);
	return (0);
}