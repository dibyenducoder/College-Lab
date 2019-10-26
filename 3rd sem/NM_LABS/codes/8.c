//Gauss Jordan Elimination To perform Inverse of Matrix of given matrix
#include <stdio.h>
int main(){
	FILE *fp; //creating file pointer
	fp=fopen("8.txt","w"); //write mode file
	fprintf(fp,"Gauss Jordan Elimination To perform Inverse of Matrix of given matrix\n\n");
	int i,j,k,n;
	float a[20][20],ratio,an; 
	printf("Enter the order of matrix :"); //order of matrix
	scanf("%d",&n);
	fprintf(fp,"Enter your matrix n X n :\n"); //Input the matrix of "n" order
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%f",&a[i][j]);
		}
	}
	fprintf(fp,"Your matrix  :\n"); //Display the matrix of "n" order
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fprintf(fp,"%f    ",a[i][j]);
		}
		fprintf(fp,"\n");
	}
	for(i=0;i<n;i++){             //For identity Matrix
		for(j=n;j<2*n;j++){
			if(i==(j-n)){
				a[i][j]=1;    //1s on the diagonal and 0s everywhere else.
			}
			else a[i][j]=0;
		}
	}
	for(i=0;i<n;i++){         //Applying Gauss Jordan Elimination Method
		for(j=0;j<n;j++){
			if(i!=j){                      
				ratio=a[j][i]/a[i][i];
				for(k=0;k<2*n;k++){
					a[j][k]-=a[i][k]*ratio;  //performs row operations to form 
					                           //required identity matrix out of the input matrix
				}
			}
		}
	}
	for(i=0;i<n;i++){       //For inverse Matrix Calculation
		an=a[i][i];
		for(j=0;j<2*n;j++){
			a[i][j]=a[i][j]/an;
		}
	}
	fprintf(fp,"\n\nEnter the augmented matrix :\n");
	for(i=0;i<n;i++){
		for(j=0;j<2*n;j++){
			fprintf(fp,"%f  ",a[i][j]); //print resulted matrix
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"\n\n");
	fprintf(fp,"Inverse matrix :\n");
	for(i=0;i<n;i++){
		for(j=n;j<2*n;j++){
			fprintf(fp,"%f  ",a[i][j]); //Print resulted inverse matrix
		}
		fprintf(fp,"\n"); //escape sequence
	}
	return 0;
}
