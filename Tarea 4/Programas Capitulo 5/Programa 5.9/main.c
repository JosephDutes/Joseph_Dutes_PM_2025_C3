#include <stdio.h>
/* Busqueda secuencial en arreglos desordenados. */
const int MAX=100;
void Lectura(int[], int); /* prototipo dee funciones */
int Busca(int *, int, int);
void main(void)
{
    int RES, ELE, TAM, VEC[MAX];
    do
    {
        printf("\nIngrese el tamano del arreglo: ");
        scanf("%d", &TAM);
    }
    while (TAM>MAX || TAM<1); /* se verifica que el tamaño del arreglo sea correcto. */
    Lectura(VEC, TAM);
    printf("\nIngrese el elemento a buscar: ");
    scanf("%d", &ELE);
    RES = Busca(VEC, TAM, ELE); /* se llasma a la funcion wue busca en el arreglo */
    if (RES) /* si RES tiene un valor verdadero -diferente a 0-, se escribe la posicion en la que se encontro el elemento */
        printf("\nEl elemento se encuentra en la posicion %d", RES);
    else printf("\nEl elemento no se encuentra en el arreglo");
}
void Lectura(int A[], int T)
/* La función Lectura se utiliza para leer un arreglo unidimensional de T elementos de tipo entero. */
{
    int I;
    for (I=0; I<T; I++)
    {
        printf("\nIngrese el elemento %d: ", I+1);
        scanf("%d", &A[I]);
}
}
int Busca(int A[], int T, int K)
/* Esta función localiza en el arreglo un elemento determinado. Si el elemento es encontrado, regresa la posición correspondiente. En caso contrario, regresa 0. */
{
    int I = 0, BAN = 0, RES;
    while (I < T && !BAN)
        if (A[I] == K)
        BAN++;
    else I++;
    if (BAN)
        RES = I + 1;
    /* Se asigna I+1 dado que las posiciones en el arreglo comienzan desde cero. */
else RES = BAN;
return (RES);
}
