/* WAP to find the accuracy between the sum (1/n + 1/n + … n times) and 1 */
#include <stdio.h>
int main()
{
	int i;
	float sum,n;
	printf("Enter a number :");
	scanf("%f",&n);
	for (i=0;i<n;i++)
		sum+=1/n;
		sum=(1-sum)*100;
     printf("Accuracy : %f",sum);
	
	return 0;
}
