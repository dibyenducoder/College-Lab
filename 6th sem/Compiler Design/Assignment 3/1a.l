%{
	#include<stdio.h>
	int c1=0 , c2=0 , c3=0;
%}

%%

\n 				{c1++;c2++;}
[ ]				{c2++;c3++;} 
\t 				{c2++;}
. 				{c3++;}
%%

int yywrap(){} 
int main()
{
	yyin= fopen("input.txt","r");
	yylex(); 
	printf("\nNumber of lines:-      %d\n", c1);
	printf("\nNumber of words:-      %d\n", c2);
	printf("\nNumber of character :- %d\n", c3);
  
	return 0; 
} 