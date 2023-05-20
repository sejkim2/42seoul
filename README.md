# 42cursus

# So_Long

# MiniLibX
>  그래픽에 대한 전문 지식 없이도 그래픽 프로그래밍을 학습하기 위해 42서울에서 개발한 라이브러리이다.
>  컴파일 시 -L[mlx 폴더의 경로] -lmlx -framework OpenGL -framework Appkit -Imlx 옵션을 같이 넣어서 컴파일 한다. (makefile에 지정)
> 내부 함수 살펴보기
  * mlx_init() : 소프트웨어와 디스플레이를 연결, 반환값은 (void *) 이며 연결 식별자로 사용된다.
  * mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title) : 새 창을 연다. 반환값은 (void *) 이며 윈도우 창 식별자로 사용된다.
  * mlx_destroy_window(void *mlx_ptr, void *win_ptr) : 창을 종료한다.
