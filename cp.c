//simulation of cp linux command
#include<stdio.h>

int main(int argc, char *argv[]) {
    if(argc == 3) {
        FILE *source = fopen(argv[1], "r");
        if(source == NULL) {
            printf("Error: source file not found\n");
            return 1;
        }
        FILE *dest = fopen(argv[2], "w");
        char c;
        while((c = fgetc(source)) != EOF) {
            fputc(c, dest);
        }
        
        fclose(source);
        fclose(dest);
    }
    else if(argc < 3) {
        printf("Too few arguments\n");
    }
    else {
        printf("Too many arguments\n");
    }

    return 0;
}