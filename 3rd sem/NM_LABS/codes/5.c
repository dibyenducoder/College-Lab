#include<stdio.h>
#include<math.h>

/*Function that performs Gauss-Elimination and returns the Upper triangular matrix and solution of equations.
 Pass the augmented matrix (a) as the parameter, and calculate and store the upperTriangular(Gauss-Eliminated Matrix) in it.*/
 FILE *fp;
void Gaussian_Elimination(int m, int n, double a[m][n], double x[n-1]){
    int i,j,k;
    for(i=0;i<m-1;i++){
        //Partial Pivoting
        for(k=i+1;k<m;k++){
            //If diagonal element(absolute value) is smaller than any of the terms below it
            if(fabs(a[i][i])<fabs(a[k][i])){
                //Swapping the rows
                for(j=0;j<n;j++){                
                    double temp;  
                    temp=a[i][j];   //storing in temporary variable
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        //Begin Gauss Elimination
        for(k=i+1;k<m;k++){
            double  term=a[k][i]/ a[i][i];
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }
         
    }
    //Begin Back-substitution
    for(i=m-1;i>=0;i--){
        x[i]=a[i][n-1];
        for(j=i+1;j<n-1;j++){
            x[i]=x[i]-a[i][j]*x[j];
        }
        x[i]=x[i]/a[i][i];
    }
             
}
/*Function that reads the elements of a matrix row-wise
Parameters: rows(m),columns(n),matrix[m][n] */

void readMatrix(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("  %lf",&matrix[i][j]);
        }
    } 
}
/*Function that prints the elements of a matrix row-wise
Parameters: rows(m),columns(n),matrix[m][n] */

void printMatrix(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++)
            fprintf(fp,"  %.1f",matrix[i][j]);
            fprintf(fp,"\n");
    } 
}
/*Function that copies the elements of a matrix to another matrix
Parameters: rows(m),columns(n),matrix1[m][n] , matrix2[m][n]*/

void copyMatrix(int m, int n, double matrix1[m][n], double matrix2[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=matrix1[i][j];
        }
    } 
}
 /*Function that starts the Gaussian Elimination process method
Parameters: rows(m),columns(n),user_matrix[m][n] , result_matrix[m][n]*/

int main(){
    fp=fopen("5.txt","w");
    int m,n,i,j;
    printf("Enter the size of the augmeted matrix:\nNo. of rows (m) : ");
    scanf("%d",&m);
    printf("No.of columns (n) : ");
    scanf("%d",&n);
    double user_matrix[m][n];   //Declare a matrix to store the user given matrix
    
    double result_matrix[m][n];     //Declare another matrix to store the resultant matrix obtained after Gauss Elimination
    
    double x[m];   //Declare an array to store the solution of equations
    printf("\nEnter the elements of matrix:\n");
    readMatrix(m,n,user_matrix);
    fprintf(fp,"Your matrix :\n");
    printMatrix(m,n,user_matrix);
    copyMatrix(m,n,user_matrix,result_matrix);
    //Perform Gauss Elimination 
    Gaussian_Elimination(m,n,result_matrix,x);
    fprintf(fp,"\nThe Upper Triangular matrix after Gaussian Eliminiation is:\n\n");
    printMatrix(m,n,result_matrix);
    fprintf(fp,"\nThe unique solution of linear equations is:\n\n");
    for(i=0;i<n-1;i++){
        fprintf(fp,"x[%d]=\t%lf\n",i+1,x[i]);  //unique soln of user_matrix
    }

fclose(fp);
}
