#include <stdio.h>

#include <stdlib.h>

char *s1, *s2;

void init();

void len();

int getlen(char *str);

void compare();

char* concat();

int srchsub();

void freq();

void convertUpper();

void convertLower();

void replace();

void countwords();

void remspace();

void reverse();

int main(){

	init();

	do{

        printf("Enter 1 to find the length of String\n");

	printf("Enter 2 to compare the two Strings\n");

	printf("Enter 3 to concatenate the two strings\n");

	printf("Enter 4 to print the reverse of a String\n");

        printf("Enter 5 to Search for a particular substring in a string\n");

	printf("Enter 6 to find frequency of letters in a String\n");

	printf("Enter 7 to convert a string into Uppercase\n");

	printf("Enter 8 to convert a string into Lowercase\n");

	printf("Enter 9 to replace a letter in a String\n");

	printf("Enter 10 to count the number of words in a String\n");

	printf("Enter 11 to remove spaces in a String\n");

	printf("Enter 12 to Exit\n");

        printf("\n Your Choice :");

       

            int ch;

            scanf("%d",&ch);

            switch(ch){

            case 1: len();

                    break;

            case 2: compare(s1,s2);

                    break;

            case 3: concat();

                    break;

            case 4: reverse();

                    break;

            case 5: srchsub();

                    break;

            case 6: freq();

                    break;

            case 7: convertUpper();

                    break;

            case 8: convertLower();

                    break;

            case 9: replace();

                    break;

            case 10: countwords();

                    break;

            case 11: remspace();

                    break;

            case 12: return 0;

            default: printf("Invalid Input");

            }

    }while(1);



}

void init(){



	s1 = (char*)(malloc(100*sizeof(char)));

	s2 = (char*)(malloc(100*sizeof(char)));

	printf("Enter two strings:\n");

	fgets(s1, 100*sizeof(s1), stdin);

	fgets(s2, 100*sizeof(s2), stdin);
        /*printf("string 1 :");

	scanf("%[^\n]s",s1);

	fflush(stdin);
        printf("string 2 :");

	scanf("%[^\n]s",s2);

	fflush(stdin);
        /*fputs(s1, stdout); printf("is stored as String 1\n");
        fputs(s2, stdout); printf("is stored as String 2\n");*/

	printf("%s is stored as String 1\n",s1);

	printf("%s is stored as String 2\n",s2);



}

void len(){

    char* str;



    int fl = 1;

    do{

            fl = 1;

            printf("Enter string number\n");

            int num;

            scanf("%d",&num);

            if(num == 1)str = s1;

            else if(num == 2)str = s2;

            else{ printf("Wrong input!\n"); fl = 0;}

    }while(fl == 0);

	int i = 0;

	while(str[i] != '\0')i++;

	//str[i] = '\0';

	printf("Length of %s = %d\n",str, i);

}



int getlen(char *str){

    int i = 0;

	while(str[i] != '\0')i++;

	return i;

}





void compare(char *first, char *second) {

   while (*first == *second) {

   	printf ("%c %c\n",*first,*second);

      if (*first == '\0' || *second == '\0')

         break;



      first++;

      second++;

   }



   if (*first == '\0' && *second == '\0')

      printf("Equal Strings\n");

   else

      printf("Different Strings\n");



}

char* concat(){

	char* str = (char*)(malloc(200*sizeof(char)));

	int i=0,j=0;

	while(s1[i] != '\0'){str[i] = s1[i];i++;}

	while(s2[j] != '\0'){str[i] = s2[j]; i++;j++;}

	str[i] = '\0';

	printf("%s\n",str);



}

int srchsub(){

	fflush(stdin);

	printf("\nEnter substring to search for: ");

	char* sub = (char*)(malloc(200*sizeof(char)));

	scanf("%[^\n]s",sub);

	char* str;

    int fl = 1;

    do{

            fl = 1;

            printf("\nEnter string number :");

            int num;

            scanf("%d",&num);

            if(num == 1) str = s1;

            else if(num == 2) str = s2;

            else{ printf("Wrong input!\n"); fl = 0;}

    }while(fl == 0);



    int lsub = getlen(sub);

	int l = getlen(str);

	int i = 0, ret = 0,st=0;

	if(lsub > l)return 0;

	for(i=0; i < l; i++){

		if(str[i] == sub[st]){

			st++;

			if(st == lsub){i=l; ret=1; break;}

		}

		else {st=0; if(i != 0){if(str[i] == sub[st])st++;}}

	}

	if(ret == 1)printf("%s is found in %s\n",sub,str);

	else printf("Substring not found\n");

}

void freq(){

    char* str;

    int fl = 1;

    do{

            fl = 1;

            printf("Enter string number\n");

            int num;

            scanf("%d",&num);

            if(num == 1)str = s1;

            else if(num == 2)str = s2;

            else{ printf("Wrong input!\n"); fl = 0;}

    }while(fl == 0);

    int l = getlen(str);

	int ar[26] = {0};

	int i;

	for(i = 0; i < l; i++){

		char ch = str[i];

		if(ch == 32)continue;

		if(ch > 90)ch-=97;

		else ch-=65;

		ar[ch]++;

	}

	printf("Letter\tFrequency\n");

	for(i = 0; i < 26; i++){

		if(ar[i] != 0){

			printf("%c\t%d\n",(i+97),ar[i]);

		}

	}

}

void convertUpper(){

    char* str;

    int fl = 1;

    do{

            fl = 1;

            printf("\nEnter string number\n");

            int num;

            scanf("%d",&num);

            if(num == 1)str = s1;

            else if(num == 2)str = s2;

            else{ printf("Wrong input!\n"); fl = 0;}

    }while(fl == 0);

    int l = getlen(str);

	printf("String %s in UPPERCASE: ",str);

	char *tmp = (char*)(malloc(100*sizeof(char)));

	tmp[l] = '\0';

	while(l-- > 0){

		if(str[l] > 90)tmp[l]= str[l]-32;

		else tmp[l] = str[l];

	}



	printf("%s\n",tmp);

}

void convertLower(){

    char* str;

    int fl = 1;

    do{

            fl = 1;

            printf("Enter string number\n");

            int num;

            scanf("%d",&num);

            if(num == 1)str = s1;

            else if(num == 2)str = s2;

            else{ printf("Wrong input!\n"); fl = 0;}

    }while(fl == 0);

    int l = getlen(str);

	printf("String %s in UPPERCASE: ",str);

	char *tmp = (char*)(malloc(100*sizeof(char)));

	tmp[l] = '\0';

	while(l-- > 0){

		if(str[l] <= 90)tmp[l]= str[l]+32;

		else tmp[l] = str[l];

	}



	printf("%s\n",tmp);

}

void replace(){

	char* str;

    int fl = 1;

    do{

            fl = 1;

            printf("Enter string number\n");

            int num;

            scanf("%d",&num);

            if(num == 1)str = s1;

            else if(num == 2)str = s2;

            else{ printf("Wrong input!\n"); fl = 0;}

    }while(fl == 0);

    int l = getlen(str);

	printf("Enter letter to be replaced and letter to replace it: ");

	fflush(stdin);

	char ch1,ch2;

	scanf("%c %c",&ch1,&ch2);

	while(l-- > 0){

		if(str[l] == ch1)str[l]=ch2;

	}

	printf("\nConverted String: %s\n",str);

}

void countwords(){

	char* str;

    int fl = 1;

    do{

            fl = 1;

            printf("Enter string number\n");

            int num;

            scanf("%d",&num);

            if(num == 1)str = s1;

            else if(num == 2)str = s2;

            else{ printf("Wrong input!\n"); fl = 0;}

    }while(fl == 0);

    int l = getlen(str);

	int wrds = 1;

	while(l--){

		if(str[l] == ' ')wrds++;

	}

	printf("%d\n",wrds);

}

void reverse(){

    char* str;

    int fl = 1;

    do{

            fl = 1;

            printf("Enter string number\n");

            int num;

            scanf("%d",&num);

            if(num == 1)str = s1;

            else if(num == 2)str = s2;

            else{ printf("Wrong input!\n"); fl = 0;}

    }while(fl == 0);

    int l = getlen(str);

	char* rev = (char*)(malloc(100*sizeof(char)));

	int index = 0;

	while(l--)rev[index++]=str[l];

	rev[index] = '\0';

	printf("%s\n",rev);

}

void remspace(){

    char* str;

    int fl = 1,i=0,j=0;;

    do{

            fl = 1;

            printf("Enter string number\n");

            int num;

            scanf("%d",&num);

            if(num == 1)str = s1;

            else if(num == 2)str = s2;

            else{ printf("Wrong input!\n"); fl = 0;}

    }while(fl == 0);

    int l = getlen(str);

    char* s = (char*)(malloc(200*sizeof(char)));

	while(j < l){

		if(str[j++] != ' ')s[i++]= str[j-1];

	}

	s[i] = '\0';

	printf("%s\n",s);

}
