/*Extract the numbers of a given integer number*/

#include<stdio.h>
int main()
{
  int num,temp,factor=1;

  printf("Enter a number: ");
  scanf("%d",&num);

  temp=num;
  while(temp)
  {
      temp=temp/10;
      factor = factor*10;
  }

  printf("Each digits of given number are:  \n");
  
  while(factor>1)
  {
      factor = factor/10;
      printf("%d \n",num/factor);
     
      num = num % factor;
  }

  return 0;
}

