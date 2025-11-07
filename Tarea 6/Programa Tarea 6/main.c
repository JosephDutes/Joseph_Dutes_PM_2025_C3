#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int codigo;
    char nombre[50];
    float precio;
    int cantidad;
}producto;
//Prototipos de funciones
producto* cargarInventario(const char* nombreArchivo, int* n);
void mostrarInventario(producto* inventario, int n);
void agregarProducto(producto** inventario, int* n);
void guardarInventario(const char* nombreArchivo, producto* inventario, int n);
int main(void)
{
    producto* inventario = NULL;
    int n = 0;
    char opcion;
    inventario = cargarInventario("inventario.txt", &n);
    if (inventario == NULL)
    {
        printf("\nNo se pudo cargar el inventario o el archivo no existe");
        return 1;
    }
    printf("\nInventario cargado con exito. Productos en inventario: %d", n);
    printf("\n¿Desea agregar un nuevo producto? (s/n): ");
    scanf(" %c", &opcion);
    if (opcion == 's' || opcion == 'S')
    {
        agregarProducto(&inventario, &n);
        guardarInventario("inventario.txt", inventario, n);
        printf("\nProducto agregado y archivo actualizado.");
    }
    printf("\n¿Desea imprimir los prodcutos en inventario? (s/n): ");
    scanf(" %c", &opcion);
    if (opcion == 's' || opcion == 'S')
        mostrarInventario(inventario, n);
    free(inventario);
    return 0;
}
// Funcion para cargar el inventario desde archivo
producto* cargarInventario(const char* nombreArchivo, int* n)
{
    FILE* f = fopen(nombreArchivo, "r");
    if (!f) return NULL;
    fscanf(f, "%d", n);
    producto* inventario = (producto*)malloc((*n) * sizeof(producto));
    if (!inventario)
    {
        fclose(f);
        return NULL;
    }
    for (int i = 0; i < *n; i++)
    {
        fscanf(f, "%d %s %f %d", &inventario[i].codigo, &inventario[i].nombre, &inventario[i].precio, &inventario[i].cantidad);
    }
fclose(f);
return inventario;
}
// Funcion para mostrar el inventario
void mostrarInventario(producto* inventario, int n)
{
    printf("\n=== LISTA DE PRODUCTOS ===\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nCodigo: %d | Nombre: %s | Precio: %.2f | Cantidad: %d ", inventario[i].codigo, inventario[i].nombre, inventario[i].precio, inventario[i].cantidad);
}
}
// Funcion para agregar un nuevo producto al inventario
void agregarProducto(producto** inventario, int* n)
{
    (*n)++;
    *inventario = (producto*)realloc(*inventario, (*n) * sizeof(producto));
    if (!(*inventario))
    {
        printf("\nError al asignar memoria.");
        exit(1);
    }
    producto nuevo;
    printf("\nIngrese codigo del producto: ");
    scanf("%d", &nuevo.codigo);
    printf("\nIngrese nombre del producto: ");
    scanf("%s", &nuevo.nombre);
    printf("\nIngrese precio: ");
    scanf("%f", &nuevo.precio);
    printf("\nIngrese cantidad: ");
    scanf("%d", &nuevo.cantidad);
    (*inventario)[(*n) - 1] = nuevo;
}
// Funcion para guardar el inventario en el archivo
void guardarInventario(const char* nombreArchivo, producto* inventario, int n)
{
    FILE* f = fopen(nombreArchivo, "w");
    if (!f)
    {
        printf("\nError al abrir el archivo para guardar.");
        return;
    }
    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d %s %.2f %d\n", inventario[i].codigo, inventario[i].nombre, inventario[i].precio, inventario[i].cantidad);
    }
    fclose(f);
}
