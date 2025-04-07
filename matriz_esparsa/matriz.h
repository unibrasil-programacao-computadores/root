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

typedef struct {
    int m_linhas;
    int n_colunas;
    apontador raiz;
} matriz;

void le_matriz        (matriz* mat);
void apaga_matriz     (matriz* mat);
void soma_matriz      (matriz* mat1, matriz* mat2, matriz* mat_soma);
void multiplica_matriz(matriz* mat1, matriz* mat2, matriz* mat_produto);
void imprime_matriz   (matriz* mat);
void insere_na_matriz (int linha, int coluna, float valor, matriz* mat);

#endif // MATRIZ_H_INCLUDED
