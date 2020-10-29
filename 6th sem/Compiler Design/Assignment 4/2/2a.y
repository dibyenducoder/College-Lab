%{
#include<stdio.h>
%}


%token NUMBER ID
%left '+' '-' 
%left '*' '/'
%%

expr: expr '+' expr 
     |'('expr')'
     |NUMBER
     |ID
     ;
%% 
int yylex();
int yyerror(char *s)
{
printf("Expression is Invalid\n");
exit(0);
}

int main()
{
printf("Enter Expression: ");
yyparse();
printf("Expression is Valid\n");
exit(0);
}
