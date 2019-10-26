#include <stdio.h>
int check(int arr[],int n){
	if(n==0 || n==1){   //if there is no elements then return 1
		return 1;
	}

	else {
		if(arr[n] > arr[n-1]) return check(arr,n-1);   //checking whether array is descending order or not
		else return 0;
	}
}
int check1(int arr[],int n){
        if(n==0 || n==1){   //if there is no elements then return 1
                return 1;
        }

        else {
                if(arr[n] < arr[n-1]) return check(arr,n-1);   //checking whether array is ascending order or not
                else return 0;
        }
}

int sort(int arr[],int n){   /*BUBBLE SORT ALGORITHM*/
	int temp,i,j;
       for(i=0;i<n;i++){
       	for(j=0;j<(n-i-1);j++){
       		if(arr[j] > arr[j+1]){  //descending order case
       			temp=arr[j];
       			arr[j]=arr[j+1];
       			arr[j+1]=temp;
			   }
		   }
	   }	
}
int sort2(int arr[],int n){   /*BUBBLE SORT ALGORITHM*/
        int temp,i,j;
       for(i=0;i<n;i++){
        for(j=0;j<(n-i-1);j++){
                if(arr[j] < arr[j+1]){   //ascending order case
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                           }
                   }
           }
}


int main(){
	int arr[50],n,i;
	printf("Enter the size of array :");
	scanf("%d",&n);  //how many elements you want to give the array array[number of elements]
	for(i=0;i<n;i++){
		printf("arr[%d]:",i);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
	printf(" %d ",arr[i]);   //give the elements 
}
   if (check(arr,n-1)) printf("\nArray is sorted in ascending order\n");  //if array ,which is checked by function, is sorted then print sort 
   else {
   printf("\nArray Not sorted in ascending order");  //otherwise unsorted 
   printf("\n\n\n");
   sort(arr,n);            //make the unsorted array to sorted array
   for(i=0;i<n;i++){
   	printf(" %d ",arr[i]); //now print the final sorted array which was originally unsorted
   }
   printf("\nArray now has been sorted \n");
}
if (check1(arr,n-1)) printf("\nArray is sorted in descending order\n");  //if array ,which is checked by function, is sorted then print sort 
   else {
   printf("\nArray Not sorted");  //otherwise unsorted 
   printf("\n\n\n");
   sort2(arr,n);            //make the unsorted array to sorted array
   for(i=0;i<n;i++){
        printf(" %d ",arr[i]); //now print the final sorted array which was originally unsorted
   }
   printf("\nArray now has been sorted \n");
}
	return 0;  //exit 
}
