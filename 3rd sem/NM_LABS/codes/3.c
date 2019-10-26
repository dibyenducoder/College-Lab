//Chebshev Method
#include <stdio.h>
#include <math.h>
#define f(x) (exp(-x)-x) //given eqn
#define fd(x) ((-1)*exp(-x)-1)  //derivative of f(x) wrt x
#define fdd(x) (exp(-x))      //derivative of fd(x) wrt x

int main(){
	FILE *fp;
    fp=fopen("chebyshev.txt", "w");//opens a file in write mode to display all the chebyshev results
    fprintf(fp,"Chebyshev Method\n");
	int itr=1;
	float r0,r1,error=0,errorold;
	printf("Enter the Initial value:"); //Desired Root of finding chebyshev root
	scanf("%f",&r0);
	//if(fd(r0)>1) // Convergence Checking
	fprintf(fp,"_________________________________________\n");
	fprintf(fp,"Itr    Ri     Ri+1     Error\n");
	fprintf(fp,"------------------------------------------\n");
	do{
		errorold=error; // current error becomes old error
		r1=r0 - (f(r0)/fd(r0)) - (pow(f(r0),2)*fdd(r0))/(2*(pow(fd(r0),3)));  //Chebyshev Method to find the root
		error=fabs(r1-r0);  //absolute error
		fprintf (fp,"\n%d   %f    %f    %f\n",itr++,r0,r1,error); 
		r0=r1; //current root becomes old root 
	}while(error > 0.00005);
	fprintf(fp,"Absolute Error :%f",r0);
	fclose (fp); //closing file 
	return 0;
}
