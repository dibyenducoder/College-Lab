//Gauss Central Forward 
#include<stdio.h>
#define Max 10
int main(){
    int n;                          // no. of terms.
    int i,j;                        // Loop variables
    float ax[Max];                  // 'X' array limit 9
    float ay[Max];                  // 'Y' array limit 9
    float x,h,p,nr,dr;              // user input from x
    float y=0;                      // Calculated value for coressponding X.
    float difference[Max*2][Max*2]; // to store Y
    float y1,y2,y3,y4;              // temp variables

// Taking number of inputs
    printf("\nPlease enter the number of (x,y) pairs\t");
    scanf("%d",&n);

// Input Sequel for array X
    printf("\n\nEnter the value of x\t");
// Input loop for X.
    for(i=0; i<n; i++) {
        printf("\nEnter the value of x%d\t",i+1);
        scanf("%f",&ax[i]);
    }

// Input sequel for array Y.
    printf("\n\nEnter the value of y\t");
// Input loop for Y.
    for(i=0; i<n; i++){
        printf("\nEnter the value of y%d\t",i+1);
        scanf("%f",&ay[i]);
    }

// Inputing the required value quarry
    printf("\n\nEnter the value of x for f(x)\t");
    scanf("%f",&x);

// Calculation and processing section.
    h=ax[1]-ax[0];
    for(i=0; i<n-1; i++)
        difference[i][1]=ay[i+1]-ay[i];

    for(j=2; j<=4; j++)
        for(i=0; i<n-j; i++)
            difference[i][j]=difference[i+1][j-1]-difference[i][j-1];
    i=0;
    do {
        i++;
    }
    while(ax[i]<x);

    i--;                 //Gauss Central Forward Formula Method
    p=(x-ax[i])/h;
    y1=p*difference[i][1];
    y2=p*(p-1)*difference[i-1][2]/2;
    y3=(p+1)*p*(p-1)*difference[i-2][3]/6;
    y4=(p+1)*p*(p-1)*(p-2)*difference[i-3][4]/24;

// Taking sum
    y=ay[i]+y1+y2+y3+y4;

// Output Section
    FILE *fp = fopen("6.txt","w");
    fprintf(fp,"\nGauss Central Forward\n");
	i	=	0;
	int z = n;
	fprintf(fp,"x\t\ty\t\tY1\t\tY2\t\tY3\n");
	while(i<n){
		fprintf(fp,"%f\t%f",ax[i],ay[i]);
		j	=	1;
		while(j<z){
			fprintf(fp,"\t%f",difference[i][j]);
			j++;
		}
	fprintf(fp,"\n"); 
	z--;
	i++;
	}
	printf("\nAt x = %6.4f , f(x) = %6.8f\n",x,y);
	fprintf(fp,"\nAt x = %6.4f , f(x) = %6.8f\n",x,y);
	fclose(fp);  //closing file
	return 0;
}
