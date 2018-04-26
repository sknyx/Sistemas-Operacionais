/**Faça	um	programa	onde um	programa	iniciará	imprimindo	o valor	1,	o
   processo	pai	imprime	o	valor	2	e	o	filho	o	valor	3.
  Portanto,	na	tela	deverá	aparecer: 1	2 3.
  **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int pid;
    printf("1");
    fflush(stdout);
    /* Cria processo filho. */
    pid = fork();

    if(pid == -1)
    {
        perror("Nao e possivel criar filho") ;
        return -1 ;
    }
    else if(pid ==0)
    {
        printf("2");
        exit(0);
    }
    else
    {
        wait(0);
        printf("3");
        exit(0);
    }


}
