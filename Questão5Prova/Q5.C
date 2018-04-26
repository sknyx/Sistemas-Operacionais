
#include <stdio.h>
#include <stdlib.h>
    #include <unistd.h>

int main()
{
    int fd[2];
    int i,j;
    pid_t pid;

    pipe(fd);

    pid = fork();

    if(pid > 0) //pai
    {
        int matriz[3][3];

        printf("Insira os elementos\n");

        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                printf("E[%d,%d]:",i+1,j+1);
                scanf("%d",&matriz[i][j]);
            }
        }
        write(fd[1],matriz,sizeof(matriz));

    }else{//filho
        int m[3][3];
        int maior,menor;

        read(fd[0],m,sizeof(m));

        maior=m[0][0];
        menor=m[0][0];

        for(i=0; i<3; i++)
        {
            for(j=0; j<3; j++)
            {
                if(m[i][j] > maior)
                    maior = m[i][j];
                if(m[i][j] < menor)
                    menor = m[i][j];
            }
        }

        printf("Maior: %d \nMenor: %d",maior,menor);
    }

}
