#include<stdio.h>

int Prioridade(char c, char t); //define a prioridade das express�es
int confere(char expr[]); //confere quantidade de caracteres na express�o matem�tica inserida
void In2Pos(char expr[], char pf_expr[]); //transforma a express�o de infixada para p�s-fixada
