#include <stdio.h>
// Archivos y caracteres. El programa lee caracteres de un archivo.

void main(void)
{
    char p1;
    FILE *ar;
    if ((ar = fopen("arc.txt", "r")) != NULL)
//Observa que lad os instrucciones del programa 9.1 necesarias para abrir un archivo y verificar que este en realidad se haya abierto, se pueden agrupar en una sola instrucion
{
    while (!feof(ar))
        // Se leem caracteres del archivo mientras no se detecte el fin del archivo
    {
        p1 = fgetc(ar); //Lee el caracter del archivo
        putchar(p1); // Despliega el caracter en la pantalla
    }
    fclose(ar);
}
else
    printf("\nNo se puede abrir el archivo");
}
