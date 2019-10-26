// newton backward interpolation 
#include <stdio.h>   

// Calculation of u mentioned in formula 
float u_cal(float u, int n) { 
    int i;
    float temp = u; 
    for (i = 1; i < n; i++) 
        temp = temp * (u + i); 
    return temp; 
}   
// Calculating factorial of given n 
int fact(int n) { 
    int i;
    int f = 1; 
    for (i = 2; i <= n; i++) 
        f *= i; 
    return f; 
}   
int main() { 
    // number of values given 
    int n,i,j;
    FILE *fp;     //creating file pointer
    fp=fopen("16.txt","w"); //write mode file
    fprintf("\t\tNewton Backward Interpolation\n");
    printf("Enter the number of records you want to store: ");
    scanf("%d",&n);
    float x[n];
    for( i=0;i<n;i++) 
    {
        printf("\nEnter X[%d]: ",i);
        scanf("%f",&x[i]);
    }                   
    // y[][] is used for difference  
    // table and y[][0] used for input 
    float y[n][n]; 
    for(i=0;i<n;i++) 
    {
        printf("\nEnter Y[%d]: ",i);
        scanf("%f",&y[i][0]);
    } 
    printf("\n");
    // Calculating the backward difference table 
    for (i = 1; i < n; i++) { 
        for (j = n - 1; j >= i; j--) 
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1]; 
    } 
    // Displaying the backward difference table 
    fprintf(fp,"\nX             Y");
    for(i=1;i<n;i++)
        fprintf(fp,"            Y[%d]",i);
    fprintf(fp,"\n");
    for (i = 0; i < n; i++) { 
        fprintf(fp,"%6.3f",x[i]);
        for (j = 0; j <= i; j++)
            fprintf(fp,"        %6.3f",y[i][j]); 
        fprintf(fp,"\n"); 
    }   
    // Value to interpolate at 
    printf("\nEnter the value: ");
    float value;
    scanf("%f",&value);  
    // Initializing u and sum 
    float sum = y[n - 1][0]; 
    float u = (value - x[n - 1]) / (x[1] - x[0]); 
    for (i = 1; i < n; i++) { 
        sum = sum + (u_cal(u, i) * y[n - 1][i]) / 
                                     fact(i); 
    }   
    fprintf(fp,"\nValue=%6.3f",sum);
    printf("\nThe output :  16.txt");
    fclose(fp); //closing file
    return 0; 
} 
