%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	int flag=0;
%}

%token NUMBER RNUM NL
%left '+'
%left '*' '%'
%left '^'

%%
S : expr NL{printf("Result=%d\n",$$);return 0;} 
	| error'\n'{yyerror("Invalid expression\n");yyerrok;} 
	|
expr : expr '+' expr {$$=$1+$3;} 
	| NUMBER {$$=$1;} 
	| expr '*' expr {$$=$1*$3;} 
	| expr '%' expr {$$=$1%$3;} 
	| expr '^' expr {$$=pow($1,$3);} |
;
%%

int yyerror(char*msg)
{
	printf("Invalid expression\n",msg);
	exit(0);
}
int main(void)
{
	printf("Enter Expression : ");
	yyparse();
	if(flag==0)
	{
		printf("Valid expression\n");
	}
	exit(0);
}
