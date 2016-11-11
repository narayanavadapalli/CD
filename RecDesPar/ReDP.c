#include<stdio.h>

void E(), E1(), T(), T1(), F();

int ip = 0;
static char s[10];

void main()
{
	printf("Enter String : ");
	scanf("%s", s);
	printf("The string is %s",s);
	E();
	if(s[ip] == '$')
		printf("\n String is accepted");
	else
		printf("\n String is not accepted");
}

void E()
{
	T();
	E1();
	return;
}

void E1()
{
	if(s[ip] == '+')
	{
		ip++;
		T();
		E1();
	}
	return;
}

void T()
{
	F();
	T1();
	return;
}

void T1()
{
	if(s[ip] == '*')
	{
		ip++;
		F();
		T1();
	}
	return;
}

void F()
{
	if(s[ip] == '(')
	{
		ip++;
		E();
		if(s[ip] == ')')
		{
			ip++;
		}
	}
	else if(s[ip] == 'a')
		ip++;
	else
		printf("Id expected");
	return;
}

