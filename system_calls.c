// implementation of system calls
// fork, execlp, wait, exit, getpid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if (pid == 0) {
        execlp("whoami", NULL);
    } 

    if (pid < 0) {
        fprintf(stderr, "fork failed\n");
        exit(0);
    }

    wait(NULL);

    printf("pid: %d\n", getpid());
    printf("finished\n");
    return 0;
}