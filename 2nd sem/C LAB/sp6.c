/*Emulate Tree */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int choice;
	printf("Difference between if-else-then and switch statements\n ");
	while(1)
	{
		printf("\nPress 1 : if-else statement of sp3.c \n");
		printf("Press 2 : switch statements of sp3.c \n");
		printf("Press 3: if-else-then statements of sp4.c \n");
		printf("Press 4: switch statements of sp4.c \n");
		printf("Press 5: Exit Program \n");
		
		printf("Enter your choice : ");
		scanf("%d",&choice);
		
		if(choice==5)
		   
		   exit(0);
	       
	       
       if(choice==1)
       {
       	printf("\nThis is the if-else-then statements of sp3.c ,that is Converting integer Numbers to Words \n");
       	
       	int len=0,x,one,ten,th,hundred;
        int no;
        char *ones[] = {"", "Zero", "One", "Two", "Three", "Four","Five", "Six", "Seven", "Eight", "Nine"};
        char *tens[] = {"", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen","Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        char *tens2[] = {"","","Ten","Twenty", "Thirty", "Forty", "Fifty","Sixty", "Seventy", "Eighty", "Ninety"};
        printf("Enter a number:");
        scanf("%d",&no);
        x = no;
        while(no!=0)
		{
         no = no/10;
          len++;
        }
        if(len==1)
		{
         printf("Number in words is: %s",ones[x+1]);
        }  
         else if(len==2)
		 {
          if(x>19)
		  { 
          one = x%10;
          ten = x/10;
           printf("Number in words is: %s %s",tens2[ten+1],ones[one+1]);
          }
         else
		 {
          one = x%10;
           printf("Number in words is: %s",tens[one+1]);
         }
    }
          else if(len==3)
		  {
           hundred = x/100;
           ten = (x%100)/10;
            one = ((x%100)%10);
           if(x%100 > 10 && x%100 < 20)
		   {
              printf("Number in words is: %s hundred %s",ones[hundred+1],tens[one+1]);
           }
            else
			{
                printf("Number in words is: %s hundred %s %s",ones[hundred+1],tens2[ten+1],ones[one+1]);
            }
          }
             else if(len==4)
			 {
              th = x/1000;
               hundred = (x%1000) / 100;
               ten = ((x%1000) % 100)/10;
               one = (((x%1000) % 100)%10);
               if(x%1000 > 10 && x%1000 < 20)
			   {
                 printf("Number in words is: %s thousand %s",ones[th+1],tens[one+1]);
                }
               else if(x%1000>19 && x%1000<100)
			   {
                  printf("Number in words is: %s thousand %s %s",ones[th+1],tens2[ten+1],ones[one+1]);
               }
                else if(x%1000 > 110 && x%1000 < 120)
				{
                 printf("Number in words is: %s thousand %s hundred %s",ones[th+1],ones[hundred+1],tens[one+1]);
                }
               else
			   {
                 printf("Number in words is: %s thousand %s hundred %s %s",ones[th+1],ones[hundred+1],tens2[ten+1],ones[one+1]);
                }
              }
               else
			   {
                 printf("please enter a number below 10000");
               }
	   }
	

                if(choice==2)
				{
					printf("\nThis is the switch statements of sp3.c ,that is Converting integer Numbers to Words\n");
					int number,digit,second_digit,i=3,j=2;
                    printf("Enter any integer number : ");     /* Enter number from 1 to 9999*/
                    scanf("  %d",&number);
                    digit=number/1000;
                    printf ("\nThe number in word is : ");
                    while(number!=0)
                   {

                     switch(digit)
                        {
                         

                         case 1:printf("One");break;
                          case 2:printf("Two");break;
                          case 3:printf("Three");break;
                         case 4:printf("Four");break;
                         case 5:printf("Five");break;
                         case 6:printf("Six");break;
                         case 7:printf("Seven");break;
                         case 8:printf("Eight");break;
                          case 9:printf("Nine");break;
                          }


                         if(i==1)
                            break;
                          if(number>=1000)
                               {
                             printf(" Thousand ");
                                }
                              number=number%1000;

                              digit=number/100;

                                 j=j-1;
                                 if(j==0)
                                     {

                                        if(number>=100)
                                            {
                                              printf(" Hundred ");
                                               number=number%100;
                                               }
                                          second_digit=number/10;

                                          if(second_digit!=1)
                                              {
                                               if(i==1)
                                                break; 
                                               switch(second_digit)
                                                   {

                                                case 2:printf(" Twenty ");break;
                                                 case 3:printf(" Thirty ");break;
                                                 case 4:printf(" Forty ");break;
                                                 case 5:printf(" Fifty ");break;
                                                case 6:printf(" Sixty ");break;
                                                 case 7:printf(" Seventy ");break;
                                                  case 8:printf(" Eighty ");break;
                                                 case 9:printf(" Ninety ");break;
                                                 }
                                                  digit=number%10;

                                              }
                                                   else
                                                      {
                                                          switch(number)
                                                             {	
                                                              case 11:printf(" Eleven ");break;
                                                              case 12:printf(" Twelve ");break;
                                                              case 13:printf(" Thirteen ");break;
                                                               case 14:printf(" Fourteen ");break;
                                                               case 15:printf(" Fifteen ");break;
                                                                case 16:printf(" Sixteen ");break;
																case 17:printf(" Seventeen ");break;
                                                                 case 18:printf(" Eighteen ");break;
                                                                  case 19:printf(" Nineteen ");break;
                                                                }
                                                                     break;

                                                          }

                                                  }
                                            i=i-1;
                                      }
					
								} 
								
								
								if(choice==3)
								{
								
							    printf("\nThis is if-then-else statements of sp4.c that is finding min and max of 3 numbers :\n");
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
	  
	                                       printf ("\nThe maximum number of 3 numbers is  %f \n",max);
	                                        printf ("\nThe minimum number of 3 numbers is  %f \n",min);
	                      
	                            }
	                              if(choice==4)
	                              {
	                              	printf("\nThis is switch statements of sp4.c that is finding min and max of 3 numbers :\n");
	                                // printf("This is if-then-else statements of sp4.c that is finding min and max of 3 numbers :");
							     	float num1,num2,num3,max,min,c,d;
	                                printf ("\nEnter the three numbers  \n");
	                                 printf ("Enter the 1st number : ");
	                                 scanf ("%f",&num1);
	                                printf ("Enter the 2nd number : ");
	                                 scanf ("%f",&num2);
	                                 printf ("Enter the 3rd number : ");
	                                  scanf ("%f",&num3);
                                     c=((num1>num2)&&(num1>num3))?1:2;
                                     d=((num1<num2)&&(num1<num3))?1:2;
                                      switch((int)c)
                                      {
										  
                                          case 1:
                                          printf("\nMaximum number is %f\n",num1);break;
                                         case 2:c=(num2>num3)?num2:num3;
                                                 printf("\nMaximum number is %f\n",c);
                                                 break;
                                           
										}
									 switch((int)d)
									 {
									 	case 1: printf("\nMinimum number is %f\n",num1);break;
									 	case 2: d=(num2<num3)?num2:num3;
									 	        printf ("\nMinimun number is %f\n",d);
									 	        break;
									  } 
							 }
							 if (choice >=6)
							 {
							 
                                 printf("\nInvalid choice.\n");
 
                                 printf("\nPress any one of 5 choices (1 or 2 or 3 or 4 or 5)...\n");
				}
			}
}
                                      
								  
								               
