#include<stdio.h>
#include<stdlib.h>
void gen()
{

  FILE *fp=fopen("dat.txt","a");
  int i;
  for(i=0;i<100;i++)
    fprintf(fp,"%d ",rand()%100);
  fclose(fp);
}
void find(int n)
{
    FILE *fp=fopen("dat.txt","r");
    int k,c=0;
    while(fscanf(fp,"%d",&k)!=EOF)
    {
        if(k==n)
            ++c;
    }
    if(c==0)
        printf("Element not found");
    else
        printf("%d found %d times",n,c);
}
int main()
{
    gen();
    int n;
    printf("Enter number : ");
    scanf("%d",&n);
    find(n);
}
