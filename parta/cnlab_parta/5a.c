#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N strlen(g)

char t[28],cs[28],g[]="10001000000100001";
int a,e,c;

void xor(){
for(c=1;c<N;c++)
   cs[c]=((cs[c]==g[c])?'0':'1');
}

void crc(){
for(e=0;e<N;e++)
   cs[e]=t[e];
do{
if(cs[0]=='1')
   xor();
for(c=0;c<N-1;c++)
   cs[c]=cs[c+1];
cs[c]=t[e++]; 

}while(e<=a+N-1);
}

int main(){
printf("Enter the data:");
scanf("%s",t);
printf("\nGenerating polynomial:%s\n",g);
a=strlen(t);
for(e=a;e<a+N-1;e++)
   t[e]='0';
printf("Modified dataword:%s\n",t);
crc();
printf("Checksum:%s\n",cs);
for(e=a;e<a+N-1;e++)
   t[e]=cs[e-a];
printf("Codeword is:%s\n",t);

printf("Test error detection 0:yes 1:no \n");
scanf("%d",&e);

if(e==0){
do{
	printf("Enter the position to insert error:\n");
	scanf("%d",&e);
 }while(e==0||e>a+N-1);
 t[e-1]=(t[e-1]=='0')?'1':'0';
 printf("Erroneous data%s\n",t);
}
crc();
int flag=0;

for(e=0;e<a+N-1;e++){
if(cs[e]=='1'){
 flag=1;
 break;
 }
}
if(flag==1){
 printf("Error detected\n");
}
else{
printf("No error detected");
}
}
