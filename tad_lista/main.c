#include "lista.h"

#define TAM_VETOR 10

int main()
{
    int i;
    int chaves[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
    lista_t lista;

    inicia_lista(&lista);

    if (eh_lista_vazia(&lista))
    {
        printf("Lista vazia.\n");
    }

    for (i = 0; i < TAM_VETOR; ++i)
    {
        insere_lista(chaves[i], &lista);
    }

    printf("Lista: ");
    imprime_lista(&lista);

    printf("Remocao da chave 3.\n");
    retira_lista(3, &lista);

    printf("Lista: ");
    imprime_lista(&lista);

    printf("Remocao da chave 9.\n");
    retira_lista(9, &lista);

    printf("Lista: ");
    imprime_lista(&lista);

    printf("Remocao da chave 55.\n");
    retira_lista(55, &lista);

    printf("Lista: ");
    imprime_lista(&lista);

    destroi_lista(&lista);

    return 0;
}
