/**Faça	um programa	que	o processo pai faz	a leitura de uma matriz de ordem 3
e o	processo filho irá ordenar essa	 matriz	e imprimir na tela.
**/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
void comb_sort(int matriz[], int tamanho)
{
    int i, j, intervalo, trocado = 1;
    int aux;
    intervalo = tamanho;
    while (intervalo > 1 || trocado == 1)
    {
        intervalo = intervalo * 10 / 13;
        if (intervalo == 9 || intervalo == 10) intervalo = 11;
        if (intervalo < 1) intervalo = 1;
        trocado = 0;
        for (i = 0, j = intervalo; j < tamanho; i++, j++)
        {
            if (matriz[i] > matriz[j])
            {
                aux = matriz[i];
                matriz[i] = matriz[j];
                matriz[j] = aux;
                trocado = 1;
            }
        }
    }
}
void main()
{

    int matriz[3][3], vetor[9];
    int i,j,t=0;
    pid_t filho;

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("[%d][%d]: ",i,j);
            scanf("%d", &matriz[i][j]);
            vetor[t] = matriz[i][j];
            t++;
        }
    }

    filho = fork();

    if(filho==0)
    {
        comb_sort(vetor,t);
        printf("\n");
        for(j=0; j<t; j++)
        {
            printf("%d\t", vetor[j]);
            if((j+1)%3==0)printf("\n");
        }
    }
}
