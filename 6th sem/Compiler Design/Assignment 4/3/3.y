%{

#include <stdio.h>
#include <ctype.h>
    
    
%}

%token <dval> FLOAT
%token <ival> INTEGER
%token NL 

%union
{
   float dval;
   int ival;
}

%type <dval> command exp term factor

%%

command : exp           {printf("%f\n",$1);}
    ;

exp : exp '+' term      {$$ = $1 + $3;}
    | exp '-' term      {$$ = $1 - $3;}
    | term          {$$ = $1;}
    ;

term    : term '*' factor   {$$ = $1 * $3;}
    | factor        {$$ = $1;}
    ;

factor : '(' exp ')'        {$$ = $2;}
    | FLOAT         {$$ = $1;}
    | INTEGER       {$$ = $1;}
    ;

%% 

int main()
{
	printf("Enter A expression : ");
	return yyparse();
}

int yylex(){
  int c;
  while( (c=getchar()) == ' ');

  if( isdigit(c) ){
    ungetc(c, stdin);
    float f1;
    scanf("%f", &f1);
    int i1 = (int) f1;

    if(f1 == 0){
      yylval.ival = 0;
      return INTEGER;
    }
      
    else if( (((float) i1) / f1 ) == 1){
     yylval.ival = i1;
     return INTEGER;
    }
      
    else{
     yylval.dval = f1;
     return FLOAT;
    }
      //scanf("%f",&yylval.dval);
      //return(NUMBER);
  }
   
   
  if(c == '\n') return 0;
  return c;
}

int yyerror(char *s)
{
   fprintf(stderr,"%s\n",s);
   return 0;
}
