//Power Method

#include<stdio.h>
#include<math.h>
#include <stdlib.h>
int main(){
        FILE *fp; //file pointer 
	fp=fopen("21.txt","w"); //write mode
	fprintf(fp,"\t\tPower Method\n\n");
	int i,j,n;
	float A[40][40],x[40],z[40],e[40],zmax,emax;      //zmax =max eigen value , emax =max error
	printf("\n Enter the order of matrix: ");     //order of matrix (Square matrix)
	scanf("%d", &n);
	printf("\nEntre the matrix elements row-wise \n");  //enter matrix in row wise
	for(i=1;i<=n;i++){
  		for(j=1;j<=n;j++){
  		printf("A[%d][%d]= ",i,j);
  		scanf("%f",&A[i][j]);
  	}
}    
    //Your Matrix in your File
    fprintf(fp,"\nYour Matrix\n");
    for(i=1;i<=n;i++){
  		for(j=1;j<=n;j++){
  	    fprintf(fp,"%f    ",A[i][j]);
  	}
  	fprintf(fp,"\n"); //escape sequence
}
	printf("\n Enter the column vector\n");    //initial value of eigen vectors
	for(i=1;i<=n;i++){
   		printf("\nX[%d]= ",i);
   		scanf("%f",&x[i]);
	}
	    //Your column vector ,also called RHS of Matrix
	    fprintf(fp,"\nColumn Vector\n");
		for(i=1;i<=n;i++){
   		fprintf(fp,"%f\n",x[i]);
	}
       fprintf(fp,"\nX		Eigen value         	Error\n");
	do{
  		for(i=1;i<=n;i++){   //calculate the new eigen vectors
        	z[i]=0;
        	for(j=1;j<=n;j++){
           		z[i] = z[i]+A[i][j]*x[j];
       		}
   	}
	zmax=fabs(z[1]);   //initialize the maximum elements
	for(i=2;i<=n;i++){       //finding the maximim elements
		if((fabs(z[i]))>zmax)
		zmax = fabs(z[i]);
	}
	for(i=1;i<=n;i++){
		z[i]=z[i]/zmax;
	}
	for(i=1;i<=n;i++){
		e[i]=0;
		e[i]=fabs((fabs(z[i]))-(fabs(x[i])));
	}
	emax=e[1];
	for(i=2;i<=n;i++){      // Getting maximum error
   		if(e[i]>emax)
   		emax =e[i];
	}
	for(i=0;i< n;i++){
		fprintf(fp,"%f     ",z[i]);
		fprintf(fp,"%f 		          %f\n",zmax,emax);
}
	for(i=1;i<=n;i++){        //updating the eigen vectors
    		x[i]=z[i];
    	}
}while(emax>0.001);   //limitation of error

fprintf(fp,"\n The required eigen value is %f",zmax);
fprintf(fp,"\n\n The required eigen vector is : \n");
for(i=1;i<=n;i++){
        fprintf(fp,"X[%d]     ",i);
	fprintf(fp,"%f\n",z[i]);      //new value of eigen vectors
}
fclose(fp);
}
	
