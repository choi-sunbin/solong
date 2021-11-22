#include <stdio.h>
#include <mlx.h>

int main(void)
{
	void *mlx_ptr;
	void *win_ptr;
	void *img_ptr;  // 이미지를 저장할 포인터
	void *img_ptr2;  // 이미지를 저장할 포인터
	void *img_ptr3;  // 이미지를 저장할 포인터
	void *img_ptr4;  // 이미지를 저장할 포인터
	void *img_ptr5;  // 이미지를 저장할 포인터
	
    
    
    int width;  // 이미지의 너비
	int height; // 이미지의 높이

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "load image!");
	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "./img/Wall.xpm", &width, &height);
    img_ptr2 = mlx_xpm_file_to_image(mlx_ptr, "./img/Ground.xpm", &width, &height);
	img_ptr3 = mlx_xpm_file_to_image(mlx_ptr, "./img/Apple.xpm", &width, &height);
    img_ptr4 = mlx_xpm_file_to_image(mlx_ptr, "./img/Goraphaduck.xpm", &width, &height);
	img_ptr5 = mlx_xpm_file_to_image(mlx_ptr, "./img/Water.xpm", &width, &height);
    
	
    
    int loop = 0;

    while (loop < 5)
    {
        mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, loop * 64, 0);
        mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, loop * 64);   
        loop++;
    }
    loop = 1;
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2, loop++ * 64, 64);
    
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2,  loop * 64, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr3, loop++ * 64, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2,  loop * 64, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr4, loop++ * 64, 64);
    
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr2,  loop * 64, 64);
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr5, loop++ * 64, 64);
    
    loop++;
    
  //:wq  printf("%d",img_ptr);
	mlx_loop(mlx_ptr);
	return (0);
}