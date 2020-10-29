%{
	#include<stdio.h>
	int c1=0 , c2=0 , c3=0 , line =0;	
%}

%%
^([A-Z]) 	{c2++;}
[A-Z]+[ ]	{c1++;}
[A-Z]+\n 	{line++; c1++;}
\n 			{line++;}
%%

int yywrap(){} 
int main()
{
	yyin= fopen("input.txt","r");
	yylex(); 
	int pr = line-c2;
	printf("\nNumber of proper names :- %d\n", pr);
	printf("\nNumber of acronyms :- %d\n", c1);
  
	return 0; 
} 