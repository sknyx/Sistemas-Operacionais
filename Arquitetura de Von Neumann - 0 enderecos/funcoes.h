#include<stdio.h>

int Prioridade(char c, char t); //define a prioridade das expressões
int confere(char expr[]); //confere quantidade de caracteres na expressão matemática inserida
void In2Pos(char expr[], char pf_expr[]); //transforma a expressão de infixada para pós-fixada
