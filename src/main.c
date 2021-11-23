#include "so_long.h"
#include <string.h>


int check_input(int argc, char* argv[])
{
    char    *map_ext;
    
    if (argc < 2)
    {
        error("Please enter the name of the map file you want to use.\n\
            Ex: ./maps/map.ber");
    }
    else if (argc > 2)
    {
        error("Too many argument entered. Please retry it again.\n\
            Ex: ./maps/map.ber");
    }
    map_ext = ft_strrchr(argv[1], '.');
    if ((ft_strstr(map_ext, ".ber") == NULL) || (ft_strlen(map_ext) != ft_strlen(".ber")))
    	error("Invalid map extension. Please Enter *.ber"); 
    return (1);
}

int main(int argc, char* argv[])
{   
    t_data	*data;

	check_input(argc, argv);
	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	initialize_data(argv, data);
	data->win = mlx_new_window(data->mlx, data->map_data.x_len * 64, data->map_data.y_len * 64, "sunbchoi so_long");
    mlx_hook(data->win, X_EVENT_KEY_PRESS, 0, &key_press, data); // 키를 잡는 함수
	print_map(data);
    printf("CHECK"); // param의 값 확인
	
	mlx_loop(data->mlx);
 	return (0);
}