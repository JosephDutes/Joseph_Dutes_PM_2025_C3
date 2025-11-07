#include <stdio.h>
// Archivos y caddenas de caracteres. El programa lee cadenas de caracteres de un archivo
void main(void)
{
    char cad[50];
    FILE *ap;
    if ((ap=fopen ("arc.txt", "r")) != NULL)
        //Se abre el archivo para lectura y se verifica si se abrio correctsmente
    {
        while (!feof(ap))
            //Mientras no se detecte el fin de archivo se siguen leyendo cadenas de caracteres
        {
            fgets(cad, 50, ap);
            // Observa que la instruccion ppara leer cadenas requiere de tres arrgumentos
            puts(cad); //Despliega la cadena en la pantalla
        }
        fclose(ap);
    }
    else
        printf("\nNo se puede abrir el archivo");
}
