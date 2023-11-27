//Round Robin
#include <stdio.h>
int main(){
    int i,limit,total=0,x,counter=0,tq;
    int wt=0,tatime=0,at[10],bt[10],temp[10];
    float avg_wt,avg_tat;
    printf("\nEnter Total no. of Process: ");
    scanf("%d",&limit);
    x=limit;
    for(i=0;i<limit;i++){
        printf("Enter details of P%d\n",i+1);
        printf("Arival time: ");
        scanf("%d",&at[i]);
        printf("Burst time: ");
        scanf("%d",&bt[i]);
    }
    printf("Enter time Quntum: ");
    scanf("%d",&tq);
    printf("\nProcess  bt  tat  wt\n");
    for(total=0,i=0;x!=0;){
        if(temp[i]<=tq && temp[i]>0){
            total=total+temp[i];
            temp[i]=0;
            counter=1;
        }else if(temp[i]>0){
            temp[i]=temp[i]-tq;
            total=total+tq;
        }
        if(counter==1 && temp[i]==0){
            x--;
            printf("\nProcess[%d]\t%d\t%d\t\t%d",i+1,bt[i],total-at[i],total-at[i]-bt[i]);
            wt=wt+total-at[i]-bt[i];
            tatime=tatime+total-at[i];
            counter=0;
        }
        if(i==limit-1){
            i=0;
        }else if (at[i+1]<=total){
            i++;
        }else{
            i=0;
        }
    }
    avg_wt=wt*1.0/limit;
    avg_tat=tatime*1.0/limit;
    printf("\n avg wait= %f",avg_wt);
    printf("\n avg tat= %f",avg_tat);
    return 0;
}