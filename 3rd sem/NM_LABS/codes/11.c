//Jacobi Eigen Values

#include <stdio.h> 
#include <math.h>
   int main() {
   	  FILE *fp; //creating file pointer 
   	  fp=fopen("11.txt","w");  //write mode
   	  fprintf(fp,"\tJacbi Eigen Values Method\n\n");
      int i, j, r, s, n;
      printf("Enter the order of the square matrix : "); //order of n matrix
      scanf("%d", & n);
      float a[n][n], v[n][n];
      for (i = 0; i < n; i++) {      //Input the matrix a
         for (j = 0; j < n; j++) {
            printf("Enter a%d%d : ", i + 1, j + 1);
            scanf("%f", & a[i][j]);
         }
      }
      for (i = 0; i < n; i++) {      // matrix in a file
         for (j = 0; j < n; j++) {
            fprintf(fp,"%f      ",a[i][j]);
         }
         fprintf(fp,"\n"); //escape sequence
      }
      
      /*Calculation of Jacobi Eigen Values along with Eigen vectors E*/
      for (i = 0; i < n; i++)            
         for (j = 0; j < n; j++) 
		 	v[i][j] = (i == j ? 1 : 0);
      int k = 5;
      while (k) {
         float mx = -1e5, mn = 1e5; //maximum and minimum value to compute
         for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
               if (i != j && fabs(a[i][j]) > mx) {
                  mx = fabs(a[i][j]);
                  r = i;    //updating the values
                  s = j;
               }
            }
         if (mx <= 0.000001) break;       //maximum value to compute else break the code 
         float theta = atan(2 * a[r][s] / (a[r][r] - a[s][s])) / 2;
         float vnew[n][n];    //new vectors initialization
         for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) vnew[i][j] = v[i][j];
         for (i = 0; i < n; i++) {
            vnew[i][r] = v[i][r] * cos(theta) + v[i][s] * sin(theta);
            vnew[i][s] = v[i][s] * cos(theta) - v[i][r] * sin(theta);
         }
         float newa[n][n];       //new array initialization
         for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) newa[i][j] = a[i][j];
         for (i = 0; i < n; i++) {
            if (i != r || i != s) {
               newa[i][r] = newa[r][i] = a[i][r] * cos(theta) + a[i][s] * sin(theta);
               newa[i][s] = newa[s][i] = -a[i][r] * sin(theta) + a[i][s] * cos(theta);
            }
         }                                              //calculation process
         newa[r][r] = a[r][r] * cos(theta) * cos(theta) + 2 * a[r][s] * sin(theta) * cos(theta) + a[s][s] * sin(theta) * sin(theta);
         newa[s][s] = a[s][s] * cos(theta) * cos(theta) - 2 * a[r][s] * sin(theta) * cos(theta) + a[r][r] * sin(theta) * sin(theta);
         newa[r][s] = newa[s][r] = 0;
         for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) a[i][j] = newa[i][j];
         for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) v[i][j] = vnew[i][j];
      }
      fprintf(fp,"\n\n");
      for (i = 0; i < n; i++) {
         fprintf(fp,"Eigen Value%d : %f\n E%d :\n",i,a[i][i],i);
         for (j = 0; j < n; j++) fprintf(fp,"%f\n",v[j][i]);
         fprintf(fp,"\n");
      }
      fclose(fp);   //closing file
      return 0;
   }
