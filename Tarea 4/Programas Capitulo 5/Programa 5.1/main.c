#include <stdio.h>

/* Cuenta-numeros.
El programa, al recibiir como datos un arreglo unidimensional de tipo entero y un numero entero, determina cuantas veces se encuantra el numero en el arreglo */
int main(void)
{
    int I, NUM, CUE = 0;
    int ARRE[100];   /* Declaracion del arreeglo */
    for (I=0; I<100; I++)
    {
        printf("\nIngrese el elemento %d del arreglo: ", I + 1);
        scanf("%d", &ARRE[I]); /* Lectura -asignacion-- del arreglo */
    }
    printf("\nIngrese el numero que se va a buscar en el arreglo: ");
    scanf("%d", &NUM);
    for (I=0; I<100; I++)
    if(ARRE[I] == NUM) /* Comparacion del numero con los elementos del arreglo */
   CUE++;
   printf("\nEl %d se encuentra %d veces en el arreglo", NUM, CUE);
}
