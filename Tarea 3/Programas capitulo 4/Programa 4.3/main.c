#include <stdio.h>
/* Conflicto de variables con el mismo nombre. */
 void f1(void);            /* Prototipo de funci�n. */
 int K = 5;               /* Variable global. */
void main(void)
{
    int I;
    for(I = 1; I <= 3; I++)
        f1();
}
void f1(void)
/* La funci�n utiliza tanto la variable local I como la variable
 global I. */
{
    int L = 2;  /* Variable local. */
    L += L;
    printf("\nEl valor de la variable local es: %d", L);
     K = K + L;   /* Uso de ambas variables. */
    printf("\nEl valor de la variable global de: %d", K);

}
