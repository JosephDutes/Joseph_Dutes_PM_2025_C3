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
}Libro;
Libro* crearLibro(int ano, char autor[], char titulo[], char descripcion[], float precio, int codigo)
{
    Libro *nuevo = (Libro*)malloc(sizeof(Libro));
    if (!nuevo)
    {
        printf("\nError: No hay memoria.");
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
void agregarLibro(Libro **Lista, Libro *nuevo)
{
    if (*Lista == NULL)
    {
        *Lista = nuevo;
        return;
    }
    Libro *temp = *Lista;
    while (temp->sig != NULL)
        {
        temp = temp->sig;}
        temp->sig = nuevo;
    }
void guardarEnArchivo(Libro *Lista)
{
    FILE *f = fopen(ARCHIVO, "wb");
    if (!f)
    {
        printf("\nNo se pudo abrir el archivo.");
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
    if (!f) return NULL;
    Libro *Lista = NULL;
    Libro aux;
    while (fread(&aux, sizeof(Libro) - sizeof(Libro*), 1, f))
    {
        Libro *nuevo = crearLibro(
        aux.ano, aux.autor, aux.titulo, aux.descripcion, aux.precio, aux.codigo);
        agregarLibro(&Lista, nuevo);
    }
    fclose(f);
    return Lista;
}
void imprimirLibro(Libro *l)
{
    printf("\n------------------------------");
    printf("\nCodigo: %d", l->codigo);
    printf("\nTitulo: %s", l->titulo);
    printf("\nAutor: %s", l->autor);
    printf("\nAno: %d", l->ano);
    printf("\nPrecio: %.2f", l->precio);
    printf("\nDescripcion: %s", l->descripcion);
    printf("\n------------------------------");
}
void buscarPorTitulo(Libro *Lista, char titulo[])
{
    Libro *temp = Lista;
    int enc = 0;
    while (temp)
    {
        if (strstr(temp->titulo, titulo))
        {
            imprimirLibro(temp);
            enc = 1;
        }
        temp = temp->sig;
    }
    if (!enc) printf("\nNo se encontraron Libros con ese titulo");
}
void buscarPorAutor(Libro *Lista, char autor[])
{
    Libro *temp = Lista;
    int enc = 0;
    while (temp)
    {
        if (strstr(temp->autor, autor))
        {
            imprimirLibro(temp);
            enc = 1;
        }
        temp = temp->sig;
    }
    if (!enc)
        printf("\nNo se encontraron Libros de ese autor.");
}
void LiberarMemoria(Libro *Lista)
{
    Libro *temp;
    while (Lista)
    {
        temp = Lista;
        Lista = Lista->sig;
        free(temp);
    }
}
int main()
{
    Libro *Lista = cargarDesdeArchivo();
    int op;
    do
    {
        printf("\n=== MENU ===");
        printf("\n1. Agregar Libro");
        printf("\n2. Buscar por Titulos");
        printf("\n3. Buscar por Autor");
        printf("\n4. Guardar y salir");
        printf("\nOpcion:" );
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
            printf("\nAutor: ");
            fgets(autor, 100, stdin);
            autor[strcspn(autor, "\n")] = 0;
            printf("\nTitulo: ");
            fgets(titulo, 100, stdin);
            titulo[strcspn(titulo, "\n")] = 0;
            printf("\nDescripcion: ");
            fgets(descripcion, 200, stdin);
            descripcion[strcspn(descripcion, "\n")] = 0;
            printf("\nPrecio: ");
            scanf("%f", &precio);
            printf("\nCodigo: ");
            scanf("%d", &codigo);
            Libro *nuevo = crearLibro(ano, autor, titulo, descripcion, precio, codigo);
            agregarLibro(&Lista, nuevo);
            printf("\nLibro agregado exitosamente. ");
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
                    printf("\ningrese autor a buscar: ");
                    getchar();
                    fgets(autor, 100, stdin);
                    autor[strcspn(autor, "\n")] = 0;
                    buscarPorAutor(Lista, autor);
                }
            } while (op != 4);
            guardarEnArchivo(Lista);
            LiberarMemoria(Lista);
            printf("\nDatos guardados. Fin del programa.");
            return 0;
        }
