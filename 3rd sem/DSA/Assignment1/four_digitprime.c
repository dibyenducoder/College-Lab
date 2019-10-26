#include <stdio.h>    /*Header files*/
#include <math.h>
#include <stdlib.h>
#include <time.h>

int prime_checker(int number){    /*Function Declaration as Iteration Method*/

	int i=1,prime=1000,d=2,found;

	while(number>=i){

		found=0;

		for(d=2;d<=sqrt(prime);d++){

			if(prime%d==0) {

			found=1;          /*If prime found then break */

			break;

			}
		}

		if(found==0) 

		i++;

		prime++;
	}

	return prime-1;

}

int main(){

	FILE *fp;
     
	fp=fopen("prime.txt","w");

	int x,i,num,ri,p,c,count=0;  /*Declare variables*/

	long int li;

	for(c=1;c<=3;c++){              /*Loop for only 2 others prime numbers*/

		printf("Enter required primes order :");

		scanf("%d",&num);        

		printf("Enter no of li's : ");     /*How much member of large integer you wish */

		scanf("%d",&num);

		srand(time(NULL));   /*seed rand()*/

		p=prime_checker(num);    
                fprintf(fp,"\n\n");
		fprintf(fp,"%d no 4 digit prime P is : %d\n\n",num,p);

		fprintf(fp,"i	li	        	ri\n");
               fprintf(fp,"----------------------------------------------\n");
		for(i=1;i<=num;i++){

			li=100000+rand();

			ri=li%p;

			fprintf(fp,"%d	%ld	      %d\n",i,li,ri);

		}	

    } 
        printf("\n\nOutput File: prime.txt\n\n");
	return 0;

}


