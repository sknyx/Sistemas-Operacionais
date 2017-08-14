#include<stdio.h>
#include"pilha.h"
#include<stdlib.h>

Pilha *pilha_cria(void)
{
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

Pilha *pilha_push(Pilha *p, char val)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = val;
    novo->prox = p->topo;
    p->topo = novo;

    return 0;
}

int pilha_pop(Pilha *p)
{
    Lista* temporario;
    int val;

    temporario = p->topo;
    val = temporario->info;
    p->topo = temporario->prox;
    free(temporario);
    return val;
}
