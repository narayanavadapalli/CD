%{
#include<stdio.h>
#include "y.tab.h"
%}
%%
[0-9]+ {yylval.dval = atof(yytext);
return DIGIT;
}
\n|. return yytext[0];
%%
