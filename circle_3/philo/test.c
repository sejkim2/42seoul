#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int cnt1 = 0;
pthread_mutex_t mutex_cnt;
// pthread_mutex_t mutex_print;

void *thread_func(void *data)
{
	char *name = (char *)data;
	
	// pthread_mutex_lock(&mutex_cnt);
	int i = 0;
	while (i < 10)
    {
		usleep(10);
        printf("%s %d\n", name, cnt1);
		cnt1++;
        i++;
    }
	// pthread_mutex_unlock(&mutex_cnt);

	return NULL;
}

int main()
{
    pthread_t th[5];

    int i;
	char name[5][8] = { "thread0", "thread1", "thread2", "thread3", "thread4"};
	char *thread_name = 0;
	i = 0;

	printf("Before Thread\n"); 

	pthread_mutex_init(&mutex_cnt, 0);

	while (i < 5)
	{
		if (pthread_create(&th[i], NULL, thread_func, (void *)name[i]))
			return (1);
		i++;
	}

	// i = 0;
	// while (i < 10000)
	// {
	// 	usleep(10);
    //     printf("main %d\n", cnt1);
	// 	cnt1++;
    //     i++;
	// }
	i = 0;
	while (i < 5)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	printf("After Thread\n");
	pthread_mutex_destroy(&mutex_cnt);

    return 0;
}
