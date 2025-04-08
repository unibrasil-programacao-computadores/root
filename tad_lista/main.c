#include "lista.h"

int main()
{
    int i;
    int chaves[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
    lista_t lista;

    int tam_vetor = sizeof(chaves) / sizeof(int);

    inicia_lista(&lista);

    if (eh_lista_vazia(&lista))
    {
        printf("Lista vazia.\n");
    }

    for (i = 0; i < tam_vetor; ++i)
    {
        insere_chave_lista(chaves[i], &lista);
    }

    printf("Lista: ");
    imprime_lista(&lista);
    printf("\n");

    printf("Remocao da chave 3.\n");
    retira_chave_lista(3, &lista);
    printf("Lista: ");
    imprime_lista(&lista);
    printf("\n");

    printf("Remocao da chave 9.\n");
    retira_chave_lista(9, &lista);
    printf("Lista: ");
    imprime_lista(&lista);
    printf("\n");

    printf("Remocao da chave 55.\n");
    retira_chave_lista(55, &lista);
    printf("Lista: ");
    imprime_lista(&lista);
    printf("\n");

    printf("Busca da chave 13 na lista.\n");
    if (eh_chave_lista(13, &lista))
    {
        printf("Chave 13 encontrada na lista.\n");
    } else
    {
        printf("Chave 13 nao pertence a lista.\n");
    }
    printf("\n");

    printf("Remocao da celula na posicao 4 (chave 5) da lista\n");
    retira_posicao_lista(4, &lista);
    printf("Lista: ");
    imprime_lista(&lista);
    printf("\n");

    printf("Numero de ocorrencias da chave 1: %d\n", ocorrencias_chave_lista(1, &lista));
    printf("\n");

    printf("Adicao da chave 3 na posicao 4 da lista\n");
    insere_posicao_lista(3, 4, &lista);
    printf("Lista: ");
    imprime_lista(&lista);
    printf("\n");

    destroi_lista(&lista);

    return 0;
}
