#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a = 0.0;
    float b = 0.0;
    printf("\nIngresa el numero para calcular la raiz cuadrada:");
    scanf("%f",&a) ;
    b = a;
    while (!(b == (a/b)))
    {
        b = 0.5 * ((a/b)+b);
    }
    printf("\nLa raiz cuadrada de %f es %f",a,b);
    return 0;
    }
