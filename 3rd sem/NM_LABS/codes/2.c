/*BISECTION METHOD*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) (exp(-x)-x)

int main(){
  FILE *fptr ;
  fptr = fopen("2.txt","w");             //creating the file pointer for output
  float a,b,error,m,mold;
  int i=0;
printf("                                         BISECTION METHOD\n");
fprintf(fptr,"\t\t\t\t\tBISECTION METHOD\t\t\t\n");
 printf("Enter the Interval :");                         //Enter the intervals from the user
 scanf("%f%f",&a,&b);    //a and b are so chosen that f(a) & f(b) are of opposite sign
 fprintf(fptr,"_______________________________________________________________________________________________\n");
 fprintf(fptr,"Ite\t  a\t          b\t         mid\t\t           f(m)\t\t           f(a)*f(m)           error\n");
fprintf(fptr,"------------------------------------------------------------------------------------------------\n");
 do{
    mold=m;            // To find the  midpoint
    m=(a+b)/2;
    fprintf(fptr,"%d\t\t%f\t\t%f\t\t %f\t      %f\t\t       %f\t\t",i++,a,b,m,f(m),(f(a)*f(m)));
 
  if  (f(m)==0){        
     fprintf(fptr,"Root is %f\n",m);
   }
  else if (f(a)*f(m) < 0) { b=m ;}
  else a=m;
  error=fabs(m-mold);           //Absolute Error
  fprintf(fptr," %f\n",error);
} 
  while (error > 0.0005);
fprintf(fptr,"--------------------------------------------------------------------------------------------------\n");
printf("\n");
 fprintf(fptr,"\nApproximate Root is %f\n",m);
fclose(fptr);
return 0;
}
