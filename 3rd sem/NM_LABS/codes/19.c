//Newton Raphson Method

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) (exp(-x)-x)  //Given Equation
#define fd(x) ((-1)*exp(-x)-1)  //Differentaite f(x) w.r.t x
#define fdd(x)  (exp(-x))    //differentiate fd(x) w.r.t x
 
int main(){
	FILE *fp;  //Creating File pointer
	fp=fopen("newtonraphson.txt","w");      //writing mode
	float r0,r1,error=0,errorold,order,converge; 
	int itr=1;
	fprintf(fp,"Newton Raphson Method\n");
	printf("Enter the approx value of r0:");     //Enter your desired root 
	scanf("%f",&r0);
	converge=(f(r0)*fdd(r0))/(pow(fd(r0),2)) ;    //convergence of NR method 
	if (converge > 1) {
		fprintf(fp,"The Solution Does not converge !!!"); exit(1);
	}
	fprintf(fp,"__________________________________________________________________\n");
	fprintf(fp,"\nItr.    Rn         Rn+1               Error              Order\n");
	fprintf(fp,"---------------------------------------------------------------------\n");
	do{
		errorold=error;       
		r1=r0-(f(r0)/fd(r0));         //NR method of finding the root formula
		error=fabs(r1-r0);
		fprintf(fp,"\n%d    %f     %f      %f     ",itr++,r0,r1,error);
		order=log(error)/log(errorold);   //order of error
		if (order == 0) printf("       ----\n");
		else fprintf(fp,"       %f\n",order);     //first order becomes void 
		r0=r1;         //current root becomes previous root and solve it until
	}while(error > 0.00005);  //error of getting desired root  
	fprintf (fp,"\nThe Approx root :%f",r0);     
	fclose(fp); //closing the file
	return 0;
}
