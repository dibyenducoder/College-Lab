#include <stdio.h>
#include <math.h>
#define PI 3.1415926
int main()
{

  int height,width,half_height,row,column,f,sinvalue,cosvalue;
  float x,extent;
  extent=2*PI;
  height=30;
  width=40;
  //row=0;column=0;;
  half_height=height/2;

   printf("Graph of both sinx and cosx : [* stands for sin,# stands for cos]\n");
    printf("\n");
    printf("\n");
    printf("\n");
   for(row=0;row<=height;row++)
   {

      x=0;

      f=(int)(half_height-row);

      for(column=0;column<=width-1;column++)
	  {

      sinvalue=(int)(half_height*sin(x));

       cosvalue=(int)(half_height*cos(x));
       
       
	   x=x+extent/width;

       if(f==sinvalue) printf("*");

          else if(f==cosvalue) printf("#");

           else if(f==0) printf("-");

       else printf(" ");

     }

printf("\n");}

return 0;}

