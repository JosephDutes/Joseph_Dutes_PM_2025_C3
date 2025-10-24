#include <stdio.h>
/* Funciones para el manejo de caracteres de la biblioteca stdio.h */
void main(void)
{
char p1, p2, p3 = '$';

int c; //Variable auxiliar para limpiar el bufer
/* Declaracion de las variables tipo caracter p1, p2, y p3. Observa que a p3 se le aigna el simbolo $ */
printf("\nIngrese un caracter: ");
p1=getchar();  /* Se utiliza la funcion getchar para leer un caracter. */
putchar(p1);   /* Se utiliza la funcion putchar para escribir un caracter. */
printf("\n");
 while ((c = getchar()) != '\n' && c != EOF); /* limpiar búfer
 Verificar si es una letra Luego de leer un caracter siempre es conveniente escribir la funcion fflush para limpiar el bufer, porque generalmente queda con basura y genera un error en la ejecucion del programa. El error se produce porque cuando se ingresa un dato se oprime el return y luego cuando volvemos a leer un caracter o una cadena de caracteres se toma a ese return como el nuevo dato ingresado. */
printf("\nEl caracter p3 es: ");
putchar(p3);
/* Se utiliza la funcion putchar para escribir el caracter almacenado en p3. */
printf("\n");
printf("\nIngrese otro caracter: ");
while ((c = getchar()) != '\n' && c != EOF);
scanf("%c", &p2);
/* Se puede utilizar scanf con el formato de variable %d para leer un caracter */
printf("%c", p2);
/* Se puede utilizar printf con el formato de variable %C para escribir un caracter. */
}
