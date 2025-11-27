#include <stdio.h>
#include <stdlib.h>
#define TAM 10
int hash (int x)
{
    return x % TAM;
}
int main()
{
    int tabla[TAM];
    for (int i = 0; i < TAM; i++) tabla[i] = -1;
    int valores[] = {15, 25, 35, 45, 55, 65};
    for (int i = 0; i < 6; i++)
    {
        int pos = hash(valores[i]);
        tabla[pos] = valores[i];
    }
    for (int i = 0; i < TAM; i++)
        printf("\n[%d] = %d", i, tabla[i]);
    return 0;
}
