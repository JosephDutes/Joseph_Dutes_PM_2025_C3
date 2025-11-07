#include <stdio.h>

void main(void)
{
    char cad[50];
    int res;
    FILE *ar;
    if ((ar = fopen("arc.txt", "w")) != NULL)
        // Se abre el archivo para escritura. en la misma instruccion se verifica si se pude abrir
    {
        printf("\n¿Desea ingresar una cadena de carateres? Si-1  No-0:");
        scanf("%d", &res);
        while (res)
        {
        fflush(stdin);
        printf("\nIngrese la cadena: ");
        gets(cad);
        fputs(cad, ar); // Observa la forma como se escribe la cadena en el archivo
        printf("\n¿Desea ingresar otra cadena de caracteres? Si-1  No-0:");
        scanf("%d", &res);
        if (res)
        fputs("\n", ar);
        //se indica un salto de linea, excepto en la ultima cadena. Si no se hiciera esta indicacion, la funcion fputs pegaria las cadenas y luego tendriamos dificultades en el momento de leerlas. Por otra parte, si reaLizaramos este salto de linea al final de la ultima cadena, en la escritura se repetiria la ultima cadena
    }
    fclose(ar);
    }
    else
        printf("\nNo se puede abrir el archivo");
}
