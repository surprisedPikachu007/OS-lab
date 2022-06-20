//simulation of the ls command
#include<stdio.h>
#include<dirent.h>

int main(int argc, int *argv[]) {
    //list the contents of the current directory
    DIR *dir = opendir(".");
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if(entry->d_name[0] != '.') {
            printf("%-20s", entry->d_name);
        }
    }
    closedir(dir);
    return 0;
}