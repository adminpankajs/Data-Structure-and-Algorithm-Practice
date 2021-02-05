#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char stack[10][10];
char x[10];
int top = -1;
void push(char x[10])
{
    top++;
    strcpy(stack[top],x);
}
void pop()
{
    if(top == -1)
        printf("Stack is empty !! ERROR\n");
    else
        strcpy(x,stack[top]);
        top--;
}
int main()
{
    int oprnd1, oprnd2, res;
    int static i=0;
    char exp[20];
    char num[10] = "";
    int flag=0;
    // char exp[i];
    printf("Enter the postfix expression : ");
    scanf("%s",exp);
    printf("Experssion ENtered !!\n");
    // e = exp;
    while(exp[i] != '.')
    {
        // getch();
        if(exp[i] == ',')
        {
            if(flag==1)
            {
                flag=0;
            }
            else
            {
            push(num);
            strcpy(num,"");    
            }
            
        }
        else
        {
            if(isalnum(exp[i]))
            {
                strncat(num,&exp[i],1);
            }
            else
            {
                pop();
                oprnd2 = atoi(x);
                printf("\n Operand 2 : %d\n",oprnd2);
                pop();
                oprnd1 = atoi(x);
                printf("\n Operand 1 : %d\n",oprnd1);
                if (exp[i] == '+')
                {
                    res = oprnd1+oprnd2;
                    printf("RESULT : %d",res);
                    itoa(res,num,10);
                    push(num);
                    strcpy(num,"");
                }
                else if (exp[i] == '-')
                {
                    res = oprnd1-oprnd2;
                    printf("RESULT : %d",res);
                    itoa(res,num,10);
                    push(num);
                    strcpy(num,"");
                }
                else if (exp[i] == '*')
                {
                    res = oprnd1*oprnd2;
                    printf("RESULT : %d",res);
                    itoa(res,num,10);
                    push(num);
                    strcpy(num,"");
                }
                else if (exp[i] == '/')
                {
                    res = oprnd1/oprnd2;
                    printf("RESULT : %d",res);
                    itoa(res,num,10);
                    push(num);
                    strcpy(num,"");
                }
                else
                {
                    printf("ERROR !!");
                }
                flag=1;
            }
            
        }
        i++;
    }
    printf("\n ANS : %s",stack[top]);

}
