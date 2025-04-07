#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

typedef struct celula_t *apontador;
typedef struct celula_t {
    apontador direita;
    apontador abaixo;
    int linha;
    int coluna;
    float valor;
} celula;

#endif // MATRIZ_H_INCLUDED
