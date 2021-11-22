/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:32:29 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/22 18:13:50 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "./../libft/libft.h"

# define item_key "10CPE"

typedef struct s_img
{
    void    *wall;
    void    *exit;
    void    *item;
    void    *point;
    void    *ground;
}   t_img;

typedef struct s_game
{
	int			count_collec;
	int			count_steps;
	int			count_enemy;
}	t_game;

typedef struct s_map
{
	char		**map_mtrix;
    size_t      x_len;
    size_t      y_len;
    t_game      org_data;
    t_game      cur_data;
}	t_map;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_img img;
    t_map map_data;
}   t_data;

void print_map(t_data *data);
int	error(char *msg);
void initialize_data(char* argv[], t_data *data);

#endif