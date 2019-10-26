// C Program to interpolate using 
// newton forward interpolation 
#include <stdio.h> 
#define MAX 20

FILE *fp; //creating file pointer

// calculating u mentioned in the formula 
float u_cal(float u, int n) 
{ 
	int i;
	float temp = 1; 
	if (n == 0) return 1;
	else {
		for (i = 0; i <= (n-1) ; i++) 
			temp = temp * (u - i); 
		return temp;
	}
} 

// calculating factorial of given number n 
int fact(int n) 
{ 
	int i;
	int f = 1;
	if (n==0) return 1;
	if (n==1) return 1;
	else { 
		for (i = 2; i <= n; i++) 
			f *= i; 
		return f;
	}
} 

int main() {
    fp=fopen("17.txt","w");    //write mode 
    fprintf(fp,"\t\t\tNewton Forward Interpolation\n\n\n");
	// Number of values given 
	int i,j,n; 
	float x[MAX],y[MAX][MAX],value;
	printf("Enter how many records you want to keep :");  //record the file
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nEnter the value of x%d :",i);     //value of x . example sinx = sin 45
		scanf("%f",&x[i]);
		printf("Enter the value of f(x%d) :",i);   //value of f(x) , example 0.7071
		scanf("%f",&y[i][0]);
	}
	printf("\nEnter the value of X for finding f(x) :");
	scanf("%f",&value);
	
	
	// Calculating the forward difference 
	// table 
	for ( i = 1; i < n; i++) { 
		for ( j = 0; j < n - i; j++) 
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1]; 
	} 
	fprintf(fp,"\tX\t\tY");
//	int k;
	// Displaying the forward difference table 
	for( i = 1 ; i < n ; i++){
		fprintf(fp,"\t\tD%dY",i);
	}
	fprintf(fp,"\n");
	
	for ( i = 0; i < n; i++) { 
		fprintf(fp,"%f\t",x[i]); 
		for ( j = 0; j < n - i; j++) 
			fprintf(fp,"%f\t", y[i][j] );
				
		fprintf(fp,"\n"); 
	} 
	
	// initializing u and sum 
	//float sum = y[0][0]; 
	float sum = 0 ;
	float u = (value - x[0]) / (x[1] - x[0]); 
	
	for (i = 0 ; i <= n ; i++) { 
		sum = sum + ((u_cal(u, i) * y[0][i]) / fact(i)); 
	} 

	fprintf(fp,"\n\nValue at %f is %f\n",value,sum); //value of desired x 
	fclose(fp);   //closing file 
	return 0; 
} 

