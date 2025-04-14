#include "pilha.h"

int main()
{
    int i;
    int chaves[] = { 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };
    pilha_t pilha;

    int tam_vetor = sizeof(chaves) / sizeof(int);

    inicia_pilha(&pilha);

    if (eh_pilha_vazia(&pilha))
    {
        printf("Pilha vazia.\n");
    }

    for (i = 0; i < tam_vetor; empilha_chave(chaves[i++], &pilha));

    printf("pilha: ");
    imprime_pilha(&pilha);
    printf("\n");

    printf("Remocao do topo da pilha: %d\n", desempilha(&pilha));
    printf("pilha: ");
    imprime_pilha(&pilha);
    printf("\n");

    printf("Remocao do topo da pilha: %d\n", desempilha(&pilha));
    printf("pilha: ");
    imprime_pilha(&pilha);
    printf("\n");

    destroi_pilha(&pilha);

    return 0;
}
