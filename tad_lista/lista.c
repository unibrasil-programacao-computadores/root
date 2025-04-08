#include "lista.h"

void inicia_lista (lista_t *lista)
{
    lista->primeiro = (apontador) malloc(sizeof(celula));
    lista->ultimo = lista->primeiro;
    lista->ultimo->proximo = NULL;
}

int eh_lista_vazia(const lista_t *lista)
{
    return lista->primeiro == lista->ultimo;
}

void insere_chave_lista (int chave, lista_t *lista)
{
    lista->ultimo->proximo = (apontador) malloc(sizeof(celula));
    lista->ultimo = lista->ultimo->proximo;
    lista->ultimo->chave = chave;
    lista->ultimo->proximo = NULL;
}

void retira_chave_lista (int chave, lista_t *lista)
{
    apontador anterior = lista->primeiro;
    apontador atual = anterior->proximo;

    if (eh_lista_vazia(lista))
    {
        printf("Chave %d nao retirada: Lista vazia.\n", chave);
        return;
    }

    while (atual != NULL && atual->chave != chave)
    {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL)
    {
        printf("Chave %d nao encontrada na lista.\n", chave);
    } else
    {
        anterior->proximo = atual->proximo;
        atual->proximo = NULL;
        free(atual);
    }
}

void imprime_lista(const lista_t *lista)
{
    apontador aux = lista->primeiro->proximo;

    while (aux != NULL)
    {
        printf("%d ", aux->chave);
        aux = aux->proximo;
    }

    printf("\n");
}

void destroi_lista(lista_t *lista)
{
    apontador aux = lista->primeiro;
    lista->ultimo = NULL;

    while (aux != NULL)
    {
        lista->primeiro = lista->primeiro->proximo;
        free(aux);
        aux = lista->primeiro;
    }
}

/**
 * Verifica se a chave informada pertence a alguma celula da lista.
 *
 * Retorna 1, se a chave pertence � lista, ou 0, caso contr�rio.
 */
int eh_chave_lista(int chave, const lista_t *lista)
{
    return 0;
}

/**
 * Remove a celula que est� na posi��o informada da lista.
 * A posi��o 0 corresponde � celula cabe�a da lista e esta nunca
 * poder� ser removida. Logo, a primeira posi��o pass�vel de remo��o �
 * a posi��o 1.
 */
void retira_posicao_lista(int posicao, lista_t *lista)
{

}

/**
 * Contabiliza a ocorr�ncia de uma chave na lista
 *
 * Retorna um inteiro correspondente ao n�mero de ocorr�ncias da chave na lista.
 */
int ocorrencias_chave_lista(int chave, const lista_t *lista)
{
    return 0;
}

/**
 * Insere uma nova c�lula com a chave informada na posi��o indicada.
 * A c�lula cabe�a deve ser considerada como posi��o 0 e nunca deve
 * ser alterada. A primeira posi��o pass�vel de inser��o � a posi��o 1.
 */
void insere_posicao_lista(int posicao, int chave, lista_t *lista)
{

}
