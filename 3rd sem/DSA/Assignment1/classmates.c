#include <stdlib.h>

#include <stdio.h>

#include <string.h>

void dictionary_order(char classmates[54][30])         /*Insertion Sort Algorithm*/

{

	int i,j;

	char target_student[30];

	for(i=1;i<54;i++)

	{

		strcpy(target_student,classmates[i]);

		j=i-1;

		while(strcmp(classmates[j],target_student)>0 && j>=0) {



		   strcpy(classmates[j+1],classmates[j]);

		   j--;

		   }

		   strcpy(classmates[j+1],target_student);

	}

}

int main(){

	char max[30],min[30],name[30],classmates[54][30],max_name[30],min_name[30];     /*Declare Variables*/

	int i,x=0,b=0,y=0,c=0;

	FILE *fp,*fptr;                               /*Creating a file pointer*/

    printf("Original Student File :   classmatesname.txt \n");

	fp=fopen("classmatesname.txt","r");            /*Open File If Exits */

	if(fp==NULL){

		printf("\nUnable to open file");       /*If the File does not exit then it print NULL(Error)*/



	}

	fscanf(fp,"%[^\n]s",&name);     /*From the file, see the name and then scan it*/

	printf("%s\n",name);

	strcpy(classmates[0],name);

    strcpy(max,name);

    strcpy(min,name);

//    int c=0;

	for( i=1;i<54;i++){

        while(fgetc(fp)!='\n' && fgetc(fp)!='\t'&&fgetc(fp)!=EOF);     /*To see if there is a space or tab*/

		fscanf(fp,"%[^\n]s",&name);



		strcpy(classmates[i],name);

		printf("%s\n",classmates[i]);

		if(strlen(max) <= strlen(name))

		  strcpy(max,name);



	   if(strlen(min) >= strlen(name))

		 strcpy(min,name);



}

   while(max[x] != '\0'){    /* till string doesn't terminate*/



        if(max[x] != ' '){  /* if the char is not a white space*/

         max_name[b++] = max[x];      /* incrementing index b only when the char is not space*/

        }

        x++;                     /*  x is the index of the actual string and  is incremented irrespective of the spaces*/

    }

   max_name[b] = '\0';





    while(min[y] != '\0')    /* till string doesn't terminate*/

    {

        if(min[y] != ' ')  /* if the char is not a white space*/

        {



            min_name[c++] = min[y];     /* incrementing index c only when the char is not space*/

        }



        y++;        /*y is the index of the actual string and  is incremented irrespective of the spaces*/

    }

    min_name[c] = '\0';



	printf("\n%s is the largest name: %d",max,strlen(max_name));

	printf("\n%s is the smallest name: %d\n\n\n",min,strlen(min_name));

	fclose(fp);



	fptr=fopen("Dictionary_order_name.txt","w");

	fprintf(fp,"\nList of names in Lexicographical Order :\n Dictionary_order_name.txt\n");

	dictionary_order(classmates);        /*Function Call*/

	for(i=0;i<=54;i++){

		strcpy(name,classmates[i]);

		fprintf(fptr,"%s\n",name);

	}

	fclose(fptr);

	return 0;

}
