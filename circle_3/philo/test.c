#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int cnt = 0;
pthread_mutex_t mutex;

void *t_function(void *data)
{
	char *name = (char *)data;
	
	pthread_mutex_lock(&mutex);

	for(int i = 0; i<10; i++)
	{
		printf("%s cnt : %d\n", name, cnt);
		cnt++;
		usleep(1000000);
	}

	pthread_mutex_unlock(&mutex);
}

int main()
{
    pthread_t th1;
	pthread_t th2;
    int status;
	cnt = 0;

	printf("Before Thread\n"); 

	pthread_mutex_init(&mutex, 0);
    pthread_create(&th1, NULL, t_function, (void *)"thread1");
	pthread_create(&th2, NULL, t_function, (void *)"thread2");
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_mutex_destroy(&mutex);

    return 0;
}