#include <stdio.h>                    /*Header Files*/

#include <string.h>

/*-----------------------------------------------------------------------------------------------------------------------------------------------*/

/*                                  LINEAR SEARCH FOR NUMBERS*/

/*arr[first.....last]*/

int linearsearch(int arr[],int first,int last,int search){

	if(first > last)

	return -1;

	if (arr[first]==search)           /*Checking your desired search in first element of an array*/

	 return first;                  

	return linearsearch(arr,first+1,last,search); 	/*If the first element does not match your search then increment of first element until matches search */

}

int linearsearch_integer(){

	int arr[100],i,n,search,position;    /*Declare variable*/

	printf("Enter how many Element you want :");      /*Number of elements of an array*/

	scanf("%d",&n);

	printf("Enter the Elements :\n");

	for(i=0;i<n;i++){

		printf("array[%d] :",i);        /*Enter your element*/

		scanf("%d",&arr[i]);

	}

	printf("Enter which integer value you want to search in the list :");

	scanf("%d",&search);

	position=linearsearch(arr,0,n-1,search);      /*Location of searched element*/

	if(position >= 0){

		printf("\nYour element %d is located at %d\n",search,position);

	}

	else printf("\nYour Element %d NOT FOUND !\n",search);

	}



/*------------------------------------------------------------------------------------------------------------------------------------*/



/*                                          LINEAR SEARCH FOR FLOATING POINT NUMBERS*/

int linearsearch2(float arr[],int first,int last,float search){

	if(first > last)

	return -1;

	if (arr[first]==search)               /*Checking your desired search in first element of an array*/

	 return first;

	return linearsearch2(arr,first+1,last,search); 	/*If the first element does not match your search then increment of first element until matches search */

}

int linearsearch_floatingpoint(){

	float arr[100],search;

	int i,n,position;

	printf("Enter how many Element you want :");

	scanf("%d",&n);

	printf("Enter the Elements :\n");

	for(i=0;i<n;i++){

		printf("array[%d] :",i);

		scanf("%f",&arr[i]);

	}

	printf("Enter which integer value you want to search in the list :");

	scanf("%f",&search);

	position=linearsearch2(arr,0,n-1,search);

	if(position >= 0){                     /*Location of searched element*/

		printf("\nYour element %f is located at %d\n",search,position);

	}

	else printf("\nYour Element %f NOT FOUND !\n",search);



	}

/*----------------------------------------------------------------------------------------------------------------------------------------*/

/*                                  LINEAR SEARCH FOR SEARCHNG WORDS*/

void linear_search3(char words[][50],char *search,int n)

{

	int i,found=-1;

	for(i=n-1;i>=0;i--)                 /*Terminate when search found otherwise found will be -1*/

	{

		if(strcmp(words[i], search)==0) {                /*Checking your desired search in first element of an array*/

		printf("Word found at location(index):%d",i);

		found=0;

		break;

		}

	}

	if(found==-1) 

	printf("DATA NOT FOUND !");

	printf("\n");

}

int linearsearch_words()

{

	char words[50][50],search[50];

	int length,i;

	printf("Enter number of words : ");

	scanf("%d",&length);

	printf("Enter the words :\n");

	for(i=0;i<length;i++) {

	printf("Array[%d] :",i);

	scanf("%s",&words[i]);

}

	printf("Enter the word to be searched : ");

	scanf("%s",&search);

	linear_search3(words,search,length);         /*Calling Function*/

}

/*---------------------------------------------------------------------------------------------------------------------------------------------*/

/*                                MAIN FUNCTION STARTS*/



int main(){

 	printf("                      LINEAR SEARCH FOR INTEGER                      \n");

 	linearsearch_integer();

 	printf("\n\n");

 	printf("                      LINEAR SEARCH FOR FLOATING POINT                \n");

 	linearsearch_floatingpoint();

 	printf("\n\n");

 	printf("                     LINEAR SEARCH  FOR NAMES IN THE LIST             \n");

 	linearsearch_words();

 	printf("\n\n");

 	printf("                        THE END                                       \n");

 	return 0;

 }
