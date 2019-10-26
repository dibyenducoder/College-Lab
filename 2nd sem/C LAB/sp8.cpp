#include <stdio.h>
#include <math.h>
#define PI 3.1415926

int main()
{
	int degree,n;
	float rad,term,sum,mysine;
	printf("Degree \t mysin \t \t mycos \t \t mytan \n  ");
	for(degree=0;degree<=360;degree=degree+15)
	{
		rad=degree*PI/180;
		n=1;
		term=rad;
	/*	sum=rad;
		while (term >=0.0001 || term<=-0.0001)
		{
			term=-0.5*term*rad*rad/(2*n*n+n);
			sum=sum+term;
			n++;
		}
			mysine=sum;*/
			printf("%d \t %0.6f \t %0.6f \t %0.6f \t  \n",degree,sin(rad),cos(rad),tan(rad));
		}
		return 0;
	}
	

