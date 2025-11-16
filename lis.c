#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    DIR *dir = opendir(".");
    if (!dir){
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    struct stat fileStat;

    while ((entry = readdir(dir)) != NULL){
        if (stat(entry->d_name, &fileStat) == 0){
            // Success: file_stat now contains valid data
            printf("%s\t%d bytes\n", entry->d_name, fileStat.st_size);
        }else{
            // Failure: file doesn't exist, no permissions, etc.
            perror(entry->d_name);
        }
    }

    closedir(dir);
    return 0;
}
