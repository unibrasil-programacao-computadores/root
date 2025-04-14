#include "pilha.h"

void inicia_pilha (pilha_t *pilha)
{
    pilha->topo = (apontador) malloc(sizeof(celula));
    pilha->fundo = pilha->topo;
    pilha->topo->proximo = NULL;
    pilha->tamanho = 0;
}

int eh_pilha_vazia(const pilha_t *pilha)
{
    return pilha->topo == pilha->fundo;
}

void empilha_chave (int chave, pilha_t *pilha)
{
    apontador novo_topo = (apontador) malloc(sizeof(celula));
    pilha->topo->chave = chave;
    novo_topo->proximo = pilha->topo;
    pilha->topo = novo_topo;
    pilha->tamanho++;
}

int desempilha (pilha_t *pilha)
{
    if (eh_pilha_vazia(pilha))
    {
        printf("Chave do topo nao desempilhada: pilha vazia.\n");
        return 9999999;
    } else 
    {

        apontador aux = pilha->topo->proximo;
        int chave_desempilhada = aux->chave;
        pilha->topo->proximo = aux->proximo;
        pilha->tamanho--;
        free(aux);
    
        return chave_desempilhada;
    }
}

void imprime_pilha(const pilha_t *pilha)
{
    apontador aux = pilha->topo->proximo;

    while (aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }

    printf("\n");
}

void destroi_pilha(pilha_t *pilha)
{
    apontador aux = pilha->topo;

    while (aux != NULL)
    {
        pilha->topo = pilha->topo->proximo;
        free(aux);
        aux = pilha->topo;
    }
}
