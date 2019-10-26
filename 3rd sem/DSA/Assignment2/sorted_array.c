#include <stdio.h>
int sort_descendingOrder(int arr[],int n){
	int temp,i,j;
       for(i=0;i<n;i++){
       	for(j=0;j<(n-i-1);j++){
       		if(arr[j] > arr[j+1]){
       			temp=arr[j];
       			arr[j]=arr[j+1];
       			arr[j+1]=temp;
			   }
		   }
	   }	
}
int sort_ascendingOrder(int arr[],int n){
        int temp,i,j;
       for(i=0;i<n;i++){
        for(j=0;j<(n-i-1);j++){
                if(arr[j] <  arr[j+1]){
                        temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                           }
                   }
           }
}
int main(){
int sorted; 
int arr[50],n,i;
printf("Enter the size of array :");
scanf("%d",&n);
       if(n==0) printf("\nNO ELEMENT PRESENT IN THE ARRAY\n");  

	for(i=0;i<n;i++){
		printf("arr[%d]:",i);
		scanf("%d",&arr[i]);
	} 
	for(i=0;i<n;i++){
	printf(" %d ",arr[i]);
}
sorted=1;
for(i=0;i<n-1;i++) {
        if(arr[i] == arr[i+1]) { sorted=0; break; }
}

if(sorted==0){
       sorted=2;
       for(i=0;i<n-1;i++) {
	if(arr[i]>arr[i+1]) { sorted=0; break; }
   }
}

if (sorted==0) {
	sorted=3;
	for(i=0;i<n-1;i++) {
		if(arr[i]<arr[i+1]) { sorted=0; break;}
	}
}

if (sorted==0) {
	printf("\n\nThe array is not sorted.\n");
        printf("\n\n");
       sort_descendingOrder(arr,n);
       printf("\nDescending Order\n");
       for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
}
       printf("\nAscending Order\n");
       sort_ascendingOrder(arr,n);
       for(i=0;i<n;i++){
        printf(" %d ",arr[i]);
}

}
else if(sorted==1){
         printf("\nAll elements of an array are equal\n");
} 
else if (sorted==2) {
	printf("\n\nThe array is sorted in ascending order.\n");
} else {
	printf("\n\nThe array is sorted in decending order.\n");
}
printf("\n\n");
return 0;
}

