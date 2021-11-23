/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunbchoi <sunbchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:14:16 by sunbchoi          #+#    #+#             */
/*   Updated: 2021/11/23 17:17:45 by sunbchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void walk_process(int x, int y, t_data *data)
{
    t_pos   *cur;
    cur = &data->map_data.game_data.pos_data;
    
    data->map_data.map_mtrix[cur->y][cur->x] = '0';
    data->map_data.map_mtrix[y][x] = 'P';
    cur->x = x;
    cur->y = y;
}

int walk_check(int x, int y, t_data *data)
{
    t_pos pos;
    char check;
    int flag;

    pos.x = data->map_data.game_data.pos_data.x + x;
    pos.y = data->map_data.game_data.pos_data.y + y;
    check = data->map_data.map_mtrix[pos.y][pos.x];
    //10CPE"
    if (check == item_key[0])
        return (0);
    if (check == item_key[1])
    {
        walk_process(pos.x, pos.y, data);
        return (1);
    }
    if (check == item_key[2]) 
    {
        walk_process(pos.x, pos.y, data);
        data->map_data.game_data.item_cnt--;
        return (1);
    }
    if (check == item_key[4] && data->map_data.game_data.item_cnt != 0)
        return (0);
    if (check == item_key[4] && data->map_data.game_data.item_cnt == 0)
    {    
        return (0);
        exit(0);
    }
}

int key_press(int keycode, t_data *data) // 어떤 키가 눌렸는지 판단하고,
{                                                // 정의된 행동을 수행하는 함수
	int x;
    int y;
    int flag;

    x = 0;
    y = 0;
    if (keycode == KEY_W)        // W 키를 누르면 param.x값이 1 증가한다.
		y = -1;
	else if (keycode == KEY_S)   // S 키를 누르면 param.x값이 1 감소한다.
        y = 1;
    else if (keycode == KEY_A)   // A 키를 누르면 param.y값이 1 증가한다.
        x = -1;
    else if (keycode == KEY_D)   // D 키를 누르면 param.y값이 1 감소한다.
        x = 1;
    if (keycode == KEY_ESC) // ESC 키를 누르면 프로그램 종료
		exit(0);
    flag = walk_check(x, y, data);
    print_map(data);
    
    if (flag != 0)
    {
        printf("STEP CNT[%d]\n", data->map_data.game_data.step_cnt++); // param의 값 확인
	}
    return (0);
}

