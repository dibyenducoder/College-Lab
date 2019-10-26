/* Reverse the floating point number 
   for example 
   i/p : 123.4567 
   output should be like that 321.7654 */  
 
#include <stdio.h>

int main ()
{
int no,dec,rn=0,rn1=0,remdr1,remdr;
char dot;
printf("Enter a floating number  : ");       //Please input like 123.567 as I mean there should be a dot (.) between numbers . 
scanf("%d%C%d", &no, &dot, &dec);
	while ( no!=0)
	{
		remdr=no%10;
		rn=rn*10+remdr;
		no=no/10;
	}
		while ( dec!=0)
	{
		remdr1=dec%10;
		rn1=rn1*10+remdr1;
		dec=dec/10;
	}
	
	   if (dot =='.')
	   
	printf("Reverse any real no. with floating point of your input : %d%c%d ", rn1,dot,rn);
	 
	 else printf("Invalid Input");
	
return 0;
}
