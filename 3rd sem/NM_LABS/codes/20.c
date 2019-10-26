//Newton Raphson Multivariable

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#define X(x,y) 2*(x)*(x) -y//Equation 1
#define Y(x,y) (y)*(y) -2*x//Equation 2
#define F1(x,y) 4*x//Diff Eq1 wrt x
#define G1(x,y) -1//Diff Eq1 wrt y
#define F2(x,y) -2//Diff Eq2 wrt x
#define G2(x,y) 2*y//Diff Eq2 wrt y
//Newton_Raphson Method for non linear multivariable polynomials
int main(){
  FILE *fp;//creating File pointer
  fp=fopen("NewtonRaphson_multivariate.txt","w");
  fprintf(fp,"\n\tNewton Raphson Multivariable\n");
  double x1=0,y1=0,y2=0,x2=0,x=0,y=0,f=0,g=0,f1=0,f2=0,g1=0,g2=0;
  int i=1;
  printf("\nEnter the initial value of x: ");
  scanf("%lf",&x);    //initial value of x
  printf("\nEnter the initial value of y: ");
  scanf("%lf",&y);      //initial value of y
  fprintf(fp,"X		Y	  Error(X)	    Error(Y)");	
  fprintf(fp,"\n%.5lf		%.5lf		%.5lf		%.5lf",x,y,fabs(x-x1),fabs(y-y1));
  f=X(x,y);    //calculating the values
  g=Y(x,y);
  f1=F1(x,y);
  f2=F2(x,y);
  g1=G1(x,y);
  g2=G2(x,y);
  x1= x-((f*g2-g*f2)/(f1*g2-f2*g1));
  y1= y-((g*f1-f*g1)/(f1*g2-f2*g1));
  fprintf(fp,"\n%.5lf		%.5lf		%.5lf		%.5lf",x1,y1,fabs(x1-x),fabs(y-y1));
  printf("\n\n");
  do {          //Newton Raphson Multivariable calculation
    f=X(x1,y1);
    g=Y(x1,y1);
    f1=F1(x1,y1);
    f2=F2(x1,y1);
    g1=G1(x1,y1);
    g2=G2(x1,y1);
    x2= x1-((f*g2-g*f2)/(f1*g2-f2*g1));
    y2= y1-((g*f1-f*g1)/(f1*g2-f2*g1));       //updating statement
    
   if(fabs(x1-x2)<0.00001 && fabs(y1-y2)<0.00001)        //checking for error margin
   {
    fprintf(fp,"\n\nX = %6.5lf",x1);
    fprintf(fp,"\n\nY = %6.5lf",y1);
    break;        //breaking the iteration
   }
   else
   {
   	fprintf(fp,"\n%.5lf		%.5lf		%.5lf		%.5lf",x2,y2,fabs(x1-x2),fabs(y1-y2));
    x1=x2;          //updating values
    y1=y2;
   }
   i++;
  }while(1);
  
  fprintf(fp,"\n\nNo of iteration=%d",i);
  fclose(fp);        //closing file
  return 0;
}
