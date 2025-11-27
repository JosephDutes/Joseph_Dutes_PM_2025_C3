#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Nodo
{
    char tarea[50];
    struct Nodo* sig;
}Nodo;
Nodo* crearNodo(char* t)
{
Nodo* n = malloc(sizeof(Nodo));
strcpy(n->tarea, t);
n->sig = NULL;
return n;
}
void agregarTarea(Nodo** lista, char* t)
{
    Nodo* n = crearNodo(t);
    n->sig = *lista;
    *lista = n;
}
void mostrarTareas(Nodo* lista)
{
    printf("\nTareas pendientes: ");
    while (lista)
    {
        printf("\n- %s", lista->tarea);
        lista = lista->sig;
    }
}
int main()
{
    Nodo* lista = NULL;
    agregarTarea(&lista, "Hacer tarea de PM");
    agregarTarea(&lista, "Sacar la basura");
    agregarTarea(&lista, "Llamar a mi hermana");
    agregarTarea(&lista, "lavar el auto");
    agregarTarea(&lista, "buscar a mi tia");
    agregarTarea(&lista, "Trabajar en el almacen");
    agregarTarea(&lista, "Cocinar para todos");
    mostrarTareas(lista);
    return 0;
}
