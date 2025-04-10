#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

int main()
{
    matriz matA, matB, matC;

    le_matriz(&matA);
    imprime_matriz(&matA);

    le_matriz(&matB);
    imprime_matriz(&matB);

    soma_matriz(&matA, &matB, &matC);
    imprime_matriz(&matC);
    apaga_matriz(&matC);

    multiplica_matriz(&matA, &matB, &matC);
    imprime_matriz(&matC);
    apaga_matriz(&matC);

    apaga_matriz(&matA);
    apaga_matriz(&matB);

    return 0;
}
