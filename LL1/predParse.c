#include<stdio.h>
#include<string.h>

void pop();
void push(char);
int resolve_nt(char);
int resolve_t(char);
void advance();

char nt[] = {'E', 'A', 'T', 'B', 'F'}, ter[] = {'i','+', '*', '(', ')', '$'};
char arr[20][20][20] = {
	{"TA", " ", " ", "TA", " ", " "},
	{" ", "+TA", " ", " ", "#", "#"},
	{"FB", " ", " ", "FB", " ", " "},
	{" ", "#", "*FB", " ", "#", "#"},
	{"i", " ", " ", "(E)", " ", " "}
						};

char ipstr[20];
char stack[40], prod[10];
int i=0, top = 1, ia, ix;

void main()
{
	char a,x;
	int len, temp, k;
	stack[0]= '$';
	stack[1]= 'E';
	printf("Enter the input string\n");
	printf("Enter $ as an end marker\n");
	scanf("%s", ipstr);
	printf("input string\t\tstack constants\t\tProduction used\n");
	while(1)
	{
		a = ipstr[i];
		x = stack[top];
		
		for(k=1; ipstr[k]!='$'; k++)
		{
			printf("%c", ipstr[k]);
		}
		printf("$\t\t");
		
		if(x == a)
		{
			if(x == '$')
			{
				printf("Input string is accepted\n");
				break;
			}
			else
			{
				pop();
				advance();
			}
		}
		else if(isupper(x))
		{
			ix = resolve_nt(x);
			ia = resolve_t(a);
			strcpy(prod, arr[ix][ia]);
			len = strlen(prod);
			pop();
			for(k=1; k<=len; k++)
			{
				push(prod[len-k]);
			}
			if(stack[top] == '#')
				pop();
		}
		else
		{
			printf("Error: Could not parse the input string");
			break;
		}
		
		for(k=0; k<=top; k++)
		{
			printf("%c", stack[k]);
		}
		printf("\t\t\t\t %s\n", prod);
	}
}

void push(char k)
{
	top += 1;
	stack[top] = k;
}

void pop()
{
	top--;
}

void advance()
{
	i++;
}

int resolve_nt(char t)
{
	int k, index;
	for(k=0; k<5; k++)
	{
		if(t == nt[k])
		{
			index = k;
			break;
		}
	}
}

int resolve_t(char t)
{
	int k, index;
	for(k=0; k<6; k++)
	{
		if(t == ter[k])
		{
			index = t;
		}
	}
	return index;
}
