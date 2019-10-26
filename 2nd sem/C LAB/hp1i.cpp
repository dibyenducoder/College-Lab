#include<stdio.h>
#include<math.h>

int main (void)
{
	double f,inp,k,kk;
	int z;
	printf("Enter any number (Fraction are even allowed )  :");
    scanf("%lf",&inp);
	f=modf(inp,&k);
	while(k>0)
	{
		z=z*10+(int)k%10;
		k=k/10;
		k=(int)(k);
		}
		while((int)(f*10)!=0)
		{
			/*printf("f %lf %lf \n",f,kk);*/
			f*=10;
			kk=kk*0.1+(int)f;
			f-=(int)f;
			}
			
			kk*=0.1;
			printf("%lf",kk+z);
			return 0;	
}
