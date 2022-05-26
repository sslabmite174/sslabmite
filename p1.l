%{
	#include<stdio.h>
	int identifiers=0,operators=0,braces=0,alpha=0,spaces=0;
%}
%%
[a-zA-Z] {alpha++; printf("\n alphabet:");ECHO;}
[0-9]* {identifiers++; printf("\n identifiers:");ECHO;}
[*\+] {operators++;printf("\n operators:"); ECHO;}
"(" {braces++;}
")" {braces--;}
[ ] {spaces++;}
.|\n {return 0;}
%%
void main()
{
printf("enter the expression:");
yylex();
if((braces==0)&&(operators=identifiers-1)&& alpha==0&&spaces==0)
	{
	printf("\n valid expression");
	printf("\n number of operators:%d",operators);
	printf("\n number of identifiers:%d",identifiers);
	}
	else
	printf("\n Invalid expression");
	printf("\n");
}
