%{
	#include<stdio.h>
	int c1=0 , c2=0 , c3=0 , dec=0 , inti=0;
%}

%%
\n 				{c1++; c2++;}
[ ]				{c2++; c3++;} 
\t 				{c2++;}
[a-zA-Z]		{c3++;}
[0-9]+ 			{inti++;}
[0-9]*"."[0-9]+ {dec++;}
[0-9]+"."[0-9]* {dec++;}
%%

int yywrap(){}

int main()
{
	yyin= fopen("myfile.txt","r");
	yylex(); 
	printf("\nNumber of lines :- %d\n", c1);
	printf("\nNumber of words :- %d\n", c2);
	printf("\nNumber of character :- %d\n", c3);
	printf("\nNumber of integers :- %d\n", inti);
	printf("\nNumber of decimal :- %d\n", dec);
  
	return 0; 
} 