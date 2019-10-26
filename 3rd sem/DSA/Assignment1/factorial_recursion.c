#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef long long unsigned F;
long int count;
F factorial(F x){
    count++;
    int i,f=1;
    if(x > 1){
      return x*factorial(x-1);
   }
   else {
        return 1;
    }
}

int main(){
FILE *fp;
  fp=fopen("factorial_recursion.txt","w");
  F fact;
  int n,i;
  double time_taken;
  printf("            FACTORIAL IN RECURSION  METHOD\n");
  printf("Enter the number of terms:");
  scanf("%d",&n);
// printf("%llu",factorial(n));
  fprintf(fp,"Terms   Factorial    Soln    Iterative_calls     Time_taken\n");
  for(i=1;i<=n;i++){
         fact=factorial(i);
         time_taken=((double)(clock()))/ CLOCKS_PER_SEC ;
         fprintf(fp,"%d       %d!           %llu             %ld                  %f\n",i,i,fact,count,time_taken);
}
count=0;
printf("\nOUTPUT FILE : factorial_recursion.txt\n");
return 0;
}
