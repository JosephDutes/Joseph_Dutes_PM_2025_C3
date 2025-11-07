#include <stdio.h>
// Archivos y caracteres. El programa escrie caracteres en un archivo

void main(void)
{
    char p1;
    FILE *ar;
    ar = fopen("arc.txt","w"); // Se abre el archivo arc.txt para escritura
    if (ar != NULL)
    {
    while ((p1=getchar()) != '\n')
        // Se escriben caracteres en el archivo mientras mo se detecte el caracter que indica el fin de la linea
        fputc(p1, ar);
    fclose(ar);  // Se cierra el archivo
    }
    else
        printf("\nNo se puede abrir el archivo");
}
