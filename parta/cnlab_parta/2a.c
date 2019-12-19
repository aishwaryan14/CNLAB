#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

int main(){
 int i,x,n=5,count=0,drop=0,cap=5,out=2,inp[10]={0};
 for(i=0;i<5;i++){
   inp[i]=rand()%10;
 }
 printf("Iteration\tReceived\tSent\tDropped\tRemaining\n");
 for(i=0;count||i<n;i++){
  printf("%d\t",i+1);
  printf("%d\t",inp[i]);
  printf("%d\t",MIN(inp[i]+count,out));
  if((x=inp[i]+count-out)>0){
	if(x>cap){
	    count=cap;
 	    drop=x-cap;
 	}
	else{
	    count=x;
	    drop=0;		   	
	}
   }
   else{
	count=0;
	drop=0;
   } 
  printf("%d\t%d\n",drop,count);
  }
}
