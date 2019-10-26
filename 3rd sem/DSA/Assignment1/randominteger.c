#include <stdio.h>     /*Header Files*/

#include <time.h>

#include <stdlib.h>

#define Number1 1             /*Macro Preprocessor*/

#define Number2 60000          



int main(){

	printf("Output File : random.txt\n");

    int len = Number2-Number1+1,i , r , temp;     /*Declare local variables*/

    int num[len];

     FILE *fp;     /*Creating File Pointer*/

     fp=fopen("random.txt","w");       /*Open random.txt for output*/

        for( temp=0,i=Number1; temp<len; i++,temp++ )      /*Fill array with desired numbers*/

        num[temp] = i;



    srand( time(NULL) );  /*seed rand()*/



    /* Shuffle Algorithm */

    for( i=len-1; i>0; i-- ){

        r = rand()%i;   /*pop random number*/

        temp = num[i];    /*swaping using temp*/

        num[i] = num[r];

        num[r] = temp;

    }



    /*Random Numbers between Number1-Number2 are stored in Array num*/

    for( i=1; i<=len; i++ )

        fprintf(fp,"%d : %d\n",i,num[i]);  /*Print Array*/

}


