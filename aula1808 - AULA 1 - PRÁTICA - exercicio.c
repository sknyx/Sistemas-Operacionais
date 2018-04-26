#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>

void main()
{

    int i;
    float j;
    char k, s;

    printf("(1) main = %5p\n", &main);
    printf("(2) int i = %10p\n", &i);
    printf("(3) float j = %10p\n", &j);
    printf("(4) char k = %10p\n", &k);
    printf("(5) char s = %10p\n\n", &s);

    printf("Topo do processo: %10p", sbrk(0));


    if(sbrk(1024) == -1)
        printf("\n\nNão foi possível alterar o segmento de dados\n");

    printf("\nProcesso break = %10p\n", sbrk(0));

    /**    if(sbrk(1024) == -1)
            printf("\nNão foi possível alterar o segmento de dados\n");

        printf("\n(3) Processo break = %10p\n", sbrk(0));
    **/

    return 0;

}
