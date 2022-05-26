%{
#include<stdio.h>
int count=0,words=0,word=0,space=0;
%}
%%
[" "] {space++;}	
\n {words++;}
[^ \n\t]+ {word++;count=count+yyleng; }
. {count++;}

%%
int main()
{
	yyin=fopen("name.txt","r");
	
	yylex();
	
	printf("\nletters : %d",count);
	printf("lines : %d",words);
	printf("words : %d",word);
	printf("spaces : %d",space);
	return 0;
}
