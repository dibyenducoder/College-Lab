
//Secant Method
#include <stdio.h>
#include<math.h>
#define f(x) (exp(-x)-x)

int main(){
	FILE *fp; //File Pointer
	fp=fopen("Secant Method.txt","w");  //write mode 
	fprintf(fp,"Secant Method\n");
	int itr=1;
	float r0,r1,r2,error,errorold,order;
	printf("Enter the interval of A and B:");      //Enter the interval between two points 
	scanf("%f%f",&r0,&r1);
	fprintf(fp,"___________________________________________________________________\n");
	fprintf(fp,"\nItr.     Rn-1       Rn       Rn+1       Error       Order\n");
	fprintf(fp,"---------------------------------------------------------------------\n");
	do{
		r2=(r0*f(r1)-r1*f(r0))/(f(r1)-f(r0));  //next root finding method
		errorold=fabs(r2-r1); //absolute previous error finding
		error=fabs(r1-r0);
		fprintf(fp,"\n%d      %f    %f     %f      %f    ",itr++,r0,r1,r2,error);
		r0=r1;  //current root becomes previous root
		r1=r2;  //next root becomes current root
		order=log(error)/log(errorold); //order of convergence 
		if (order==0) fprintf(fp,"    ----\n");    //first order is null
		else fprintf(fp,"     %f\n",order);  //rest order of convergence
	}while(error > 0.0005);  
	fprintf(fp,"\nThe approx Root:%f",r1); //next root ,actually it is r2 value
	fclose(fp);
	return 0; 
}
