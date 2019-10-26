//Trapezoidal Method

#include <stdio.h>
#include <math.h>
#define f(x) (1/(1+pow(x,2)))
int main(){
	int i,n;
	float a,b,h,r,s;
        FILE *fp;  //file pointer
        fp=fopen("26.txt","w"); //write mode
	printf("Enter the lower limit :"); //Lower limit of integration
	scanf("%f",&a);
	printf("Enter the upper limit :"); //upper limit of integration
	scanf("%f",&b);
	printf("Enter the number of segments(interval) :"); //number of intervals you want 
	scanf("%d",&n);
	float x[n+1],y[n+1];
	fprintf(fp,"\t\tTrapezoidal Method\n");
	h=(b-a)/n ;
	fprintf(fp,"\nLower Limit : %f \n Upper limit : %f \n Number of intervals :%d",a,b,n);  
    r=f(a)+f(b) ;  //sum of two function of limit
	fprintf(fp,"\nX           Y values :\n");
	for(i=0;i<=n;i++) {
		x[i] = a +i*h; 
		y[i] = f(x[i]) ;    
		fprintf(fp,"%f    %f\n",x[i],y[i]);
	}
	for(i=1;i<n;i++){
		r+=2*y[i]; //sum from y1,y2,....yn-1
	}

	r=(r*h)/2;     // Formula to evaluate the area or the integration of given eqn
	fprintf(fp,"\nFinal Integration : %f",r);
	fclose(fp); //closing file 
	return 0;
}
