/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_can_go.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:32:10 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/24 15:45:29 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **create_empty_map(t_data *data)
{
	char	**cpy_map;
	int		loop_y;
	int		loop_x;

	cpy_map = (char **)ft_calloc(sizeof(char *), data->map_data.y_len + 1);
	loop_y = 0;
	while (loop_y < data->map_data.y_len)
	{
		cpy_map[loop_y] = ft_calloc(sizeof(char), data->map_data.x_len + 1);
		ft_memmove(cpy_map[loop_y], data->map_data.map_mtrix[loop_y], data->map_data.x_len);
        cpy_map[loop_y][data->map_data.x_len] = 0;
        loop_y++;
	}
    loop_y = 0;
	while (loop_y < data->map_data.y_len)
	{
		loop_x = 0;
		while (loop_x < data->map_data.x_len)
		{
			if (cpy_map[loop_y][loop_x] == item_key[2] || cpy_map[loop_y][loop_x] == item_key[3] || cpy_map[loop_y][loop_x] == item_key[4] )
				cpy_map[loop_y][loop_x] = item_key[1];
			loop_x++;
		}
        loop_y++;
	}
	return (cpy_map);
}

int setting_empty_map(char **empty_map, int x, int y)
{
	int		loop;

	loop = 0;
	if (empty_map[y][x] == item_key[0] || empty_map[y][x] == item_key[2] || empty_map[y][x] == NULL)
		return (0);
    if (empty_map[y][x] == item_key[1])
		empty_map[y][x] = 'C';
	loop = 0;
	while (empty_map[y][x + loop] != item_key[0])
	{
		if (empty_map[y][x + loop] == item_key[1])
			setting_empty_map(empty_map, x + loop, y);
		loop++;
	}
    
	loop = 0;
	while (empty_map[y][x + loop] != item_key[0])
	{
		if (empty_map[y][x + loop] == item_key[1])
			setting_empty_map(empty_map, x + loop, y);
		loop--;
	}
	loop = 0;
    while (empty_map[y + loop][x] != item_key[0])
	{
		if (empty_map[y + loop][x] == item_key[1])
			setting_empty_map(empty_map, x, y + loop);
		loop++;
	}
	loop = 0;
	while (empty_map[y + loop][x] != item_key[0])
	{
		if (empty_map[y + loop][x] == item_key[1])
			setting_empty_map(empty_map, x, y + loop);
		loop--;
	}
    return (0);
}

int print_empty_map(char **empty_map, t_data *data)
{
    int loop_y;
    
    loop_y = 0;
    while (loop_y < data->map_data.y_len)
        printf("[%s]\n",empty_map[loop_y++]);
}

int checking_empty_map(char **empty_map, t_data *data)
{
    int loop_y;
    
    loop_y = 0;
    while (loop_y < data->map_data.y_len)
    {
        if (ft_strchr(empty_map[loop_y], '0') != NULL)
        {    
            error("MAP CANT GO AREA EGIST\n");
            print_empty_map(empty_map, data);
        }
        loop_y++;
    }
}

int check_can_go(t_data *data)
{
	t_pos	cur;
    char    **empty_map;
	int		loop;

	cur = data->map_data.game_data.pos_data;
    empty_map = create_empty_map(data);
	print_empty_map(empty_map, data);
    setting_empty_map(empty_map, cur.x, cur.y);
	empty_map[cur.y][cur.x] = item_key[3];
	print_empty_map(empty_map, data);
    checking_empty_map(empty_map, data);
}