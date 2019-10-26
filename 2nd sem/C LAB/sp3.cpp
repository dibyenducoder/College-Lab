/*Convert number to words using while statements without using array */

#include<stdio.h>
int main()
{
int number,digit,second_digit,i=3,j=2;
printf("Enter any integer number : ");     // Enter number from 1 to 9999
scanf("  %d",&number);
digit=number/1000;
while(number!=0)
{

switch(digit)
{
case 1:printf("one");break;
case 2:printf("two");break;
case 3:printf("three");break;
case 4:printf("four");break;
case 5:printf("five");break;
case 6:printf("six");break;
case 7:printf("seven");break;
case 8:printf("eight");break;
case 9:printf("nine");break;
}

if(i==1)
break;
if(number>=1000)
{
printf(" thousand ");
}
number=number%1000;

digit=number/100;

j=j-1;
if(j==0)
{



if(number>=100)
{
printf(" hundred ");
number=number%100;
}
second_digit=number/10;




if(second_digit!=1)
{
if(i==1)
break; 
switch(second_digit)
{

case 2:printf(" twenty ");break;
case 3:printf(" thirty ");break;
case 4:printf(" forty ");break;
case 5:printf(" fifty ");break;
case 6:printf(" sixty ");break;
case 7:printf(" seventy ");break;
case 8:printf(" eighty ");break;
case 9:printf(" ninety ");break;
}
digit=number%10;

}
else
{
switch(number)
{	
case 11:printf(" eleven ");break;
case 12:printf(" twelve ");break;
case 13:printf(" thirteen ");break;
case 14:printf(" fourteen ");break;

case 15:printf(" fifteen ");break;

case 16:printf(" sixteen ");break;

case 17:printf(" seventeen ");break;
case 18:printf(" eighteen ");break;

case 19:printf(" nineteen ");break;


}
break;

}

}
i=i-1;
}

return 0;	
}


