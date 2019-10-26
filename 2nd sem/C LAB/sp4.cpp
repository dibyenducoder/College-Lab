
/* Maximum and minimum of three numbers */
#include <stdio.h>
int main ()
{
	float num1,num2,num3,max,min;
	printf ("Enter the three numbers  \n");
	printf ("Enter the 1st number : ");
	scanf ("%f",&num1);
	printf ("Enter the 2nd number : ");
	scanf ("%f",&num2);
	printf ("Enter the 3rd number : ");
	scanf ("%f",&num3);
	
	
	if (num1 > num2)
	{
		max=num1;
		min=num2;
	}
	else 
	 {
	 	max=num2;
	 	min=num1;
	 }
	 if (max < num3 )
	 {
	 	max=num3;
	 }
	 else if (min > num3)
	   {
	   	min = num3;
	   }
	  
	   printf ("The maximum number of 3 numbers is  %f \n",max);
	   printf ("The minimum number of 3 numbers is  %f \n",min);
	   
	   return 0;
	 
	}
