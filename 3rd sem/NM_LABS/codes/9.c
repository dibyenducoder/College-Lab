/* C program to implement Gauss-Seidal Iteration Method */ 
#include<stdio.h> 
#define max 50
#define e 0.00001 /*e is the prescribed accuracy*/
FILE * fp; //open the file pointer
int main() {
    fp = fopen("9.txt", "w"); //opening file in write mode
    fprintf(fp,"Gauss Seidal Method\n");
    float a[max][max], x[max]; //a[][] is the user matrix ,
	                           // x[] is the unique solution of gauss-seidal method matrix
    int n, i, j; //n is the order of matrix
    int gauss_seidal(float[][max], float[], int);
    void printmatrix(float[][max], int);
    printf("Enter the order of the matrix(n) : ");
    scanf("%d", & n);
    if (n > 0) { //The order of "n" matrix 

        /*The user enters the augmented matrix*/

        printf("\nEnter the augmented matrix row wise :\n");
        for (i = 0; i < n; i++) {
            printf("\nEnter row %d :\n", i + 1);
            for (j = 0; j < (n + 1); j++) {
                printf("Enter element %d: ", j + 1);
                scanf("%f", & a[i][j]);
            }
        }
        printf("\nOutput File : gauss_seidal.txt\n");
        fprintf(fp, "\nThe augmented matrix entered is :\n");
        printmatrix(a, n); //printing the user_matrix 
        if (gauss_seidal(a, x, n)) { /*The gauss_seidel function return true value */
            fprintf(fp, "\nThe solutions of the given equations are :\n");
            for (i = 0; i < n; i++)
                fprintf(fp, "\ntx[%d]=%10.2f\n", i + 1, x[i]);
        }
    } else fprintf(fp, "\nNo solution.");
    // printf("\nOutput File : gauss_seidal.txt\n");
    fclose(fp);
}

/*Functions implemnts Gauss-Seidal on a system of equations*/

int gauss_seidal(float a[][max], float x[], int n) {
    int i, j, p = 1;
    float x1[max];
    float s;
    int diagonal_dominant(float[][max], int); //calling diagonal dominant function
    int converge(float[max], float[max], int); //calling converge function 
    if (!diagonal_dominant(a, n)) { /*Checking the diagonal dominant condition*/
        printf("\nThe system is not diagonally dominant.");
        return 0; /*The solution cannot be obtained if system is not diagonal-dominant*/
    }
    /*Taking the initial approximation as zero*/
    for (i = 0; i < n; i++) {
        x1[i] = 0;
        x[i] = 0;
    }
    do {
        printf("\n\n");
        fprintf(fp, "\nIteration %d :\n", p);
        p++;
        for (i = 0; i < n; i++) {
            s = 0;
            for (j = 0; j < n; j++) {
                if (i != j)
                    s += a[i][j] * x[j];
            }
            x[i] = (a[i][n] - s) / a[i][i];
            fprintf(fp, "\nx[%d]=%10.6f", i + 1, x1[i]);
        }
        /*If the present result converges to the last result then we stop */
        if (converge(x, x1, n)) break;
        for (i = 0; i < n; i++)
            x1[i] = x[i];
    } while (1);
    printf("\n");
    return 1;
}
float absolute(float x, float y) { /*Returns the absolute value*/
    float t = x - y;
    if (t > 0.0)
        return t;
    return (-1.0) * t;
}
/*Function checking diagonal-dominance*/
int diagonal_dominant(float a[][max], int n) {
    int i, j;
    float s;
    for (i = 0; i < n; i++) {
        s = 0;
        for (j = 0; j < n; j++) {
            if (i != j)
                s += absolute(a[i][j], 0.0);
        }
        if (absolute(a[i][i], 0.0) < s)
            return 0;
    }
    return 1;
}
/*Function checking convergence*/
int converge(float x[max], float x1[max], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (absolute(x[i], x1[i]) > e)
            return 0;
    }
    return 1;
}
/*Printing the augmmented matix*/
void printmatrix(float user_matrix[][max], int order) {
    int i, j; //i is the rows of augmented matrix  & j is the rows of RHS matrix
    for (i = 0; i < order; i++) {
        for (j = 0; j < (order + 1); j++) {
            if (j == order)
                fprintf(fp, " |");
            fprintf(fp, " %10.6f ", user_matrix[i][j]);
        }
        fprintf(fp, "\n");
    }
}
