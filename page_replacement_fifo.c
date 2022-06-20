// implementation of FIFO page replacement algorithm
#include<stdio.h>

int main() {
    int noOfPages;
    noOfPages = 10;

    int referenceString[10] = {2, 3, 2, 1, 5, 2, 4, 5, 3, 2}; // int referenceString[noOfPages];

    // uncomment the following line to take input from user

    /*printf("Enter the number of pages: ");
    scanf("%d", &noOfPages);
    
    for(int i=0; i<noOfPages; i++) {
        printf("Enter the reference string for page %d: ", i);
        scanf("%d", &referenceString[i]);
    }*/

    char frameSize = 3;
    int frame[frameSize];
    int frames[noOfPages][frameSize];

    for(int i=0; i<frameSize; i++) {
        frame[i] = -1;
    }

    int pageFaults = 0;
    int pageFault[noOfPages];
    for(int i=0; i<noOfPages; i++) {
        pageFault[i] = 0;
    }

    int current = 0;

    for (int i=0; i<noOfPages; i++) {
        int flag=0;

        for (int j=0; j<frameSize; j++) {
            if (frame[j] == referenceString[i]) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            pageFaults++;
            pageFault[i] = 1;
            frame[current] = referenceString[i];
            current = (current + 1) % frameSize;
        }

        for (int j=0; j<frameSize; j++) {
            frames[i][j] = frame[j];
        }
    }

    printf("\nPage Replacement Algorithm: FIFO\n");
    printf("H - Hit    F - Fault\n\n");

    for (int i=0; i<noOfPages; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\n");

    printf("----------------------------------------------------\n");

    for (int i=0; i<noOfPages; i++) {
        printf("%d ", frames[i][0]);
    }
    printf("\n");

    for (int i=0; i<noOfPages; i++) {
        if (frames[i][1] == -1) {
            printf(" ");
            printf(" ");
        } else {
            printf("%d ", frames[i][1]);
        }
    }
    printf("\n");

    for (int i=0; i<noOfPages; i++) {
        if (frames[i][2] == -1) {
            printf(" ");
            printf(" ");
        } else {
            printf("%d ", frames[i][2]);
        }
    }
    printf("\n");

    printf("----------------------------------------------------\n");

    for (int i=0; i<noOfPages; i++) {
        if (pageFault[i] == 1) {
            printf("F ");
        } else {
            printf("H ");
        }
    }
    printf("\n\n");

    printf("Number of page faults: %d\n", pageFaults);
    printf("Page fault rate: %.2f%\n", (float)pageFaults/noOfPages * 100);

    printf("Number of page Hits: %d\n", noOfPages - pageFaults);
    printf("Page Hit rate: %.2f%\n", (float)(noOfPages - pageFaults)/noOfPages * 100);

    printf("\n");

    return 0;
}