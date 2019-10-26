#include <stdio.h>

void Factors(int num);
void primefactors(int n);

int main(void)
{
	int num;
	printf("Enter a number :");
	scanf("%d",&num);
	printf("Factors of a number:");
	Factors(num);
	printf("\n");
	printf("Prime Factors of a number :");
	primefactors(num);
	printf("\n");
}

void Factors (int num)
{
	int i;
	for(i=1; i<=num; i++)
    {
        /* 
         * If num is exactly divisible by i
         * Then i is a factor of num
         */
        if(num % i == 0)
        {
            printf("%d, ",i);
        }
    }
}
 void primefactors (int num)
 {
	int i;
	for( i = 2; num!=1; i++)
		while( num%i == 0 )
		{
			printf("%d ", i);
			num = num/i;
		}
}
 
