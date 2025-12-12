#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCHIVO "libros.dat"
typedef struct Libro
{
    int ano;
    char autor[100];
    char titulo[100];
    char descripcion[200];
    float precio;
    int codigo;
    struct Libro *sig;
} Libro;

     // FUNCIONES UTILITARIAS
Libro* crearLibro(int ano, char autor[], char titulo[], char descripcion[], float precio, int codigo)
{
    Libro *nuevo = (Libro*)malloc(sizeof(Libro));
    if (!nuevo)
    {
        printf("\nError: No hay memoria disponible.\n");
        exit(1);
    }
    nuevo->ano = ano;
    strcpy(nuevo->autor, autor);
    strcpy(nuevo->titulo, titulo);
    strcpy(nuevo->descripcion, descripcion);
    nuevo->precio = precio;
    nuevo->codigo = codigo;
    nuevo->sig = NULL;
    return nuevo;
}
void imprimirLibro(Libro *l)
{
    printf("\n==============================");
    printf("\nCodigo : %d", l->codigo);
    printf("\nTitulo : %s", l->titulo);
    printf("\nAutor : %s", l->autor);
    printf("\nAno : %d", l->ano);
    printf("\nPrecio : %.2f", l->precio);
    printf("\nDescripcion : %s", l->descripcion);
    printf("\n==============================\n");
}
void agregarLibro(Libro **Lista, Libro *nuevo)
{
    if (*Lista == NULL)
    {
        *Lista = nuevo;
        return;
    }
    Libro *temp = *Lista;
    while (temp->sig != NULL)
        temp = temp->sig;
    temp->sig = nuevo;
}
void imprimirLista(Libro *Lista)
{
    if (!Lista)
    {
        printf("\nNo hay libros registrados.\n");
        return;
    }
    Libro *temp = Lista;
    printf("\n========== LISTA COMPLETA DE LIBROS ==========\n");
    while (temp)
    {
        imprimirLibro(temp);
        temp = temp->sig;
    }
}
      //  ORDENAR LISTA POR PRECIO (NODOS)
void bubbleSort(Libro **Lista)
{
    if (*Lista == NULL || (*Lista)->sig == NULL)
        return;
    Libro *i, *j;
    int swapped;
    do
    {
        swapped = 0;
        i = *Lista;
        while (i->sig != NULL)
        {
            j = i->sig;
            if (i->precio > j->precio)
            {
                /* Intercambiar datos */
                Libro temp = *i;
                i->ano = j->ano;
                strcpy(i->autor, j->autor);
                strcpy(i->titulo, j->titulo);
                strcpy(i->descripcion, j->descripcion);
                i->precio = j->precio;
                i->codigo = j->codigo;
                j->ano = temp.ano;
                strcpy(j->autor, temp.autor);
                strcpy(j->titulo, temp.titulo);
                strcpy(j->descripcion, temp.descripcion);
                j->precio = temp.precio;
                j->codigo = temp.codigo;
                swapped = 1;
            }
            i = i->sig;
        }
    } while (swapped);
    printf("\nLista ordenada por precio correctamente.\n");
}
// ARCHIVOS
void guardarEnArchivo(Libro *Lista)
{
    FILE *f = fopen(ARCHIVO, "wb");
    if (!f)
    {
        printf("\nError al abrir archivo para guardar.\n");
        return;
    }
    Libro *temp = Lista;
    while (temp)
    {
        fwrite(temp, sizeof(Libro) - sizeof(Libro*), 1, f);
        temp = temp->sig;
    }
    fclose(f);
}
Libro* cargarDesdeArchivo()
{
    FILE *f = fopen(ARCHIVO, "rb");
    if (!f)
        return NULL;
    Libro *Lista = NULL;
    Libro aux;
    while (fread(&aux, sizeof(Libro) - sizeof(Libro*), 1, f))
    {
        Libro *nuevo = crearLibro(aux.ano, aux.autor, aux.titulo, aux.descripcion, aux.precio, aux.codigo);
        agregarLibro(&Lista, nuevo);
    }
    fclose(f);
    return Lista;
}
// BUSQUEDAS
void buscarPorTitulo(Libro *Lista, char titulo[])
{
    Libro *temp = Lista;
    int encontrado = 0;
    while (temp)
    {
        if (strstr(temp->titulo, titulo))
        {
            imprimirLibro(temp);
            encontrado = 1;
        }
        temp = temp->sig;
    }
    if (!encontrado)
        printf("\nNo se encontraron libros con ese titulo.\n");
}
void buscarPorAutor(Libro *Lista, char autor[])
{
    Libro *temp = Lista;
    int encontrado = 0;
    while (temp)
    {
        if (strstr(temp->autor, autor))
        {
            imprimirLibro(temp);
            encontrado = 1;
        }
        temp = temp->sig;
    }
    if (!encontrado)
        printf("\nNo se encontraron libros de ese autor.\n");
}
    // LIBERAR MEMORIA
void liberarMemoria(Libro *Lista)
{
    Libro *temp;
    while (Lista)
    {
        temp = Lista;
        Lista = Lista->sig;
        free(temp);
    }
}
          //  MAIN
int main()
{
    Libro *Lista = cargarDesdeArchivo();
    int op;
    do
    {
        printf("\n=========== MENU ===========");
        printf("\n1. Agregar libro");
        printf("\n2. Buscar por titulo");
        printf("\n3. Buscar por autor");
        printf("\n4. Ordenar por precio");
        printf("\n5. Imprimir todos los libros");
        printf("\n6. Guardar y salir");
        printf("\nOpcion: ");
        scanf("%d", &op);
        getchar();
        if (op == 1)
        {
            int ano, codigo;
            float precio;
            char titulo[100], autor[100], descripcion[200];
            printf("\nAno: ");
            scanf("%d", &ano);
            getchar();
            printf("Autor: ");
            fgets(autor, 100, stdin);
            autor[strcspn(autor, "\n")] = 0;
            printf("Titulo: ");
            fgets(titulo, 100, stdin);
            titulo[strcspn(titulo, "\n")] = 0;
            printf("Descripción: ");
            fgets(descripcion, 200, stdin);
            descripcion[strcspn(descripcion, "\n")] = 0;
            printf("Precio: ");
            scanf("%f", &precio);
            printf("Codigo: ");
            scanf("%d", &codigo);
            Libro *nuevo = crearLibro(ano, autor, titulo, descripcion, precio, codigo);
            agregarLibro(&Lista, nuevo);
            printf("\nLibro agregado correctamente.\n");
        }
        else if (op == 2)
        {
            char titulo[100];
            printf("\nIngrese titulo a buscar: ");
            fgets(titulo, 100, stdin);
            titulo[strcspn(titulo, "\n")] = 0;
            buscarPorTitulo(Lista, titulo);
        }
        else if (op == 3)
        {
            char autor[100];
            printf("\nIngrese autor a buscar: ");
            fgets(autor, 100, stdin);
            autor[strcspn(autor, "\n")] = 0;
            buscarPorAutor(Lista, autor);
        }
        else if (op == 4)
        {
            bubbleSort(&Lista);
        }
        else if (op == 5)
        {
            imprimirLista(Lista);
        }
    } while (op != 6);
    guardarEnArchivo(Lista);
    liberarMemoria(Lista);
    printf("\nDatos guardados. Fin del programa.\n");
    return 0;
}
