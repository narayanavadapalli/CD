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
