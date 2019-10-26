#include<stdio.h>
#include<math.h>

int main (void)
{
	double f,inp,k,kk;
	double z;
	int c=1;
	printf("Enter any number (Fraction are even allowed )  :");
    scanf("%lf",&inp);
	f=modf(inp,&k);
	while(k>0)
	{
		z=z+((int)k%10)*pow(10,-c++);
		k=k/10;
		k=(int)(k);
		}
	//	c=0;
		while((int)(f*10)!=0)
		{
			
			f*=10;
			kk=kk+((int)f)*pow(10,c++);
			f-=(int)f;
			}
			
			
			printf("%lf",kk+z);
			return 0;	
}
