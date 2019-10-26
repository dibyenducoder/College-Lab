
/* Maximum and minimum of four numbers */
#include <stdio.h>
int main ()
{
	float num1,num2,num3,num4,max,min;
	printf ("Enter the four numbers  \n");
	printf ("Enter the 1st number : ");
	scanf ("%f",&num1);
	printf ("Enter the 2nd number : ");
	scanf ("%f",&num2);
	printf ("Enter the 3rd number : ");
	scanf ("%f",&num3);
	printf ("Enter the 4th number : ");
	scanf ("%f",&num4);
	
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
	   if (max<num4)
	   {
	   	max=num4;
	   	
	   }
	   else if (min>num4)
	   {
	   	min=num4;
	   }
	   printf ("The maximum number of 4 numbers is  %f \n",max);
	   printf ("The minimum number of 4 numbers is  %f \n",min);
	   
	   return 0;
	 
	}
