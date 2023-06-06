
//First and Follow
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char a[10][10], f[10];
int n, m;
int main() {
    char c;
    int i, z;
    printf("Enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter the productions (epsilon = $):\n");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);
    do {
        m = 0;
        printf("Enter the element whose FIRST & FOLLOW are to be found: ");
        scanf(" %c", &c);
        first(c);
        printf("FIRST(%c) = {", c);
        for (i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}\n");
        m = 0;
        follow(c);
        printf("FOLLOW(%c) = {", c);
        for (i = 0; i < m; i++)
            printf("%c ", f[i]);
        printf("}\n");
        printf("Do you want to continue (0/1)? ");
        scanf("%d", &z);
    } while (z == 1);
    return 0;
}
void follow(char c) {
	int i,j;
    if (a[0][0] == c)
        f[m++] = '$';
    for ( i = 0; i < n; i++)
        for ( j = 2; j < strlen(a[i]); j++)
            if (a[i][j] == c && a[i][j + 1] != '\0') {
                first(a[i][j + 1]);
                if (a[i][j + 1] == '$' && c != a[i][0])
                    follow(a[i][0]);
            }
}
void first(char c) {
	/*wdfs*/
    if (!isupper(c))
        f[m++] = c;
	int k;
    for ( k = 0; k < n; k++)
        if (a[k][0] == c)
            if (a[k][2] == '$')
                follow(a[k][0]);
            else if (islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
}

//operator precedence
#include<stdio.h> 
#include<string.h>
 char stack[20],temp; int top=-1;
void push(char item)
{
if(top>=20)
{
printf("STACK OVERFLOW");
return;
}
stack[++top]=item;
}

char pop()
{
if(top<=-1)
{
printf("STACK UNDERFLOW");
return;
}
char c; c=stack[top--];
printf("Popped element:%c\n",c); return c;
}
char TOS()
{
return stack[top];
}
int convert(char item)
{
switch(item)
{
case 'i':return 0;
case '+':return 1;
case '*':return 2;
case '$':return 3;
}
}
int main()
{
char pt[4][4]={
{'-','>','>','>'},
{'<','>','<','>'},
{'<','>','>','>'},
{'<','<','<','1'}};
char input[20]; 
int lkh=0;
printf("Enter input with $ at the end\n");
scanf("%s",input);
push('$');
 while(lkh<=strlen(input))
{
if(TOS()=='$'&&input[lkh]=='$')
{
printf("SUCCESS\n"); return 1;
}

else if(pt[convert(TOS())][convert(input[lkh])]=='<')
{
push(input[lkh]);
printf("Push---%c\n",input[lkh]); lkh++;
}
else
{
pop();
}
}
return 0;
}


//recursive decent
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int count = 0;
char expr[10];
void E();
void T();
void Tp();
void check();
int main()
{
    printf("\nEnter an Algebraic Expression:\t");
    scanf("%s", expr);
    E();
    if ((strlen(expr) == count))
        printf("\nThe expression %s is valid\n", expr);
    else
        printf("\nThe expression %s is invalid\n", expr);
    return 0;
}
void E()
{
    T();
    if (expr[count] == '+')
    {
        count++;
        E();
    }
}
void T()
{
    check();
    if (expr[count] == '*')
    {
        count++;
        T();
    }
}
void check()
{
    if (isalnum(expr[count]))
        count++;
    else if (expr[count] == '(')
    {
        count++;
        E();
        if (expr[count] == ')')
            count++;
    }
}


3.2)2.2)2.1)
%{
#include<stdio.h> int i=0,id=0;
%}
%% [#].*[<].*[>]\n {}
[ \t\n]+ {}
\/\/.*\n {}
\/\*(.*\n)*.*\*\/ {} auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long| register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile| while 
{printf("token : %d < keyword  , %s >\n",++i,yytext);}
[+\-\*\/%<>] {printf("token : %d < operator , %s >\n",++i,yytext);} [();{}] {printf("token : %d < special char , %s >\n",++i,yytext);}
[0-9]+ {printf("token : %d < constant , %s >\n",++i,yytext);}
[a-zA-Z_][a-zA-Z0-9_]* {printf("token : %d < Id%d ,%s >\n",++i,++id,yytext);}
^[^a-zA-Z_] {printf("ERROR Invaild token %s \n",yytext);}
%%
