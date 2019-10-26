//Modified Euler's Method
#include <stdio.h> 
#include <math.h>
   float df(float x, float y) {      //differential function
      return y - x;    // dy/dx
   }
float f(float x) {    //given function
   return x + 1 - 0.5 * exp(x);
}
int main() {
	FILE *fp; //creating file pointer
   fp=fopen("14.txt","w"); //write mode
   fprintf(fp,"\tModified Euler Method\n\n");
   float x0, y0, x1, y1, h, x, m1, m2, error;
   printf("Enter initial value x : ");    //Initial value of x0
   scanf("%f", & x0);
   printf("Enter final value x : ");  //Final value of x
   scanf("%f", & x);
   printf("Enter initial value y : "); //Initial value of y
   scanf("%f", & y0);
   printf("Enter difference/step height : "); //step height
   scanf("%f", & h);
   fprintf(fp,"%10s %10s %10s %10s\n", "x", "y(approx)", "y(exact)", "error"); 
   fprintf(fp,"-----------------------------------------------------\n");
   while (x0 < x) {             //Modfied Euler Method Calculation 
      m1 = df(x0, y0);
      y1 = y0 + h * m1;
      x1 = x0 + h;
      m2 = df(x1, y1);
      y0 = y0 + h * 0.5 * (m1 + m2);
      x0 = x1;
      error = fabs(y0 - f(x0)); //Absolute error
      fprintf(fp,"%10.6f %10.6f %10.6f %10.6f\n", x0, y0, f(x0), error); //printing calculation
   }
   fclose(fp); //closing file
   return 0;
}
