#include<stdio.h>
#include<stdlib.h>
#include"pilha.h"

void operacoes(char c){

    if(c == '*')
        printf("->  MULT\t");
    else if(c == '+')
        printf("->  ADD\t");
    else if(c == '-')
        printf("->  SUB\t");
    else if(c == '/')
        printf("->  DIV\t");
    else
        printf("->  PUSH\t%c", c);

}

int Prioridade(char c, char t)
{
    int pc,pt;

    if(c == '^')
        pc = 4;
    else if(c == '*' || c == '/')
        pc = 2;
    else if(c == '+' || c == '-')
        pc = 1;
    else if(c == '(')
        pc = 4;

    if(t == '^')
        pt = 3;
    else if(t == '*' || t == '/')
        pt = 2;
    else if(t == '+' || t == '-')
        pt = 1;
    else if(t == '(')
        pt = 0;

    return (pc > pt);
}

int j=0;

int confere(char expr[])
{
    int t=1, k=0;
    char x = expr[k];

    while(x != '\0')
    {
        if(x != '(' && x != ')')
        {
            t++;
        }
        k++;
        x = expr[k];
    }
    return t;
}

void In2Pos(char expr[], char pf_expr[])
{
    Pilha *p;
    int i = 0;
    char c, t;

    p = pilha_cria();
    pilha_push(p, '(');

    do
    {
        c = expr[i];
        i++;
        if(c >= 'a' && c <= 'z')
        {
            printf("%c", c);
            if(c != '(' && c != ')')
            {
                pf_expr[j] = c;
                j++;
            }
        }
        else if(c == '(')
        {
            pilha_push(p, '(');
        }
        else if(c == ')' || c == '\0')
        {
            do
            {
                t = pilha_pop(p);
                if(t != '(')
                    printf("%c", t);
                if(t != '(' && t != ')')
                {
                    pf_expr[j] = t;
                    j++;
                }
            }
            while(t != '(');
        }
        else if(c == '+' || c == '-' ||
                c == '*' || c == '/' ||
                c == '^' )
        {
            while(1)
            {
                t = pilha_pop(p);
                if(Prioridade(c,t))
                {
                    pilha_push(p, t);
                    pilha_push(p, c);
                    break;
                }
                else
                {
                    printf("%c", t);
                }
            }
        }
    }
    while(c != '\0');
    printf("\n\n\n");
    free(p);
}
