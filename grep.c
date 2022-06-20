//simulation of grep command
#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[]) {
    char temp[1000];
    FILE *file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("File not found\n");
        return 0;
    }
    
    char *pattern = argv[2];

    while(!feof(file)) {
        fgets(temp, 1000, file);
        if(strstr(temp, pattern)) {
            printf("%s", temp);
        }
    }
    fclose(file);
    return 0;
}
