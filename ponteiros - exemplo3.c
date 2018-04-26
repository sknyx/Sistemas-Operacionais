#include<stdio.h>
#include<stdlib.h>
void leiamat(int mat[3][3]);
void escrevemat(int mat[3][3]);

main(){
       int mat[3][3];
       leiamat(mat);
       escrevemat (mat);
       system("pause");
       }

void leiamat(int matriz[3][3]){
     int i, j;
     for (i=0;i<3;i++){
         for (j=0;j<3;j++){
             printf("A%d%d: ",i,j);
             scanf("%d", &matriz[i][j]);
             }
         }
     }

void escrevemat(int matriz[3][3]){
     int i, j;

     for (i=0;i<3;i++){
         printf("| ");
         for (j=0;j<3;j++){
             printf("%d ",matriz[i][j]);

             }
             printf("|\n");
         }
         printf("\n\n");
     }

