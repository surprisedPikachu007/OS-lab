//banker's algorithm for deadloack avoidance
#include <stdio.h>

int main() {
    int noOfResources, noOfProcess;

    noOfResources = 3;
    noOfProcess = 5;

    int allocation[noOfProcess][noOfResources];
    int max[noOfProcess][noOfResources];
    int available[noOfResources];

    allocation[0][0] = 0;
    allocation[0][1] = 1;
    allocation[0][2] = 0;
    allocation[1][0] = 2;
    allocation[1][1] = 0;
    allocation[1][2] = 0;
    allocation[2][0] = 3;
    allocation[2][1] = 0;
    allocation[2][2] = 2;
    allocation[3][0] = 2;
    allocation[3][1] = 1;
    allocation[3][2] = 1;
    allocation[4][0] = 0;
    allocation[4][1] = 0;
    allocation[4][2] = 2;

    max[0][0] = 7;
    max[0][1] = 5;
    max[0][2] = 3;
    max[1][0] = 3;
    max[1][1] = 2;
    max[1][2] = 2;
    max[2][0] = 9;
    max[2][1] = 0;
    max[2][2] = 2;
    max[3][0] = 2;
    max[3][1] = 2;
    max[3][2] = 2;
    max[4][0] = 4;
    max[4][1] = 3;
    max[4][2] = 3;

    available[0] = 3;
    available[1] = 3;
    available[2] = 2;

    /*printf("Enter the number of resources: ");
    scanf("%d", &noOfResources);
    printf("Enter the number of processes: ");
    scanf("%d", &noOfProcess);

    printf("Enter the allocation matrix: ");
    for (int i = 0; i < noOfProcess; i++) {
        for (int j = 0; j < noOfResources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }

    printf("Enter the max matrix: ");
    for (int i = 0; i < noOfProcess; i++) {
        for (int j = 0; j < noOfResources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the available matrix: ");
    for (int i = 0; i < noOfResources; i++) {
        scanf("%d", &available[i]);
    }*/

    //displaying the input as process number allocation matrix space max matrix space availble matrix
    printf("\nProcess\tAllocation\tMax\tAvailable\n");
    for (int i = 0; i < noOfProcess; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < noOfResources; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\t\t");
        for (int j = 0; j < noOfResources; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        if(i == 0) {
            for (int j = 0; j < noOfResources; j++) {
                printf("%d ", available[j]);
            }
        }
        printf("\n");
    }

    int need[noOfProcess][noOfResources];
    
    for(int i=0;i<noOfProcess;i++)
    {
        for(int j=0;j<noOfResources;j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }

    //displaying the need matrix
    printf("\nNeed matrix:\n");
    for (int i = 0; i < noOfProcess; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < noOfResources; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
}