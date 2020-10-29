%{
#include<stdio.h>
#include<stdlib.h>
int row = 1;
int col = 1;
%}

start \/\*
end   \*\/
%%
\/\/(.*)										{}
{start}.*{end} ;
"if"|"else"|"for"|"int"|"float"|"void"|"return" {printf("  Keyword   ->  %2d    %2d  \n",row,col);col++;}
"+"|"-"|"*"|"/"   								{printf("  arith-op  ->  %2d    %2d  \n",row,col);col++;}
"<"|">"											{printf("    relop   ->  %2d    %2d  \n",row,col);col++;}
"="												{printf(" assign-op  ->  %2d    %2d  \n",row,col);col++;}
";"|","|"("|")"|"{"|"}"							{printf(" punc-symb  ->  %2d    %2d  \n",row,col);col++;}
[a-zA-Z][a-z|0-9]* 								{printf("     ID     ->  %2d    %2d  \n",row,col);col++;}
[0-9]* 											{printf("    INUM    ->  %2d    %2d  \n",row,col);col++;}
[0-9]*"."[0-9]+									{printf("     NUM    ->  %2d    %2d  \n",row,col);col++;}
[0-9]+"."[0-9]*									{printf("     NUM    ->  %2d    %2d  \n",row,col);col++;}
"!"|"@"|"&"|"^"|"%"|"$"|"#"						{printf("   Spec-ch  ->  %2d    %2d  \n",row,col);col++;}
\n 												{row++;col=1;}
.												{}

%%
int yywrap()
{
return 1;
}
int main()
{
	yyin= fopen("input.c","r");
	printf("  Type        row    col  \n");
	printf("------------------------------\n");
	yylex();
	return 0;
}