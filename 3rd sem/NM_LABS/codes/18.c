//Newton Forward Differentiation
#include<stdio.h>
#include<math.h>

int main (){
        FILE *fp; //creating file pointer
        fp=fopen("18.txt","w"); //write mode
	int n,i,j;
	fprintf(fp,"\nNewton Forward Differentiation\n");	
	printf("Enter the number of values you want to enter and record it :");
	scanf("%d",&n);
	
	float x[n],y[n][n];  //initialisation of x and y elements
        
         //Input the value of x and y
	for(i=0;i<n;i++){
		printf("Enter x[%d] :",i);  
                scanf("%f",&x[i]);
		printf("Enter y[%d][0] :",i); 
                scanf("%f",&y[i][0]);

	}

	//Calculating the forward difference table
	for(i=1;i<n;i++){
		for(j=0;j<n-i;j++){
			y[j][i] = y[j+1][i-1] - y[j][i-1];
		}
	}
        
        //Forward Difference Table 
        fprintf(fp,"X            Y\t");        
        for(i=1;i<n;i++){
            fprintf(fp,"Y[%d]\t\t",i);
        }
        fprintf(fp,"\n");


	//Displaying the forward difference table
	for(i=0;i<n;i++){
		fprintf(fp,"%f	",x[i]);
		for(j=0;j<n-i;j++){
			fprintf(fp,"%f	",y[i][j]);
		}
		fprintf(fp,"\n");
	}


	//Here we assume x=x[0] so u=0
	
	float sum=0;
	float h= x[1]-x[0];

	for(i=1;i<n;i++){
		sum=sum +( pow(-1,i-1)*y[0][i])/i;
	}
	float d = sum/h; //derivative

	fprintf(fp,"\nThe derivative at x[0]:%f",d);
	fclose(fp);  //closing file
	return 0;

}

