#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int checksum(int fl){
 int i,n,sum=0,temp;
 char in[100];
 scanf("%s",in);
 if(strlen(in)%2!=0)
   n=(strlen(in)+1)/2;	
 else
   n=strlen(in)/2;
 for(i=0;i<n;i++){
  temp=in[i*2];
  temp=temp*256+in[(i*2)+1];
  sum+=temp;
 }
 if(fl==1){
  printf("Enter the checksum:\n");
  scanf("%x",&temp);
  sum+=temp;
 }
 if(sum%65536!=0){
   n=sum%65536;
   sum=(sum/65536)+n;
 }
 sum=65535-sum;
 return sum;
}

void main(){
printf("Enter 1:Encode 2:Decode 3:Exit \n");
int ch,sum=0;
do{
scanf("%d",&ch);
switch(ch){
case 1:
 printf("Enter a string:\n");
 sum=checksum(0);
 printf("Checksum to append is :%x\n",sum);
 break;
case 2:
 printf("Enter a string:\n");
 sum=checksum(1);
 if(sum!=0){
  printf("Invalid checksum\n");
 }
 else{
  printf("Valid checksum\n");
 }
 break;
 case 3:
  break;
 default:
  printf("Invalid option");
}
}while(ch!=3);
}
