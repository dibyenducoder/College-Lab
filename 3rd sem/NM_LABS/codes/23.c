//Runge Kutta (2nd Order) Method 
#include<stdio.h>
#include<math.h>
FILE *fp;
/*Define the RHS of the first order differential equation here(Ex: dy/dx=f(x,y))  */
double df(double x, double y){
    return (y-x);
}
double f(double x)//declaring y=?
{
 return x + 1 - 0.5 * exp(x);
}
main(){
    fp=fopen("23.txt","w"); //file pointer
    fprintf(fp,"\tRunge Kutta Method (2nd Order) \n");
    int i;
    double x,y,x0,y0,h,k1,k2;
    printf("Enter the initial condition for y: ");
    scanf("%lf",&y0);
    printf("Enter the initial condition for x: ");
    scanf("%lf",&x0);
    printf("Enter the value of x for which y is required: ");
    scanf("%lf",&x);
    printf("Enter the step-width h: ");
    scanf("%lf",&h);
    fprintf(fp,"x\t\ty(approx)\t\ty(exact)\tError\n");
    fprintf(fp,"__________________________________________________________________________\n");
    //Begin Runge-Kutta Routine
    while((x-x0)>0.0000000001){
        k1=h*df(x0,y0);
        k2=h*df(x0+h,y0+k1);
        y=y0+0.5*(k1+k2);
        fprintf(fp,"%lf\t%lf\t%lf\t%lf\n",x0,y0,f(x),fabs(y-f(x)));
        y0=y;
        x0=x0+h;
    }
    fprintf(fp,"%lf\t%lf\t%lf\t%lf\n",x0,y0,f(x),fabs(y-f(x)));
    fprintf(fp,"__________________________________________________________________________\n");
    fprintf(fp,"The value of y is %lf\n\n",y);
    fclose(fp); //closing file
}
