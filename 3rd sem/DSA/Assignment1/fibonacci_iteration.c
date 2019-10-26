#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef long long unsigned int  F;


long int count;
F fibonacci(F n){
    count++;
    int i;
    F f1 = 0;
    F f2 = 1;
    F fi;
 
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;

    for(i = 2 ; i <= n ; i++ ) {
        fi = f1 + f2;
        f1 = f2;
        f2 = fi;
    }
    return fi;
}

int main(){
FILE *fp;
fp=fopen("fibonacci_iteration.txt","w");
 int n,i;
double time_taken;
 printf("Enter the number of terms:\n");
 scanf("%d",&n);
 fprintf(fp,"Terms       Fibonacci     iteration__calls     Time_taken\n");
 for(i=0;i<=n;i++){
 time_taken =((double)clock()) / CLOCKS_PER_SEC ;
fprintf(fp,"%d                   %llu                %ld                   %f\n",i,fibonacci(i),count,time_taken);
}
count=0;
printf("\n\nOutput File: fibonacci_iteration.txt\n");
return 0;
}
