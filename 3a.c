#include<stdio.h>
#include<stdlib.h>

struct rr{
    int pno,btime,sbtime,wtime,Lst;
}p[10];

int main(){
    int pp=-1,ts,flag,count,ptm=0,i,n,twt=0,totttime=0;
    printf("Round Robbing Scheduling\n");
    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the slice time");
    scanf("%d",&ts);
    
    printf("Enter the burst time for each processes\n");
    for(i=0;i<n;i++){
        printf("Enter the burst time for process %d",i+1);
        scanf("%d",&p[i].btime);
        p[i].wtime= p[i].Lst=0;
        p[i].pno= i+1;
        p[i].sbtime = p[i].btime;
    }
    
    printf("Scheduling...\n");
    
    do{
        flag=0;
        for(i=0;i<n;i++){
            count = p[i].btime;
            if(count>0){
                flag =-1;
                count = (count>=ts)? ts:count;
                printf("\n Process %d from%d to %d",p[i].pno,ptm,ptm+count);
                ptm += count;
                p[i].btime-=count;
                
                if(pp!=i){
                    pp=i;
                    p[i].wtime += ptm - p[i].Lst - count;
                    p[i].Lst = ptm;
                }
            }
        }
    }while(flag == -1);
        
    printf("\n Process\t Waiting Time\t Turnaround Time \n");
    for(i=0;i<n;i++){
        totttime = p[i].wtime +p[i].sbtime;
        twt += p[i].wtime;
        printf("%d\t%d\t\t%d\n",p[i].pno,p[i].wtime,totttime);
        }
    printf("\n Average Waiting Time: %.2f\n",(float)totttime/n);
    return 0;
}

