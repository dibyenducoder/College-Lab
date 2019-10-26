/*Sum and avg of four numbers*/

#include <stdio.h>
 
int main()
{
    float a,b,c,d,sum;
    float avg;
 
    printf("Enter first number :");
    scanf("%f",&a);
    printf("Enter second number :");
    scanf("%f",&b);
     printf("Enter third number :");
     scanf("%f",&c);
      printf("Enter forth number :");
      scanf("%f",&d);
 
    sum=a+b+c+d;
    avg= (float)(a+b+c+d)/2;
 
    printf("\nSum of %f , %f  ,   %f  ,   %f is = %f",a,b,c,d,sum);
    printf("\nAverage of %f   ,   %f    ,    %f and     %f is = %f",a,b,c,d,avg);
 
    return 0;
}
