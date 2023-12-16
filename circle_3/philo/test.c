#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int cnt = 0;
pthread_mutex_t mutex_cnt;
pthread_mutex_t mutex_print;

void *thread_func(void *data)
{
	char *name = (char *)data;

	pthread_mutex_lock(&mutex_print);
	
	pthread_mutex_lock(&mutex_cnt);
	for(int i = 0; i<10; i++)
	{
		// printf("%s cnt : %d\n", name, cnt);
		cnt++;
		usleep(10);
	}
	pthread_mutex_unlock(&mutex_cnt);
	
	printf("%s cnt : %d\n", name, cnt);
	pthread_mutex_unlock(&mutex_print);

	return NULL;
}

int main()
{
    pthread_t th[5];

    int i;
	char name[5][8] = { "thread0", "thread1", "thread2", "thread3", "thread4"};
	char *thread_name = 0;
	i = 0;
	cnt = 0;

	printf("Before Thread\n"); 

	pthread_mutex_init(&mutex_cnt, 0);
	pthread_mutex_init(&mutex_print, 0);

	while (i < 5)
	{
		if (pthread_create(&th[i], NULL, thread_func, (void *)name[i]))
			return (1);
		i++;
	}

	i = 0;
	while (i < 5)
	{
		pthread_join(th[i], NULL);
		i++;
	}

	printf("After Thread\n");
	pthread_mutex_destroy(&mutex_cnt);
	pthread_mutex_destroy(&mutex_print);

    return 0;
}
