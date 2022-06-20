// implementation of memory allocation schemes such as first fit, best fit and worst fit
#include<stdio.h>
#include<stdlib.h>

int noOfBlocks;
int noOfProcesses;
int *blocks;
int *processes;

void display(int *processAllocated, int *blockAllocated) {
    printf("\n");
    printf("Process\tBlock");
    for (int i = 0; i < noOfProcesses; i++) {
        if (processAllocated[i] == -1) {
            printf("\n%d\tNot allocated", i); 
        }
        else {
            printf("\n%d\t%d", i, processAllocated[i]);
        }
    }
    printf("\n\n");
}

void first_fit() {
    int processAllocated[noOfProcesses];
    int blockAllocated[noOfBlocks];

    for (int i = 0; i < noOfBlocks; i++) {
        blockAllocated[i] = 0;
    }

    for (int i=0; i<noOfProcesses; i++) {
        processAllocated[i] = -1;
    }

    for(int i=0; i<noOfProcesses; i++) {
        for(int j=0; j<noOfBlocks; j++) {
            if(blockAllocated[j] == 0 && blocks[j] >= processes[i]) {
                blockAllocated[j] = 1;
                processAllocated[i] = j;
                break;
            }
        }
    }

    for(int i=0; i<noOfProcesses; i++) {
        if(processAllocated[i] == -1) {
            printf("No memory available for process %d\n", i);
        }
    }

    display(processAllocated, blockAllocated);
}

void best_fit() {
    int processAllocated[noOfProcesses];
    int blockAllocated[noOfBlocks];

    for (int i = 0; i < noOfBlocks; i++) {
        blockAllocated[i] = 0;
    }

    for (int i=0; i<noOfProcesses; i++) {
        processAllocated[i] = -1;
    }

    for(int i=0; i<noOfProcesses; i++) {
        int min = -1;

        for(int j=0; j<noOfBlocks; j++) {
            if(blockAllocated[j] == 0 && blocks[j] >= processes[i] && (min == -1 || blocks[j] < blocks[min])) {
                min = j;
            }
        }

        if(min != -1) {
            blockAllocated[min] = 1;
            processAllocated[i] = min;
        }
        else {
            printf("No memory available for process %d\n", i);
        }
    }

    display(processAllocated, blockAllocated);
}

void worst_fit() {
    int processAllocated[noOfProcesses];
    int blockAllocated[noOfBlocks];

    for (int i = 0; i < noOfBlocks; i++) {
        blockAllocated[i] = 0;
    }

    for (int i=0; i<noOfProcesses; i++) {
        processAllocated[i] = -1;
    }

    for(int i=0; i<noOfProcesses; i++) {
        int max = -1;

        for(int j=0; j<noOfBlocks; j++) {
            if(blockAllocated[j] == 0 && blocks[j] >= processes[i] && (max == -1 || blocks[j] > blocks[max])) {
                max = j;
            }
        }

        if(max != -1) {
            blockAllocated[max] = 1;
            processAllocated[i] = max;
        }
        else {
            printf("No memory available for process %d\n", i);
        }
    }

    display(processAllocated, blockAllocated);
}

int main() {
    noOfBlocks = 5;
    noOfProcesses = 4;

    // uncomment the following lines to get the input from the user

    /*printf("Enter number of blocks: ");
    scanf("%d", &noOfBlocks);
    printf("Enter number of processes: ");
    scanf("%d", &noOfProcesses);*/

    blocks = (int *)malloc(noOfBlocks * sizeof(int));
    processes = (int *)malloc(noOfProcesses * sizeof(int));

    blocks[0] = 200;
    blocks[1] = 350;
    blocks[2] = 300;
    blocks[3] = 100;
    blocks[4] = 600;

    processes[0] = 212;
    processes[1] = 412;
    processes[2] = 492;
    processes[3] = 349;

    //uncomment to get user input

    /*printf("Enter blocks: ");
    for (int i = 0; i < noOfBlocks; i++) {
        scanf("%d", &blocks[i]);
    }

    printf("Enter processes: ");
    for (int i = 0; i < noOfProcesses; i++) {
        scanf("%d", &processes[i]);
    }*/

    first_fit();
    best_fit();
    worst_fit();
}