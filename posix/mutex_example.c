#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t *tid;
pthread_mutex_t mutex_lock;

void* doWork(void *arg)
{
    unsigned long i = 0;
    pthread_t id = pthread_self();

    printf("\n Thread processing %ld\n", id);

    // start of critical section

    pthread_mutex_lock(&mutex_lock);

    for(i=0; i<(0xFFFFFFFF);i++);

    // end of critical section

    pthread_mutex_unlock(&mutex_lock);

    printf("\n Thread processing %ld: Done\n", id);

    return NULL;
}

int main(int argc, char *argv[])
{
    int i = 0;
    int err;

    if (argc != 2) {
        printf("Error: Wrong number of parameters. One integer parameter is needed\n");
        return -1;
    }

    int nThreads = atoi(argv[1]);
    if (nThreads <= 0) {
        printf("Too few threads. Please specify a number greater than zero\n");
        return -1;
    }

    // init mutex lock
    if (pthread_mutex_init(&mutex_lock, NULL) != 0) {
        printf("Fatal error: could not initialize mutex\n");
        return -1;
    }

    tid = (pthread_t *) malloc(nThreads * sizeof(pthread_t));

    while(i < nThreads)
    {
        err = pthread_create(&(tid[i]), NULL, &doWork, NULL);
        if (err != 0)
            printf("\ncan't create thread :[%s]", strerror(err));
        else
            printf("\n Thread created successfully\n");

        i++;
    }

    for(i = 0; i < nThreads; i++) {
        pthread_join(tid[i], NULL);
    }

    free(tid);
    pthread_mutex_destroy(&mutex_lock);

    return 0;
}
