#include <stdio.h>
/* Paso de una funcion como parametro por referencia. */

int suma(int X, int Y)
/* La funcion Suma regresa la suma de los parametros de tipo entero X y Y. */
{
    return (X+Y);
}
int resta(int X, int Y)
/* Esta funcion regresa la resta de los parametros de tipo entero X y Y. */
{
    return (X-Y);
}
int control(int (*apf) (int, int), int X, int Y)
/* Esta funcion recibe como parametro otra funcion -la direccion- y dependiendo de cual sea esta, llama a la funcion Suma o Resta */
{
    int RES;
    RES = (*apf) (X, Y); /* Se llama a la funcion Suma o Resta. */
return (RES);
}
void main(void)
{
    int R1, R2;
    R1 = control(suma, 15, 5); /* Se pasa como parametro la funcion suma */
    R2 = control(resta, 10, 4); /* Se pasa como parametro la funcion resta */
    printf("\nResultado 1: %d", R1);
    printf("\nResultado 2: %d", R2);
}
