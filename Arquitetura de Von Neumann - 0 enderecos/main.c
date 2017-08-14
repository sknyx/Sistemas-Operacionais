/**

Disciplina: Sistemas Operacionais
Nome: Carolina Ataíde de Assis
Matrícula: 161057600051

- Simulação da Arquitetura de Von Neumann - 0 endereços

**/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    char expr[100], c;

    printf("\t\t**** ARQUITETURA DE VON NEUMANN - UTILIZACAO DE 0 ENDERECOS ****\n\n");
    printf("Utilizando apenas parenteses, registradores (em minusculo) e os simbolos '+', '-', '*' e/ou '/', informe a equacao:  ");

    //gets(expr);
    scanf("%s", expr);

    int tam = confere(expr);
    char pf_expr[tam]; /*expressão pós-fixada*/

    printf("\nOrdem da expressao na pilha: ");
    In2Pos(expr, pf_expr);


    /*imprime a simulação*/

    for (int i=0; i<tam-1; i++){
        c = pf_expr[i];
        operacoes(c);
        printf("\n\n");
    }
    return 0;
   // system("pause");
}
