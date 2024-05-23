#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter n");
    scanf("%d",&n);

    int at[n],bt[n],pid[n];
    for(int i=0;i<n;i++){
        printf("Enter arrival time for p[%d]",(i+1));
        scanf("%d",&at[i]);
    }
    for(int i=0;i<n;i++){
        pid[i]=i+1;
    }

    for(int i=0;i<n;i++){
        printf("Enter burst time for p[%d]",(i+1));
        scanf("%d",&bt[i]);
    }

    int ct[n],tat[n],wt[n];
    int t1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(at[i]>at[j]){
                t1=at[i];
                at[i]=at[j];
                at[j]=t1;

                t1=bt[i];
                bt[i]=bt[j];
                bt[j]=t1;

                t1=pid[i];
                pid[i]=pid[j];
                pid[j]=t1;
            }
        }
    }

    // Sort pid based on arrival time and then process ID (using bubble sort)
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(at[j] == at[j + 1] && bt[j] > bt[j + 1]){
                // Swap arrival time
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;
                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
                // Swap process IDs
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(i==0){
            ct[0]=bt[0];
            tat[0]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
        }
        else if(ct[i-1]<at[i]){
            ct[i]=at[i]+bt[i];
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
        }
        else{
            ct[i]=ct[i-1]+bt[i];
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
        }
    }

    float tatavg=0,wtavg=0;
    printf("\nPID\t\tAT\tBT\t\tCT\t\tTAT\t\tWt");
    for(int i=0;i<n;i++){
        printf("\npid[%d]:%d\tat[%d]:%d\t bt[%d]:%d\tct[%d]:%d \t tat[%d]:%d \t wt[%d]:%d",(i+1),pid[i],(i+1),at[i],(i+1),bt[i],(i+1),ct[i],(i+1),tat[i],(i+1),wt[i]);
    }

}