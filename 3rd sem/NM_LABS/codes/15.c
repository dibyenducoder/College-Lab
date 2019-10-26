
//Multi Point Method
#include <stdio.h>
#include <math.h>
#define f(x) (exp(-x)-x) //Given Eqn
#define fd(x) ((-1)*exp(-x)-1) //differentiate f(x) wrt x

int main(){
	FILE *fp;  //creating file pointer
	fp=fopen("15.txt","w"); //write mode
	float r0,r1,r_1,error=0,order,errorold;
	fprintf(fp,"Multi Point Method\n");
	int itr=1;
	printf("Enter the approx value of r0:");  //Enter the desired root
	scanf("%f",&r0);
	fprintf(fp,"__________________________________________________\n");
	fprintf(fp,"\nItr.    Ri     Ri+1     Error      Order\n");
	fprintf(fp,"--------------------------------------------------\n");
	do{
		errorold=error;      //current error becomes previous error
		r_1=r0-(f(r0)/2*fd(r0));   
		r1=r0-(f(r0)/fd(r_1)); //Finding Root Method 
		error=fabs(r1-r0);    //absolute error
		fprintf(fp,"\n%d    %f    %f   %f    ",itr++,r0,r1,error);
		order=log(error)/log(errorold); //order of convergence
		if (order==0) fprintf(fp,"    -----\n");   //1st order becomes null
		else fprintf(fp,"    %f",order);
		r0=r1;  //current root becomes old root
	}while(error > 0.00005);
	fprintf(fp,"\nAbsolute Error :%f",r0);
    fclose(fp);  //closing file 
	return 0;
}
