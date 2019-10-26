//Gauss Jordan Elimination Method
#include <stdio.h>
int main(){
	FILE *fp; //creating file
	fp=fopen("7.txt","w"); //file in write mode 
	fprintf(fp,"Gauss Jordan Elimination Method\n\n");
	int i,j,k,n;
	float A[20][20],c;
	printf("Enter the order of matix :"); //order of matrix
	scanf("%d",&n);
	for (i=0;i<n;i++){
		for(j=0;j<n+1;j++){
			printf("A[%d][%d] : ",i,j); //input the coeff of matrix
			scanf("%f",&A[i][j]);
		}
	}
	for (i=0;i<n;i++){
		for(j=0;j<n+1;j++){ 
		fprintf(fp,"%0.f\t",A[i][j]);  //print matrix	
		}
		fprintf(fp,"\n"); //escape sequence
	}
	
	//Gauss Jordan Elimination Method
	
	for(i=0;i<n;i++){      
		for(j=0;j<n+1;j++){
			if(i!=j)        
			c=A[j][i]/A[i][i];   //performing row operations to form required diagonal matrix
			for(k=0;k<n+1;k++){
				A[j][k]=A[j][k]-(c*A[i][k]);  //GJ Method Formula				
			}
		}
	}
	fprintf(fp,"\nMatrix Form :\n");
	for (i=0;i<n;i++){
		for(j=0;j<n+1;j++){
		fprintf(fp,"%f\t",A[i][j]);   //Print gauss jordan method matrix form	
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n\n");
	fprintf(fp,"The Solution is:\n");
	for(i=0;i<n;i++){
		fprintf(fp,"\nx[%d] = %f",i,A[i][n]/A[i][i]);  //print the solution 
	}
	fclose(fp); //closing file
	return 0;
}
