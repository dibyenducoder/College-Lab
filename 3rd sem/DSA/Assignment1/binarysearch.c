#include <stdio.h>         /*HEADER FILES */

#include <stdlib.h>

#include <string.h>

/*-------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*                                       BINARY SEARCH FOR INTEGER*/





int swap(int arr[],int i,int j){     /*Declare Function to swap two elements*/

	int temp;

	temp=arr[i];

	arr[i]=arr[j];

	arr[j]=temp;

}

int partition(int arr[],int p,int q){        /*Divide and conquer*/

	int pivot,i,j;

	pivot=arr[p];        /*The first element takes as a pivot*/

	i=0;

	for(j=i+1;j<=q;j++){

		if(arr[j]<=pivot){    /*If the current element is smaller than or equal to pivot*/

			i=i+1;     

			swap(arr,i,j);

		}

	}

	swap(arr,p,i);

	return i;

}

int quicksort(int arr[],int p,int q){

	int r;

	if (p<q){

		r=partition(arr,p,q);

		quicksort(arr,p,r-1);

		quicksort(arr,r+1,q);

	}

}

/*array[first....last] */                  

int binarysearch1(int arr[],int first,int last,int search){        /*Function Declaration*/

    

	int mid=(first + last)/2;

	    if(first > last)  return -1;      /*When element is not present in the list*/

		if(arr[mid]==search)              /* If your search element is present at the middle itself*/

		 return mid;

		

		else if(arr[mid]>search)      /*If your search element is smaller than mid then it can be present in the left subarray*/

		 return binarysearch1(arr,first,mid-1,search);

		 

		else                      /*Else the search element can be present in the right subarray*/

		 return binarysearch1(arr,mid+1,last,search); 

}



int binarysearch_integer(){

	int arr[100],i,search,n,position;          /*variable declaration*/

	printf("Enter the number of elements:");

	scanf("%d",&n);              /*How many elements you wish to enter*/

	printf("Enter the elements:\n");

	for(i=0;i<n;i++){

		printf("array[%d] :",i);

  // quicksort(arr,0,n-1);

		scanf("%d",&arr[i]);           /*List of element along with index of an array*/

}; 

    quicksort(arr,0,n-1);

	printf("\nQuick_Sorted :\n");

	for(i=0;i<n;i++){

		printf("arr[%d]: %d\n",i,arr[i]);

	}

	printf("Enter the your target search which is on the list:");

	scanf("%d",&search);               /*Your search element*/ 

	

    position=binarysearch1(arr,0,n-1,search);  /*Position refers to location/index of searched element in a sorted array*/ 

    

    

	if(position >= 0)     /*If element found then location will be between the first and the last but not beyond the given index of an array*/ 

	 printf("\nYour Element is present at location(index) \n--->[Binary search]:%d \n",position);

	else 

	 printf("\nYour Element not found !"); 

	



}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------*/



/*                                          BINARY SEARCH FOR FLOATING POINT*/

int swap1(float arr[],int i,int j){     /*Declare Function to swap two elements*/

	float temp;

	temp=arr[i];

	arr[i]=arr[j];

	arr[j]=temp;

}

int partition1(float arr[],int p,int q){        /*Divide and conquer*/

	int pivot;

	int i,j;

	pivot=arr[p];        /*The first element takes as a pivot*/

	i=0;

	for(j=i+1;j<=q;j++){

		if(arr[j]<=pivot){    /*If the current element is smaller than or equal to pivot*/

			i=i+1;     

			swap1(arr,i,j);

		}

	}

	swap1(arr,p,i);

	return i;

}

int quicksort1(float arr[],int p,int q){    /*FUNCTION CALL FOR QUICKSORT*/

	int r;

	if (p<q){

		r=partition1(arr,p,q);       /*Divide the array*/

		quicksort1(arr,p,r-1);

		quicksort1(arr,r+1,q);

	}

}



/*array[first....last] */                  

int binarysearch2(float arr[],float first,float last,float search){        /*Function Decleration*/

	int mid=(first + last)/2;

	    if(first > last)  return -1;      /*When element is not present in the list*/

		if(arr[mid]==search)              /* If your search element is present at the middle itself*/

		 return mid;

		

		else if(arr[mid]>search)      /*If your search element is smaller than mid then it can be present in the left subarray*/

		 return binarysearch2(arr,first,mid-1,search);

		 

		else                      /*Else the search element can be present in the right subarray*/

		 return binarysearch2(arr,mid+1,last,search); 

}





int binarysearch_floatingpoint(){



	float arr[100],search;

	int i,n,position;          /*variable declaration*/



	printf("\n\n\n");

	printf("Enter the number of elements:");

	scanf("%d",&n);              /*How many elements you wish to enter*/

	

	printf("Enter the elements:\n");

	for(i=0;i<n;i++){

		printf("array[%d] :",i);

		//quicksort1(arr,0,n-1);

		scanf("%f",&arr[i]);           /*List of element along with index of an array*/

		//printf("array[%d] :%f\n",i,arr[i]);

	

}

    quicksort1(arr,0,n-1);

    printf("\nQuick_Sorted :\n");

	for(i=0;i<n;i++){

		printf("arr[%d]: %f\n",i,arr[i]);

	}

	printf("Enter the your target search which is on the list:");

	scanf("%f",&search);               /*Your search element*/

   position=binarysearch2(arr,0,n-1,search);  /*Position refers to location/index of searched element in a sorted array*/ 

	if(position >= 0)     /*If element found then location will be between the first and the last but not beyond the given index of an array*/ 

	 printf("\nYour Element is present at location(index):\n [Binary search]---->%d \n",position);

	else 

	 printf("\nYour Element not found !"); 

	

}

/*------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*                                         BINARY SEARCH FOR WORDS*/



void dictionary_order(char str[50][50],int n){         /*BUBBLE SORT*/

int i, j;

char temp[50];

    for(i=0; i<n-1; ++i)

        for(j=i+1; j<n ; ++j)

        {

            if(strcmp(str[i], str[j])>0)

            {

                strcpy(temp, str[i]);

                strcpy(str[i], str[j]);

                strcpy(str[j], temp);

            }

        }



    printf("\nIn Dictionary order: \n");

    for(i=0; i<n; ++i)

    {

       // puts(str[i]);

    printf("array[%d] :%s\n",i,&str[i]);	

    }

}

int binarysearch_name()

{ int i,n,low,high,mid;

 char a[50][50],search[20];

 printf("Enter the number of words to be added:");

 scanf("%d",&n);

 printf("Enter the words in your order: \n");

 for( i=0;i<n;i++){

     printf("array[%d] :",i);	

    scanf("%s",&a[i]);

   }

 dictionary_order(a ,n );

 printf("\n");

 printf("Enter the name to be searched :");

 scanf("%s",&search);

 low=0;

 high=n-1;

 while(low<=high){

 mid=(low+high)/2;

 if (strcmp(search,a[mid])==0){     /*If the desired search matches*/

 printf("key found at the location(index) :\n--->[Binary_Search] :%d\n",mid);

        exit(0);

 }

 else if(strcmp(search,a[mid])>0){   /*If the desired search element is greater than middle element then it is present in the right subarray*/

 low=mid+1;

 }

 else { 

     high=mid-1; /*Otherwise can be found in the right subarray*/

    }

  }

     printf("Name not found!!\n");

  

 }

 

 /*------------------------------------------------------------------------------------------------------------------------------------------------*/

 

 /*                                MAIN FUNCTION STARTS*/

 int main(){

 	printf("                      BINARY SEARCH FOR INTEGER                      \n");

 	binarysearch_integer();

 	printf("\n\n");

 	printf("                      BINARY SEARCH FOR FLOATING POINT                \n");

 	binarysearch_floatingpoint();

 	printf("\n\n");

 	printf("                     BINARY SEARCH  FOR NAMES IN THE LIST             \n");

 	binarysearch_name();

 	printf("                        THE END                                       \n");

 	return 0;

 }
