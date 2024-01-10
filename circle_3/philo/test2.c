#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int cnt = 0;
pthread_mutex_t mutex_cnt;

void *thread_func(void *data)
{
	char *name = (char *)data;
	
	pthread_mutex_lock(&mutex_cnt);
	int i = 0;
	while (1)
    {
        printf("%s %d\n", name, i);
        i++;
        usleep(100);
    }
	pthread_mutex_unlock(&mutex_cnt);

	return NULL;
}

int main()
{
    pthread_t th;

    int i = 0;
	char name[8] = "thread1";
    char name2[8] = "threadM";

	printf("Before Thread\n"); 

    pthread_mutex_init(&mutex_cnt, 0);

    if (pthread_create(&th, NULL, thread_func, (void *)name))
        return (1);

    while (i < 100)
    {
        printf("%s %d\n", name2, i);
        i++;
    }
	pthread_join(th, NULL);
	printf("After Thread\n");
	pthread_mutex_destroy(&mutex_cnt);

    return 0;
}
