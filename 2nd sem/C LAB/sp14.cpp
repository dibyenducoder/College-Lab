/*WAP to convert integer to equivalent binary */
#include <stdio.h>

int main()
     {
     int n, i, j, binno=0,dn;

     printf("\n\nConvert Decimal to Binary:\n ");
     printf("-------------------------\n");

     printf("Enter a number to convert : ");
     scanf("%d",&n);

     dn=n;
     i=1;

      for(j=n;j>0;j=j/2)
       {
        binno=binno+(n%2)*i;
        i=i*10;
        n=n/2;
       }
     
     printf("\nThe Binary of %d is %d.\n\n",dn,binno);
     return 0;
 }
 
