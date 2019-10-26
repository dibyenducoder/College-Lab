#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct k{int sub1,sub2;float avg;char name[10];}Data;
void sort(Data** dbase,int n)
{
    int i,j;
    for(i=0;i<n;i++)
      for(j=0;j<n-i-1;j++)
        if(dbase[j]->avg>dbase[j+1]->avg)
          {
              Data *t=dbase[j];
              dbase[j]=dbase[j+1];
              dbase[j+1]=t;
          }
}
int main()
{
    char ch[100];
    printf("Enter filename: ");
    scanf("%s",&ch);
    FILE *fp=fopen(ch,"r");
    Data** dbase=(Data**)calloc(1,sizeof(Data*));
    FILE *fout=fopen("out.txt","a");
    int s=0;
    if(fp!=NULL)
        {
            int a,b;
            char ch[10];
            while(fscanf(fp,"%s %d %d",&ch,&a,&b)==3)
            {
                dbase[s]=(Data*)malloc(sizeof(Data));
                strcpy(dbase[s]->name,ch);
                dbase[s]->sub1=a;
                dbase[s]->sub2=b;
                dbase[s]->avg=(a+b)/2.0;
                s++;
                dbase=(Data**)realloc(dbase,sizeof(Data*)*(s+1));
            }
        }
        sort(dbase,s);
        int i;
        for(i=0;i<s;i++)
            {
                fputs(dbase[i]->name,fout);
                itoa(dbase[i]->sub1,ch,10);
                fputs(ch,fout);
                fputs(" ",fout);
                itoa(dbase[i]->sub2,ch,10);
                fputs(ch,fout);
                fputs(" ",fout);
                gcvt(dbase[i]->avg,100,ch);
                fputs(ch,fout);
                fputs("\n",fout);
            }
        fclose(fp);
        fclose(fout);
        printf("Output stored in out.txt");
}


