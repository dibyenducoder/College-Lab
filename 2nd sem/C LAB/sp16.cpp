#include<stdio.h>
#include<stdlib.h>
int findPiv(int beg,int rear,int *a)
{
    int p=a[rear],i=beg-1,j;
    for (j=beg;j<rear; j++)
    {
        if (a[j]<=p)
         {
            i++;
            if(i!=j)
             {
               int t=a[i];
               a[i]=a[j];
               a[j]=t;
             }
         }
    }
    ++i;
    int t=a[i];
    a[i]=a[rear];
    a[rear]=t;
   return i;
}
void sort(int beg,int rear,int *a)
{
  if(beg>=rear)
     return;
  int k=findPiv(beg,rear,a);
  sort(beg,k-1,a);
  sort(k+1,rear,a);
}
int mode(int *a,int n) {
   int max=0,maxc=0,i,j;
   for(i=0;i<n;++i)
   {
      int c=0;
      for (j=0;j<n;++j)
         if (a[j] == a[i])
         ++c;
      if (c>maxc)
      {
         maxc=c;
         max=a[i];
      }
   }

   return max;
}
int main()
{
    int *a=(int*)calloc(1,sizeof(int));
    int s=0;
    char k[30];
    float mean;
    printf("Enter number : ");
    scanf("%s",&k);
    printf("%s",k);
    while(k[0]!='0' && k[0]!='x' && k[0]!='X')
    {
      a=(int*)realloc(a,sizeof(int)*(s+1));
      a[s++]=atoi(k);
      mean+=a[s-1];
      printf("Enter number : ");
      scanf("%s",&k);
    }
    sort(0,s+1,a);
    printf("Mean : %f\nMedian : %d\nMode : %d",mean/s,a[s/2],mode(a,s));
}
