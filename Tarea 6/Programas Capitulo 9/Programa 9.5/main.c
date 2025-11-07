#include <stdio.h>
//Archivos con variables enteras y reales.
//El programa almacena datos de un grupo de alumnos en un archivo
void main(void)
{
    int i, j, n, mat;
    float cal;
    FILE *ar;
    printf("\ningrese el numero de alumnos: ");
    scanf("%d", &n); // Se asume que el valor que ingresa el usuario esta comprendido entre 1 y 35
    if ((ar = fopen("arc8.txt", "w")) != NULL)
    {
        fprintf(ar, "\n%d", n);//Se escribe el numero de alumos en el archivo
        for (i=0; i<n; i++)
        {
            printf("\nIngrese la matricula del alumno %d: ", i+1);
            scanf("%d", &mat);
            fprintf(ar, "\n%d", mat); //Se escribe la matricula en el archivo
            for (j=0; j<5; j++)
            {
                printf("\nCalificacion %d: ", j+1);
                scanf("%f", &cal);
                fprintf(ar, "\n%.2f", cal); //Se escriben las calificaciones en el archivo
            }
        }
        fclose(ar);
    }
else
printf("\nNo se puede abrir el archivo");
}
