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

void *Producer(void *arg) {
    int i;
    for (i = 0; i < 10; i++) {
        printf(" Producer produced : %d\n", i);
        //in = (in+1) % 10;
        //buffer[in] = i;
        sem_wait(&empty);
        sem_wait(&mutex);
        sem_post(&mutex);
        sem_post(&full);
    }
}

void *Consumer(void *arg) {
    int i,data;
    for (i = 0; i < 10; i++) {
    printf(" \tConsumer consumed : %d\n",data);
    sem_wait(&full);
    sem_wait(&mutex);
    //out = (out + 1) % 10;
    //data = buffer[out];
    sleep(1);
    sem_post(&mutex);
    sem_post(&empty);
    }
}

int main() {
    pthread_t t1, t2;
    sem_init(&mutex, 1, 1);
    sem_init(&empty, 1, 1);
    sem_init(&full, 1, 0);
    pthread_create(&t1, NULL, Producer, NULL);
    pthread_create(&t2, NULL, Consumer, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    return 0;
}