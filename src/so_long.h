/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:32:29 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/24 14:46:08 by sunbchoi         ###   ########.fr       */
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

# define X_EVENT_KEY_PRESS 2     // mlx_hook 함수의 두 번째 인자인 
# define X_EVENT_KEY_RELEASE 3   // x_event에 들어가는 값
# define X_EVENT_KEY_EXIT 17
# define KEY_W 13    // MacOS의 키보드 코드들이다.          
# define KEY_A 0     //
# define KEY_S 1     // 위에서 부터 차례대로
# define KEY_D 2     //
# define KEY_ESC 53  // 'W' 'A' 'S' 'D' 'ESC'들의 키보드 코드이다.

typedef struct s_img
{
    void    *wall;
    void    *exit;
    void    *item;
    void    *point;
    void    *ground;
}   t_img;

typedef struct s_pos
{
    int     x;
    int     y;
}   t_pos;

typedef struct s_game
{
	int         point_cnt;
    int			item_cnt;
	int         exit_cnt;
    int			step_cnt;
    t_pos       pos_data;
}	t_game;

typedef struct s_map
{
	char		**map_mtrix;
    size_t      x_len;
    size_t      y_len;
    t_game      game_data;
}	t_map;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_img   img;
    t_map   map_data;
}   t_data;

void print_map(t_data *data);
int	error(char *msg);
void initialize_data(char* argv[], t_data *data);
int	check_map(t_data *data);
int key_press(int keycode, t_data *data); // 어떤 키가 눌렸는지 판단하고,
int check_can_go(t_data *data);

#endif