#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

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
    apontador primeiro;
    apontador ultimo;
} lista_t;

void inicia_lista           (lista_t *lista);
int eh_lista_vazia          (const lista_t *lista);
void imprime_lista          (const lista_t *lista);
void insere_chave_lista     (int chave, lista_t *lista);
void retira_chave_lista     (int chave, lista_t *lista);
void destroi_lista          (lista_t *lista);
int eh_chave_lista          (int chave, const lista_t *lista);
void retira_posicao_lista   (int posicao, lista_t *lista);
int ocorrencias_chave_lista (int chave, const lista_t *lista);
void insere_posicao_lista   (int posicao, int chave, lista_t *lista);

#endif // LISTA_H_INCLUDED
