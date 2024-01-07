#include<stdio.h>
#include<unistd.h>
main(){
    int pid,pid1,pid2;
    pid = fork();
    if(pid==-1){
        printf("Error In Process Creation\n");
        exit(1);
    }
    if(pid!=0){
        pid1 = getpid();
        printf("The parents processing ID is %d\n",pid1);
    }
    else{
        pid2 = getpid();
        printf("The child processing ID is %d",pid2);
    }
}
