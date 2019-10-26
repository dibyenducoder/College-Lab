#include <stdio.h>
#include <time.h>

long int count;
long factorial(int x){
    count++;
    int i,f=1;
    for(i=x;i>=1;i--)
    f=f*i;
    return f;
}

int main(){
  long fact;
  int n,i;
  double time_taken;
  printf("            FACTORIAL IN ITERATION METHOD\n");
  printf("Enter the number of terms:");
  scanf("%d",&n);
  printf("Terms   Factorial    Soln    Iterative_calls     Time_taken\n");
  for(i=1;i<=n;i++){
         fact=factorial(i);
         time_taken=((double)(clock()))/ CLOCKS_PER_SEC ;
         printf("%d       %d!           %ld             %ld                  %f\n",i,i,fact,count,time_taken);
}
printf("\n");
count=0;
return 0;
}
