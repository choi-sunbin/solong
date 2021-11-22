/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:55:10 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/22 18:08:09 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void *select_img(char cur, t_data *data)
{
    if (cur == item_key[0])
        return (data->img.wall);
	else if (cur == item_key[1])
		return (data->img.ground);
	else if (cur == item_key[2])
		return (data->img.item);
	else if (cur == item_key[3])
	    return (data->img.point);
	else if (cur == item_key[4])
		return (data->img.exit);
    return (NULL);
}

void print_map(t_data *data)
{
	int     loop;
	int     loop2;
	char    cur;
    void    *img;
	
	loop = 0;
	loop2 = 0;
	while (loop2 < data->map_data.y_len)
	{
		loop = 0;
		while (loop < data->map_data.x_len)
		{
			cur = data->map_data.map_mtrix[loop2][loop];
			img = select_img(cur, data);
            if (img == data->img.point || img == data->img.item)          
			    mlx_put_image_to_window(data->mlx, data->win, data->img.ground, loop * 64, loop2 * 64);
			mlx_put_image_to_window(data->mlx, data->win, img, loop * 64, loop2 * 64);
			loop++;
		}
		loop2++;
	}
}
