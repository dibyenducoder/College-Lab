//Jacobi Elimination Method
#include<stdio.h> 
#include<math.h>
#define ESP 0.0001
    /* Given Equations */
#define X1(x2,x3) -1*((1-2*(x2)+3*(x3))/5)
#define X2(x1,x3) -1*((-2-3*(x1)+1*(x3))/9)
#define X3(x1,x2) -1*((-3+2*(x1)-1*(x2))/-7)
int main(){
  FILE *fp;                        //file pointer created
  fp=fopen("10.txt","w");          //opening  file in write mode
  fprintf(fp,"\tJacobi Elimination Method\n");
  double x1=0,x2=0,x3=0,y1,y2,y3,error; 
  int i=0;     //intialising i with 0
  fprintf(fp,"\n   x1\t\t   x2\t\t   x3\t\t   Error\n"); // printing in file 
     // printing the value of x1,x2,x3 
  do {
   y1=X1(x2,x3);
   y2=X2(x1,x3);
   y3=X3(x1,x2);
   if(fabs(y1-x1)<ESP && fabs(y2-x2)<ESP && fabs(y3-x3)<ESP ) { //checking the condition 
     fprintf(fp,"\n\nx1 = %.3lf",y1);  // printing x1
     fprintf(fp,"\n\nx2 = %.3lf",y2);  //printing x2
     fprintf(fp,"\n\nx3 = %.3lf\n",y3);  //printing x3
     i = 1;
   }
   else{
     x1 = y1;
     x2 = y2;
     x3 = y3; 
     fprintf(fp,"\n%f\t%f\t%f\t%f\n",x1,x2,x3,error-x1);  //printing the value in file 
   }
   error=x1;
  }while(i != 1);
  fclose(fp); //closing file
  return 0;
}
