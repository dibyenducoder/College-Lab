#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void gen()
{

      FILE *fp=fopen("dat.txt","a");
      int i,j;
      for(i=0;i<50;i++)
        {
          for(j=0;j<6;j++)
            fprintf(fp,"%d ",rand()%100);
          fprintf(fp,"\n");
        }
      fclose(fp);
}
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
void eval()
{
    FILE *fp=fopen("dat.txt","r");
    FILE *fout=fopen("resultdata.txt","a");
    int a[6],i,j;
    //a=(int*)calloc(6,sizeof(int));
    for(j=0;j<=50;j++)
    {
      float avg,sd;
      for(i=0;i<6;i++)
        {
           fscanf(fp,"%d",&a[i]);
           avg+=a[i];
        }
      avg/=6;
      sort(0,6,a);
      for(i=0;i<6;i++)
        sd+=(a[i]-avg)*(a[i]-avg);
      sd/=5;
      sd=sqrt(sd);
      fprintf(fout,"%f %f %d\n",sd,avg,a[2]);
    }

  fclose(fout);
}
int main()
{
    gen();
    eval();
}
