%{
	#include<stdio.h>
	#include "y.tab.h"
	extern int yylval;
%}

%%
[0-9]+ {yylval=atoi(yytext);return NUMBER;}
[\t]+;
\n     {return NL;}
.      {return yytext[0];}
%%

int yylex();
int yywrap()
{
	return 1;
}
