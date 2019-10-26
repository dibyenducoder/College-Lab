//Regula Falsi Method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define f(x) (exp(-x)-x)

int main(){
  FILE *fptr ;
  fptr = fopen("22.txt","w");             //creating the file pointer for output
  float a,b,error=0,c,cold;
  int i=0;
printf("                                         REGULA FALSI METHOD\n");
fprintf(fptr,"\n\t\t\t\t\tREGULA FALSI METHOD\t\t\t\n");
 printf("Enter the Interval :");                         //Enter the intervals from the user
 scanf("%f%f",&a,&b);
 fprintf(fptr,"________________________________________________________________\n");
 fprintf(fptr,"Ite\t  a\t          b\t         c\t           f(c)\t           error\n");
fprintf(fptr,"-----------------------------------------------------------------------------------------------------------\n");
 do{
    cold=c;            // To find the certain value of c 
    c=(a*f(b) - b*f(a))/(f(b)-f(a));
    fprintf(fptr,"\n%d\t\t%f\t\t%f\t\t %f\t      %f",i++,a,b,c,f(c));
 
  if  (f(c)==0){
     fprintf(fptr,"\nRoot is %f\n",c);
   }
  else if (f(a)*f(c) < 0) { b=c ;}
  else a=c;
  error=fabs(c-cold);           //Absolute Error
 if(i==1) {
     fprintf(fptr,"            -----\n");
}
else
  fprintf(fptr,"              %f\n",error);

  // cold=c;
 }  while (error > 0.0005);
 fprintf(fptr,"-------------------------------------------------------------------\n");
 printf("\n");
 fprintf(fptr,"\nApproximate Root is %f\n",c);
 printf("\noutput file : 22.txt \n");
fclose(fptr);  //closing the file
return 0;
}
