#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef long long unsigned int  F;


long int count;
F fibonacci(F n){
   count++;
   if(n==0)
   return 0;
 else if (n==1)
   return 1;
else 
  return (fibonacci(n-1)+fibonacci(n-2));
}

int main(){
 FILE *fp;
 fp=fopen("fibonacci_iteration.txt","w");
 int n,i;
double time_taken;
 printf("Enter the number of terms:\n");
 scanf("%d",&n);
 fprintf(fp,"Terms       Fibonacci     Recursive_calls     Time_taken\n");
 for(i=0;i<=n;i++){
 time_taken =((double)clock()) / CLOCKS_PER_SEC ;
 fprintf(fp,"%d        %llu            %ld          %f\n",i,fibonacci(i),count,time_taken);
}
count=0;
return 0;
}
