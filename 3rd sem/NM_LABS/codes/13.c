//LU Decompose for solving Linear Equation
#include <stdio.h>

int main(){
	FILE *fp; //file pointer creation
	fp=fopen("13.txt","w"); //write mode
	fprintf(fp,"LU DECOMPOSE\n");
	int i,j,k,n;
	float sum=0.0,mat[20][20],l[20][20]={0},u[20][20]={0},b[20],z[20]={0},x[20]={0};
	printf("Enter the order of matrix :");  //order of matrix
	scanf("%d",&n);
	printf("\nEnter the coefficient of matrix :\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%f",&mat[i][j]);
	   }
	}
	//Display Your matrix in file
	fprintf(fp,"Your Matrix :\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fprintf(fp,"%f    ",mat[i][j]);
	   }
	   fprintf(fp,"\n");
	}
	printf("\n\nThe contstant term :\n");  //AX=B ,where B is the constant term
	for(i=0;i<n;i++){
		printf("b[%d]:",i);
		scanf("%f",&b[i]);
	}
	
	//Display Your Constant Value
	fprintf(fp,"Constant Terms :\n");
	for(i=0;i<n;i++){
		fprintf(fp,"%f\n",b[i]);
	}
	
	
	//LU decomposition
	//upper matrix
	for(i=0;i<n;i++){
		for(k=i;k<n;k++){
			sum=0;
			for(j=0;j<i;j++){
				sum+=l[i][j]*u[j][k];  //sum of terms
			}
			u[i][k]=mat[i][k]-sum;   //upper triangular method
		}
		//Lower matrix
		for(k=i;k<n;k++){
			if(i==k){
				l[i][i]=1;
			}
			else{
				sum=0;
				for(j=0;j<i;j++){
					sum+=l[k][j]*u[j][i];
				}
				l[k][i]=(mat[k][i]-sum)/u[i][i];      //Lower triangular method
			}
		}
	}
	fprintf(fp,"\nL:\n\n");   //Lower Traingualar Matrix
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fprintf(fp,"%f\t",l[i][j]);
		}
		fprintf(fp,"\n");
	}
	fprintf(fp,"\nU:\n\n");   //Upper Traingualar Matrix
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			fprintf(fp,"%f\t",u[i][j]);
		}
		fprintf(fp,"\n");
	}
	
	//Finding Z in LZ=B        //Forward  substituition Method
	for(i=0;i<n;i++){
		sum=0;
		for(j=0;j<i;j++){
			sum+=l[i][j]*z[j];
		}
		z[i]=(b[i]-sum)/l[i][i];
		fprintf(fp,"z[%d] : %f\n",i,z[i]);
	}
	//Finding X in UX=Z       //Back substituition Method
	for(i=n-1;i>=0;i--){
		sum=0;
		for(j=n-1;j>i;j--){
			sum+=u[i][j]*x[j];
		}
		x[i]=(z[i]-sum)/u[i][i];
	//	printf("\nx[%d] : %f\n",i,x[i]);  
	}
	//Print X-->the soln 
	fprintf(fp,"\nThe Set of soln :\n");
	for (i=0;i<n;i++){
		fprintf(fp,"\nX[%d]=%f",i,x[i]);
	}
	fclose(fp);
	return 0;
}
