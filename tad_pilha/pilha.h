#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct celula_t *apontador;

typedef struct celula_t
{
    int chave;
    apontador proximo;
} celula;

typedef struct
{
    apontador fundo;
    apontador topo;
    int tamanho;
} pilha_t;

void inicia_pilha  (pilha_t *pilha);
int eh_pilha_vazia (const pilha_t *pilha);
void imprime_pilha (const pilha_t *pilha);
void empilha_chave (int chave, pilha_t *pilha);
int desempilha     (pilha_t *pilha);
void destroi_pilha (pilha_t *pilha);

#endif // PILHA_H_INCLUDED
