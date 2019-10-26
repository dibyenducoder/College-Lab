//simpson's 1/3 Rule
#include<stdio.h>
#include <math.h>
#define f(x) log(x)
 
int main(){
	
      FILE *fp;  //creating file pointer 
      fp=fopen("25.txt","w");
      fprintf(fp,"Simpson's 1/3 Rule\n\n");
      int i = 0, value;
      float x[30], y[30], lower_boundary, upper_boundary, width, m = 0, n = 0, result;
      printf("\nEnter value for Lower Boundary:\t");  //lower limit of integration
      scanf("%f", &lower_boundary);   
      printf("\nEnter value for Upper Boundary:\t");  //upper limit of integration
      scanf("%f", &upper_boundary);  
      printf("\nEnter value for Width:\t");   
      scanf("%f", &width); 
      value = (upper_boundary - lower_boundary) / width;   
      if(value % 2 == 1){
            value = value + 1;      //if value is odd number then it will be just increment by 1
      }
      width = (upper_boundary - lower_boundary) / value;  //step length
      fprintf(fp,"\nModified Values:\n");     //Updating the values
      fprintf(fp,"\nMid Point:\t%d\n", value);   
      fprintf(fp,"\nWidth:\t%f\n", width);
      fprintf(fp,"\nY values\n");

      while(i <= value){
            x[i] = lower_boundary + i * width;
            y[i] = f(x[i]);
            fprintf(fp,"\nY[%d] = %f", i, y[i]);
            i++;
      }
      i = 1;

      while(i < value){
            if(i % 2 == 1){
                  m = m + y[i];  //m is the odd terms 
            }
            else{
                  n = n + y[i]; //n is the evem terms
            }
            i++;
      }
      result = width / 3 * (y[0] + y[value] + 4 * m + 2 * n);   //calculation for simpson's 1/3rd method
      fprintf(fp,"\n\nSimpson's Rule Integration:\t%f\n", result);
      return 0;
}
 
