#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int i=0,j=0,k=0,z=0,c=0;
char a[16],stk[20],ac[20],act[20];
void check();
void main(){
    puts("Grammer is E->E+T/T\n");
    puts("Enter input string");
    gets(a);
    c=strlen(a);
    strcpy(act,"SHIFT->");
    puts("stack\t input\t action\n");
    for(k=0,i=0;j<c;k++,i++,j++){
        if(a[j]=='i' && a[j+1]=='d'){
            stk[i]=a[j];
            stk[i+1]=a[j+1];
            stk[i+2]='\0';
            a[j]=' ';
            a[j+1]=' ';
            printf("\n$%s\t%s$\t%sid\n",stk,a,act);
            check();
        }
        else{
            stk[i]=a[j];
            stk[i+1]='\0';
            a[j]=' ';
            printf("\n$%s\t%s$\t%ssymbol\n",stk,a,act);
            check();
        }
    }
}
void check(){
    strcpy(ac,"REDUCE");
    for(z=0;z<c;z++)
        if(stk[z]=='(' && stk[z+1]=='E' && stk[z+2]==')'){
            stk[z]='F';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("\n$%s\t%s$\t%s\n",stk,a,ac);
            i=i-2;
        }
    for(z=0;z<c;z++){
        if(stk[z]=='i' && stk[z+1]=='d'){
            stk[z]='F';
            stk[z+1]='\0';
            printf("\n$%s\t%s$\t%s\n",stk,a,ac);
            j++;
        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=='T' && stk[z+1]=='*' && stk[z+2]=='F'){
           stk[z]='T';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("\n$%s\t%s$\t%s\n",stk,a,ac);
            i=i-2; 
        }
        else if(stk[z]=='F'){
            stk[z]='T';
            printf("\n$%s\t%s$\t%s\n",stk,a,ac);
        }
    }
    for(z=0;z<c;z++){
        if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T' && stk[z+3]=='*')break;
        if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T'){
            if(a[j+1]=='*')break;
 
          else
          { 
            stk[z]='E';
            stk[z+1]='\0';
            stk[z+2]='\0';
            printf("\n$%s\t%s$\t%s\n",stk,a,ac);
            i=i-2; 
            
          }
        }
        else if(stk[z]=='T'){
            stk[z]='E';
            printf("\n$%s\t%s$\t%sid\n",stk,a,ac);
            
        }
    }
}
