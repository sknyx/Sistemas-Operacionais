/**
Disciplina: sistemas Operacionais
Nome: Carolina Ataíde de Assis
Data: 20/10/2017
**/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define TAM 10

volatile int confere = 0, k=0;

int vetor [TAM] = {0,0,0,0,0,0,0,0,0,0}, vetor_t[TAM];

int gera_numero(void)
{
    int aux = rand() % 100;
    return aux;

}

int verifica_sequencia (int num, int i, void* id)
{
    if (num == vetor [i-1]+1)
    {
        vetor[i] = num;
        vetor_t[i] = (int)id;
        return 1;
    }
    else
        return 0;
}

void imprime (int v[])
{
    int i;
    printf("\n | ");
    for (i=0; i<TAM; i++)
    {
        printf("%d | ", v[i]);
    }
    printf("\n");
}

void * preencher (void* id)
{
    int num;
    sleep(rand()%3);

    while (k<10)
    {
        if(confere == 0)
        {
            confere++;
            if (k == 0)
            {
                    num = rand() % 90;
                    vetor [k] = num;
                    vetor_t[k] = (int)id;
                    k++;
            }
            else
            {
                if (verifica_sequencia(rand()%100, k, (void*)id))
                {
                    k++;
                    sleep(rand()%3);
		    confere++;
                }
            }

            confere = 0;
            sleep(1);
        }
    }
}


int main()
{

    srand((unsigned) time(NULL));

    pthread_t t[100];

    int i;

    for(i = 0; i < 100; i++)
    {
         pthread_create(&t[i], NULL, preencher, (void *)i);

    }

    for(i=0; i<100; i++)
    {
        pthread_join(t[i], NULL);
    }

    printf("\nvetor:");
    imprime(vetor);
    printf("\nthread");
    imprime(vetor_t);
    return 0;

}


