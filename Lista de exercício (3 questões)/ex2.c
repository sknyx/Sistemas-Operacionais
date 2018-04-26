/**Faça   um     programa  que    o   programa   leia     um    vetor  de   5    posições,
processo filho  irá contar a quantidade  de    números pares de vetor.
O processo  pai irá receber o filho  esse qtdetório  e  imprimir  na
tela. **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{

    int vetor[5];
    int i, qtde=0;
    pid_t filho;
    int fd1[2],fd2[2];
    int turn=0; /* Vai definir o que cada um vai fazer (ler, escrever, aguardar...) */

    /* Cria o pipe 1 */
    if(pipe(fd1)<0)
    {
        perror("pipe") ;
        return -1 ;
    }
    /* Cria o pipe 2 */
    if(pipe(fd2)<0)
    {
        perror("pipe") ;
        return -1 ;
    }

    filho = fork();

    if(filho == -1)
    {
        perror("fork") ;
        return -1 ;
    }

    if(filho > 0)
    {
        /* Fechando o descritor LEITURA no primeiro pipe. */
        close(fd1[0]);
        /* Fechando o descritor ESCRITA no segundo pipe. */
        close(fd2[1]);


        while(1)
        {
            if(turn==0)   /* Pai vai escreever */
            {
                for (i=0; i<5; i++)
                {
                    printf("Insira o elemento %d do vetor: ",i);
                    scanf("%d", &vetor[i]);
                }

                write(fd1[1], &vetor, sizeof(vetor)); /* Enviando o vetor pro filho */
                turn=1; /* Passa para o próximo passo, que é o pai ler a qtde do filho */
            }
            else if(turn==1)   /* Pai vai ler a qtde */
            {
                read(fd2[0], &qtde, sizeof(qtde)); /* Pai leu o resultado da qtde, e armazenou no inteiro 'qtde' */
                printf("qtde: %d\n\n", qtde);
                turn=0;  /* Retorna pro passo anterior, pra começar tudo de novo */
            }
        }

        close(fd2[0]);
        close(fd1[1]);
    }
    else
    {
        /* Fechando o descritor ESCRITA no primeiro pipe. */
        close(fd1[1]);
        /* Fechando o descritor LEITURA no segundo pipe. */
        close(fd2[0]);

        while (1)
        {
            if(turn==0)  /* Filho vai ler o vetor de numeros do pai */
            {
                read(fd1[0], &vetor, sizeof(vetor) ); /* Recebeu o vetor de inteiros do pai e colocou no vetor */
                turn=1;  /* Passa para o próximo passo, que é o filho qtder e escrever o resultado da qtde */
            }
            else if(turn==1)   /* Filho calcula a qtde e retorna pro pai */
            {
                int j;
                for(j=0, qtde=0; j<5; j++)
                {
                    if(vetor[j] % 2 == 0)
                    {
                        qtde++;
                    }
                }
                write(fd2[1], &qtde, sizeof(qtde)); /* Envia a qtde, qúe está na variável 'qtde', para o pai */
                turn=0; /* Volta para o passo anterior, que é esperar vetor de inteiros do pai */
            }
        }
        close(fd2[1]);
        close(fd1[0]);
        return 0;
    }
}


