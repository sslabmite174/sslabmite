%{
	#include<stdio.h>
	int flag=0;
%}
%%

"AND"|"OR"|"BUT"|"NOT"|"and"|"or"|"but"|"not" {flag=1;}
"\n" {if(flag==1)
	  	printf("compound sentence\n");
	else
		printf("simple sentence\n");}
 	

%%
void main()
{
	printf("enter the sentence\n");
	yylex();
	
	
}
