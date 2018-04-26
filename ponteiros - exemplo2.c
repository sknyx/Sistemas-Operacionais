#include<stdlib.h>

void altera (int *, int *, int *);

main(){
       int a=1,b=2,c=3;

       printf("\tVAR \t valor \t endereco\n");
       printf("\n\n\tA \t %d \t %d\n",a,&a);
       printf("\n\tB \t %d \t %d\n",b,&b);
       printf("\n\tC \t %d \t %d\n\n",c,&c);

       system("pause");

       altera (a,b,c);

       printf("VAR \t valor \t endereco\n");
       printf("\n\tA \t %d \t %d\n",a,&a);
       printf("\n\tB \t %d \t %d\n",b,&b);
       printf("\n\tC \t %d \t %d\n\n",c,&c);

       system("pause");

       }
void altera (int *x, int *y, int *z){
     *x = 4;
     *y = 5;
     *z = 6;

     printf("Variaveis \t valor \t endereco\n");
     printf("\n\n\tX \t %d \t %d\n",*x,x);
     printf("\n\tY \t %d \t %d\n",*y,y);
     printf("\n\tZ \t %d \t %d\n\n",*z,z);

     system("pause");
     }

