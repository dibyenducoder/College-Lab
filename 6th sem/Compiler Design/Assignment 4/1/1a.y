%{
#include<stdio.h>
#include<stdlib.h>
%}

%token A B NL

%%
stmt: S NL {printf("Expression is Valid\n");
             exit(0);}
;
S: A S B 
| A S
| S B
|
;
%%

int yyerror(char *msg)
{
printf("Expression is Invalid\n");
exit(0);
}

main()
{
printf("Enter Expression : ");
yyparse();
}