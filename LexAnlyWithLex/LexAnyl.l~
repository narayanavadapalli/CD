%{
int comment = 0;
%}

identifier[a-zA-Z][a-zA-Z0-9]*

%%
#.* {printf("\n%s is a PRE PROCESSOR DIRECTIVE", yytext);}
int |
float |
char |
double |
while |
for |
do |
if |
break |
continue |
void |
switch |
case |
long |
struct |
const |
typedef |
return |
else |
goto {printf("\n%s is a keyword", yytext);}
"/*" {COMMENT = 1;}
/*{printf("\n\n\t%s is a COMMENT\n",yytext);}*/
"*/" {COMMENT = 0;}
/* printf("\n\n\t%s is a COMMENT\n",yytext);}*/
{identifier} \( {if(!comment)printf("\n\n function \n\t %s", yytext);}
\{ {if(!comment) printf("\n Block Begins");}
\} {if(!comment) printf("\n Block Ends");}
{identifier} (\[[0-9]*\)? {if(!comment) printf("\n %s Identifier", yytext);}
\".*\" {if(!comment) printf("\n %s is a String", yytext);}
[0-9]+ {if(!comment) printf("\n %s is a Number", yytext);}
\)(\;)? {if(!comment) printf("\n\t"); ECHO;
printf("\n");
\(
=
ECHO;
{if(!comment) printf("\n\t %s is an ASSIGNMENT OPERATOR",yytext);}
\<= |
\>= |
\< |
\> |
\=={ if(!comment) printf("\n\t %s is a Relational Operator", yytext);}
%%
int main(int argc, char *argv)
{
	if(argc > 1)
	{
		FILE file;
		file = fopen(argv[1], "r");
		if(!file)
		{
			printf("Could not open %s\n", argv[1]);
			exit(0);
		}
		yyin = file;
	}
	yylex();
	printf("\n\n");
	return 0;
}

int yywrap()
{
	return 0;
}
