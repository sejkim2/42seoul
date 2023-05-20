#include <mlx.h>

typedef struct	s_date {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
}	t_data;

int main()
{
	t_data img;	//img에 대한 정보
	void *mlx_ptr;
	void *win_ptr;
	int width, height;

	mlx_ptr = mlx_init();	//초기화
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Hello world!");	//창 생성

	img.img = mlx_xpm_file_to_image(mlx_ptr, "testxpm2.xpm", &width, &height);
	
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 64, 0);	//위치 지정

	mlx_loop(mlx_ptr);	//창 계속 유지(무한루프)
	return (0);
}
