#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main()
{
    struct timeval time;

    gettimeofday(&time, NULL);
    //1초 : 0.001ms, 1초 : 0.000001us
    long	result = (time.tv_sec * 1000) + (time.tv_usec / 1000);
    printf("%ld", result);  //result : ms로 변환
    return 0;
}