/*Convert integer to roman */
#include <stdio.h>
  int main ()
   {
      int num;
     printf("Enter your input:");
     scanf("%d", &num);
     printf("Roman Number: ");
    while (num > 0)
	 {
      if (num >= 1000)          //M is 1000
	    {
                      
           printf("M");           
            num = num - 1000;     //M-1000
          }
		   else if (num >= 500)      //D is 500
		   {
                       
            if (num >= 900)            //CM is 900
			 {
                 printf("CM");
                  num = num - 900;    
               }
			    else 
			   {
                 printf("D");        //D is 500
                  num = num - 500;
                       
			    }
              } 
				else if (num >= 100)      //C is 100
				 {
                       
                     if (num >= 400)      // CD is 400
					  {
                                printf("CD");
                                num = num - 400;
                        } else {
                                printf("C");
                                num = num - 100;
                        }
                }
				 else if (num >= 50)      //L is 50
				 {
                   if (num >= 90)       //XC is 90
				    {
                        printf("XC");
                         num = num - 90;
                    }
						 else
						  {
                            printf("L");  // L is 50
                            num = num - 50;
                        }
                } 
				else if (num >= 9)     
				{
                   if (num >= 40)     //XL is 40
				    {
                       printf("XL");
                        num = num - 40;
                        } 
						else if (num == 9)     //IX is 9
						 {
                          printf("IX");
                          num = num - 9;
                        } 
						else 
						{
                         printf("X");    // X is 10
                         num = num - 10;
                        }
                } 
				else if (num >= 4)
				 {
                   if (num >= 5) 
				   {
                    printf("V");
                    num = num - 5;
                    } 
						else
						 {
                           printf("IV");
                           num = num - 4;
                        }
                }
				 else
				  {
                   printf("I");
                   num = num - 1;
                }
        }
        printf("\n");
        return 0;
  }
