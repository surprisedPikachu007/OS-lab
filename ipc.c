#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<unistd.h>

int main() {
    int child, shmid;
    char *shm;

    child = fork();

    if (child) {
        shmid = shmget(2041, 32, 0666 | IPC_CREAT);
        shm = shmat(shmid, 0, 0);
        printf("Parent writing\n");

        for(int i = 0; i < 10; i++) {
            shm[i] = 'a' + i;
            putchar(shm[i]);
        }
        printf("\n");
        wait(NULL);
    }

    else {
        shmid = shmget(2041, 32, 0666);
        shm = shmat(shmid, 0, 0);
        printf("Child reading\n");

        for(int i = 0; i < 10; i++) {
            putchar(shm[i]);
            wait(NULL);
        }
        printf("\n");
    }

    return 0;
}