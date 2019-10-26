#include<stdio.h>

int main()	
{
     float number,fracpart,fraction;
      int intpart,digit,digit2,intpart2;
        scanf("%f",&number);
            intpart=(int)number;
            fracpart=number-intpart;
            fraction=fracpart;
       while(fraction!=0)
      {
           fracpart=fracpart*10;
           fraction=fracpart-(int)fracpart;
       }

         while(intpart!=0)
            {
              digit=intpart%10;
              printf("%d",digit);
              intpart=intpart/10;

              }

             if(fracpart!=0)
              {
               printf(".");
               intpart2=fracpart;
               while(intpart2!=0)	
                 {
                 digit2=intpart2%10;
                 printf("%d",digit2);
                 intpart2=intpart2/10;
                  }


           }


         return 0;
}
