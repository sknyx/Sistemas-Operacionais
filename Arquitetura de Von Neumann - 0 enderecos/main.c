/**

Disciplina: Sistemas Operacionais
Nome: Carolina Ata�de de Assis
Matr�cula: 161057600051

- Simula��o da Arquitetura de Von Neumann - 0 endere�os

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
    char pf_expr[tam]; /*express�o p�s-fixada*/

    printf("\nOrdem da expressao na pilha: ");
    In2Pos(expr, pf_expr);


    /*imprime a simula��o*/

    for (int i=0; i<tam-1; i++){
        c = pf_expr[i];
        operacoes(c);
        printf("\n\n");
    }
    return 0;
   // system("pause");
}
