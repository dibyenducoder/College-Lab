//Least Square method for linear Fit
#include<stdio.h>

int main() {
    FILE *fp;   //file pointer
    fp=fopen("12.txt","w"); //write mode
    fprintf(fp,"\t\tLeast Square\n");
    int i,j,n;
    float x[10],y[10],s1=0,s2=0,s3=0,s4=0,a,d,b;
    printf("\nEnter how many records you want to fit in the curve : "); //records 
    scanf("%d",&n);
    
    printf("\nEnter the values of x and y in the form of table\n"); //table form
    printf("x    y\n");
    for(i=0;i<n;i++) {                     //write the values of x and y in the form of table
        scanf("%f%f",&x[i],&y[i]);
    }
    fprintf(fp,"Table of data\n");
    fprintf(fp,"Itr.\tx\t  y       x^2\t      xy\n"); //table in the file
    fprintf(fp,"------------------------------------------------\n");
    for(i=0;i<n;i++) {                     //write the values of x and y in the form of table
        fprintf(fp,"%i       %f  %f  %f   %f\n",i,x[i],y[i],x[i]*x[i],x[i]*y[i]);
    }
    fprintf(fp,"\n");

    for(i=0;i<n;i++) {        //calculation for linear fit by least square method
        s1=s1+x[i];
        s2=s2+x[i]*x[i];
        s3=s3+y[i];
        s4=s4+x[i]*y[i];      
    }
    fprintf(fp,"-------------------------------------------------\n");
    fprintf(fp,"Total Sum  %f  %f  %f  %f\n",s1,s3,s2,s4);

    d=n*s2-s1*s1;
    a=(s2*s3-s1*s4)/d; //value of a after calculating
    b=(n*s4-s1*s3)/d;   //value of b after calculating
    fprintf(fp,"\nThe values of a and b are : %f  and  %f respectively\n",a,b);
    fprintf(fp,"\nThe Required Linear Relation is : \n");
    if(b>0){
        fprintf(fp,"\ny=(%f)+(%f)x\n",a,b);
    }
    else {
        fprintf(fp,"\ny=%f%fx\n",a,b);
    }
    fclose(fp); //closing file pointer
    return 0;
}
