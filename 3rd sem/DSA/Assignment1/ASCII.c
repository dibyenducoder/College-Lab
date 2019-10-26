#include <stdio.h>  /*Header Files*/
#include <string.h>
#include <stdlib.h>
#include <math.h>

long divide(int *a,int x,int y){         /*To print 1st half and 2nd half separately*/

	int i;

	long d=a[x-1];

	for(i=x;i<y;i++)  d=d*10+a[i];

	return d;
}

int prime_checker(int x){          /*To check the prime number*/

	int i=1,prime=1000,d=2,found;

	while(x>=i){

		found=0;

		for(d=2;d<=sqrt(prime);d++){

			if(prime%d==0) {    /*If prime found then break */

			found=1;

			break;

			}
		}

		if(found==0)  /*Otherwise increment occurs*/

		i++;

		prime++;
	}

	return prime-1;  /*If not then print no prime ie error will occur*/
}

int main(){

	char name[60];

	int i,length,a,*nm,index=0,cnt=0,x,p,ri;

           long	long nm1,nm2,sum;

	printf("Enter a name within 60 charecter : ");  /*Your Name and surname*/

	scanf("%s",name);

	length=strlen(name);

	printf("Length of name : %d\n",length);

	printf("converted integer of input : ");  /*Converted Name & Surname into ASCII value and then store it as integer*/

	nm=malloc(3*length*sizeof(int));

	for(i=0;i<length;i++){

		a=(int)name[i];

		if(a>=100){

			nm[index]=1;

			nm[index+1]=(a/10)%10;

			nm[index+2]=a/100;

			index+=3;
	}

	else{

		nm[index]=a/10;

		nm[index+1]=a%10;

		index+=2;

		}

	}

	for(i=0;i<index;i++) printf("%d",nm[i]);

	printf("\n");

	nm1=divide(nm,1,index/2);  /*First Half of ASCII value*/

	nm2=divide(nm,index/2+1,index); /*second half of ASCII value*/

	sum=nm1+nm2;

	printf("1st part=%lld\n2nd part=%lld\nsum=%lld\n",nm1,nm2,sum);

	printf("enter required primes order :");

	scanf("%d",&x);

	p=prime_checker(x);   /*Check prime or not*/

	printf("%d no. 4 digit prime P is : %d\n",x,p);

	printf("Li = %lld\n",sum); /*Memeber of Largest Integer (Li)*/
        
        ri=sum%p;

	printf("ri=%d\n",ri);  /*Remainder (Ri)*/

	return 0;

	}
