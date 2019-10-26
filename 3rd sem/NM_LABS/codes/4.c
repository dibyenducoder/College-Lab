//Fixed Point Iteration
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define f(x) (pow(x,2)-x-6)  //given eqn
#define g(x) (sqrt(x+6))    //differentiate the given eqn w.r.t x

int main(){
	FILE *fp;
     fp=fopen("fixedpointresults.txt","w");//opens a file in write to display all the secant method results
     fprintf(fp,"Fixed Point Iteration\n");
	float r0,r1,error;
	int itr=0;
	printf ("Enter the approx value of desired root :");
	scanf("%f",&r0);
	fprintf(fp,"---------------------------------------\n");
	fprintf(fp,"\nItr.    Rn     Rn+1      Error\n");  //Rn is the previous root and Rn+1 is the current root
	fprintf(fp,"---------------------------------------\n");
	do{
		r1=g(r0);  //differentiate w.r.t x
		error=fabs(r1-r0);
		fprintf(fp,"\n%d    %f     %f      %f\n",itr++,r0,r1,error);
		r0=r1;  //the current root becomes previous root
	}while(error > 0.000001);
	fprintf (fp,"\nApproxiamte Root Of the Eqn:%f",r0);
	fclose(fp); //closing file
	return 0;
}
