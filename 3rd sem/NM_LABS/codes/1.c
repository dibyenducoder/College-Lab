//Bairstow Method
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define max 10
FILE *fp; //creating file pointer

/*Root Nature */
int root(float a,float b){
	float disc;
	disc=a*a - 4*b;
	if(disc<0){
	disc=-disc; 
	fprintf(fp,"%f+%fi",-a/2,sqrt(disc)/2); 
	fprintf(fp,", %f-%fi",-a/2,sqrt(disc)/2); 
   }
   else {
   	fprintf(fp,"%f+%f",-a/2,sqrt(disc)/2); 
   	fprintf(fp,", %f-%f",-a/2,sqrt(disc)/2); 
   }
}
int main(){
	fp=fopen("1.txt","w");  //write mode
	float a[max],b[max],c[max],d[max],error,errorp,errorq,p,q,rp,sp,rq,sq,r,s;
	int i,degree,itr=1;
	printf("Enter the highest degree of polynomial :");
	scanf("%d",&degree);
	fprintf(fp,"Bairstow Method\n");
	
    for(i=degree; i>=0; i--){
      printf("\n Enter coefficient of x^%d:  ",i);
     if(i<degree)  {
     scanf("%f",&a[degree-1-i]);
     a[degree-1-i]/=a[degree];
  }
  else   scanf("%f",&a[i]);
}
  a[degree]=1;
	printf("\nThe Quadratic Factor of poly :\n x^2 + Px + Q\n");
	printf("Enter the initial guess of P and Q :");
	scanf ("%f%f",&p,&q);
	error=1;
	fprintf(fp,"__________________________________________\n");
	fprintf(fp,"\nItr.   p    q     error      Root\n");
	fprintf(fp,"---------------------------------------\n");
	fprintf(fp,"%d    %f    %f     ----    ",itr++,p,q);
	root(p,q); //nature of root calling function
	fprintf(fp,"\n");
	
	/*Bairstow Method Algorithm */
	while(error > 0.0000005){ 
		for(i=0;i<=degree-3;i++){
			if(i==0) b[i]=a[i]-p;
			else if(i==1)  b[i]=a[i]-p*b[i-1]-q;
			else b[i]=a[i]-p*b[i-1]-q*b[i-2];
		}
		r=a[degree-2] - p*b[degree-3] - q*b[degree-4];
		s=a[degree-1] - q*b[degree-3];
		
		for(i=0;i<=degree-3;i++){
			if(i==0) c[i]=-1;
			else if(i==1) c[i]=-b[i-1] + p;
			else c[i]=-b[i-1] -p*c[i-1] - q*c[i-2]; 
		}
		rp=-b[degree-3] - p*c[degree-3] - q*c[degree-4] ;
		sp=-q*c[degree-3];
		
		for(i=0;i<=degree-3;i++){
			if(i==0) d[i] =0;
			else if(i==1) d[i]=-1;
			else  d[i]=-b[i-2]-p*d[i-1]-q*d[i-2];
		}
		rq=-b[degree-4] - p*d[degree-3] -q*d[degree-4];
		sq=-b[degree-3] - q*d[degree-3];
		
		errorp=(s*rq - r*sq)/(rp*sq - sp*rq);  p+=errorp;
		errorq=(r*sp - s*rp)/(rp*sq - sp*rq);  q+=errorq;
		
		errorp=fabs(errorp);
		errorq=fabs(errorq);
		
		if(errorp>errorq)  error=errorp;
		else               error=errorq;
		
	fprintf(fp,"\n%d    %f    %f      %f    ",itr++,p,q,error);
	root(p,q);
	fprintf(fp,"\n");
	}
	fprintf(fp,"\nThe Roots are :");
	root(p,q);
	fclose(fp);
	return 0;
}
