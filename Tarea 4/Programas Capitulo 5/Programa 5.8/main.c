#include <stdio.h>
/* Primos.
 El programa almacena en un arreglo unidimensional los primeros 100 n�meros
 primos. */
 #define TAM 100
 void Imprime(int [], int); /* prototipos de funciones */
 void Primo(int, int *);
void main(void)
{
    int P[TAM] = {1, 2};
    int FLA, J = 2, PRI = 3;
    while (J <= TAM)
    {
        FLA = 1;
        Primo(PRI, &FLA);/* Se llama a la funci�n que determina si PRI es primo. */
        if (FLA)  /* Si FLA es 11, entonces PRI es primo. */
        {
            P[J] = PRI;
            J++;
        }
        PRI += 2;
    }
    Imprime(P, TAM);
}
void Primo(int A, int *B)
 /* Esta funci�n determina si AAes primo, en cuyo caso el valor de **BB no se altera. */
{
    int DI = 3;
    while (*B && (DI <(A/2)))
    {
        if ((A % DI) == 0)
            *B = 0;
        DI++;
}
}
void Imprime(int Primos[], int T)  /* Esta funci�n imprime el arreglo unidimensional de n�meros primos. */
{
    int I;
    for (I=0; I<T; I++)
        printf("\nPrimos[%d]: %d", I, Primos[I]);
}

