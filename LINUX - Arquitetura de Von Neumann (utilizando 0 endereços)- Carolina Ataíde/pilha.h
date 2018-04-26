#include<stdio.h>

/* nó da lista para armazenar valores reais */
struct lista
{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

/* estrutura da pilha */
struct pilha
{
    Lista *topo;
};
typedef struct pilha Pilha;

Pilha *pilha_cria(void);

Pilha *pilha_push(Pilha *p, char val); /* insere elemento no inicio da pilha */

int pilha_pop(Pilha *p); /* retira o primeiro elemento da pilha */

