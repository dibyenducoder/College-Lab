%{ 
  #include "y.tab.h" 
%} 
  
/* Rule Section */
%% 
[0-9]+  { yylval.ival=atoi(yytext); return INTEGER;} 
([0-9])+([.])([0-9])+ { yylval.dval=atof(yytext); return FLOAT;}
[\t] ;
\n {return NL;} 
.  {return yytext[0];} 
%% 


  
int yywrap()  {  
   return 1;  
}
