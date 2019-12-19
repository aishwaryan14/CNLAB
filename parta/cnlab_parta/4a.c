#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 999

int cost[20][20];

void dijkstras(int n, int source){
 int visited[20],dist[20],pred[20],i,j,count=0,nextnode,min;
 for(i=0;i<n;i++){
  visited[i]=0;
  dist[i]=cost[source][i];
  pred[i]=source;
 }
 visited[source]=1;
 dist[source]=0;
 count=1;
 while(count<n){
   min=INF;
   for(i=0;i<n;i++)
     if(dist[i]<min && !visited[i]){
        min=dist[i];
        nextnode=i;
     }
   visited[nextnode]=1;
   for(i=0;i<n;i++)
     if(!visited[i])
       if(min+cost[nextnode][i]<dist[i]){
            dist[i]=min+cost[nextnode][i];
            pred[i]=nextnode;
       }
   count++;
  }

  for(i=0;i<n;i++)
    if(i!=source){
       printf("\nDistance of %d from %d is %d\n",i,source,dist[i]);
       printf("Path:%d",i);

       j=i;
       do{
         j=pred[j];
         printf("<--%d",j);
       }while(j!=source);
     }
 
}

void main(){
int i,j,n,source;
printf("ENter the no of nodes:\n");
scanf("%d",&n);
printf("Enter the cost matrix:\n");
for(i=0;i<n;i++){
 for(j=0;j<n;j++){
  scanf("%d",&cost[i][j]);
  if(cost[i][j]==0 && i!=j){
	cost[i][j]=INF;
  }
}}
printf("Enter the source node:\n");
scanf("%d",&source);
dijkstras(n,source);
}
