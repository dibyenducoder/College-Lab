#include <stdio.h>

int main()
{
	float x,nx,f,df;
	printf("Solve : x^6=729 \n");
	nx=729;
	printf("%f \n",nx);
	
	do{
		x=nx;
		f=x*x*x*x*x*x-729;
		df=6*x*x*x*x*x;
		nx=x-(f/df);
		printf("%f \n",nx);
	} while((x-nx)>=0.0001 || (x-nx)<= -0.0001);
	
	printf("\n x=%f",nx);
	return 0;
}
