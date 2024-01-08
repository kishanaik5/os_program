#include<stdio.h>
#include<dirent.h>
struct dirent *dptr;

int main(int args, char *argv[]){
    char buff[100];
    DIR *dirp;
    printf("Enter the directory name\n");
    scanf("%s",buff);
    if (((dirp=opendir(buff))==NULL){
        printf("The directory name doesn't exist\n");
        exit(1);
    }
    while(dptr=readdir(dirp)){
        printf("%s\n",dptr->d_name);
    }
    closedir(dirp);
}
