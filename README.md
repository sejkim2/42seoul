# 42cursus

# So_Long

# MiniLibX
>  그래픽에 대한 전문 지식 없이도 그래픽 프로그래밍을 학습하기 위해 42서울에서 개발한 라이브러리이다.
>  컴파일 시 -L[mlx 폴더의 경로] -lmlx -framework OpenGL -framework Appkit -Imlx 옵션을 같이 넣어서 컴파일 한다. (makefile에 지정) (동적 라이브러리 컴파일)

# 내부 함수 살펴보기
> void *mlx_init() : 소프트웨어와 디스플레이를 연결
  * return 타입 : void *이며 연결 식별자를 반환
> void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title) : window에 대한 제어
  * mlx_ptr : mlx_init의 반환값인 연결 식별자이며 이 식별자를 통해(디스플레이에 쏴준다) window를 생성
  * size_x : window의 width(너비)
  * size_y : window의 height(높이)
  * title : window 이름
  * return 타입 : void *이며 생성된 window에 대한 주소를 담고 있음 (mlx는 복수의 윈도우 관리가 가능하다)
