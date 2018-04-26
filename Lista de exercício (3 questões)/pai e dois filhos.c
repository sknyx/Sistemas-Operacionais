#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    int vet[5];
    int i;

    pid_t filho1,filho2;

    for(i=0; i<5; i++)
    {
        printf("%d: ",i);
        scanf("%d", &vet[i]);
    }

    filho1 = fork();

    if(filho1 == 0)
    {
        int soma=0,j;
        for(j=0; j<5; j++)
        {
            if(vet[j] % 2 == 0)
            {
                soma += vet[j];
            }
        }
        printf("Soma dos pares: %d\n", soma);
    }
    else
    {
        filho2 = fork();
        if(filho2 == 0)
        {
            int soma=0,j;
            for(j=0; j<5; j++)
            {
                if(vet[j] % 2 != 0)
                {
                    soma += vet[j];
                }
            }
            printf("Soma dos impares: %d\n", soma);
        }
    }
    return 0;
}
