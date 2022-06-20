// producer - consumer problem with semaphores
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

sem_t mutex;
sem_t empty;
sem_t full;

int buffer[10];
int in=0,out=0;
int noOfItems=0;

void *Producer(void *arg) {
    printf("Producer created\n");
    
    for (int i = 0; i < noOfItems; i++) {
        printf(" Producer produced : %d\n", i);

        in = (in+1) % 10;

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = i;

        sem_post(&mutex);
        sem_post(&full);
    }
}

void *Consumer(void *arg) {
    printf("consumer created\n");

    int data;

    for (int i = 0; i < noOfItems; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        out = (out + 1) % 10;
        data = buffer[out];

        printf(" \tConsumer consumed : %d\n",data); 

        sleep(1);

        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main(int argc, char *argv[]) {
    noOfItems = atoi(argv[1]);

    pthread_t t1, t2;

    sem_init(&mutex, 1, 1);
    sem_init(&empty, 1, 1);
    sem_init(&full, 1, 0);

    printf("main started\n");

    pthread_create(&t1, NULL, Producer, NULL);
    pthread_create(&t2, NULL, Consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    printf("main ended\n");

    return 0;
}