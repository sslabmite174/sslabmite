%{
#include<stdio.h>
#include<stdlib.h>
%}
%token NUM ENTER
%left '+''-'
%left '*''/'
%%
input:exp ENTER{printf("Result is %d\n",$$);exit(0);}
exp:exp'+'exp{$$=$1+$3;}
|exp'-'exp{$$=$1-$3;}
|exp'*'exp{$$=$1*$3;}
|exp'/'exp{if($3==0){printf("dividebyzero");exit(0);}else $$=$1/$3;}
|'('exp')'{$$=$2;}
|'-'exp{$$=$2;}
|NUM{$$=$1;};
%%
void main()
{
printf("Enter The Expression\n");
yyparse();
}
int yyerror()
{
printf("Invalid Expression\n");
}


