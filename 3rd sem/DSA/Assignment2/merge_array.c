/* read two list a and b containing m,n valus in sorted order

   merge into c which is generate in sorted order */

#include<stdio.h>

#include<conio.h>

int main()

{

   int arr1[20],arr2[20],arr3[40],i,j,k,m,n;

   printf("enter how many value in Array 1 List\n");

   scanf("%d",&m);

   printf("Enter %d value in sorted order \n",m);

   for(i=0;i<m;i++)

scanf("%d",&arr1[i]);

   printf("enter how many value in Array 2 List\n");

   scanf("%d",&n);

   printf("Enter %d value in sorted order \n",n);

   for(i=0;i<n;i++)

scanf("%d",&arr2[i]);

 

   /* Merge sort logic */

   i=j=k=0;

   /* Compare  Array1 and Array2 List */

   while(i<m&&j<n)

   if(arr1[i]>=arr2[j])

      arr3[k++]= arr2[j++];

   else

      arr3[k++]=arr1[i++];

   /* Remaining Element of Array1 List */

   while(i<m)

      arr3[k++]=arr1[i++];

  /* Remaining Element of Array2 List */

   while(j<n)

      arr3[k++]= arr2[j++];

   printf("\nArray 1 list is :\n");

   for(i=0;i<m;i++)

     printf("%5d",arr1[i]);

   printf("\nArray2 list is :\n");

   for(i=0;i<n;i++)

     printf("%5d",arr2[i]);

   printf("\nArray 3 list is :\n");

   for(i=0;i<m+n;i++)

     printf("%5d",arr3[i]);

   getch();

 

}
