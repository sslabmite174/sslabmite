%{
#include<stdio.h>
int count=0;
%}
%%

. {count++;}

%%
int main()
{
	yylex();
	printf("count is %d",count);
	if(count>0)
		printf("pattern is matched\n");
	else
		printf("pattern not matched\n");
	return 0;
}
