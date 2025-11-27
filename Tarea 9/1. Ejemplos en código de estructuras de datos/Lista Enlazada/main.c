#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int dato;
    struct Nodo* sig;
} Nodo;
Nodo* CrearNodo(int x)
{
    Nodo* n = malloc(sizeof(Nodo));
    n->dato = x;
    n->sig = NULL;
    return n;
}
void insertarInicio(Nodo** Lista, int x)
{
    Nodo* n = CrearNodo(x);
    n->sig = *Lista;
    *Lista = n;
}
void imprimir(Nodo* lista)
{
    while (lista)
    {
        printf("\n%d -> ", lista->dato);
        lista = lista->sig;
    }
    printf("\n NULL");
}
int main()
{
    Nodo* lista = NULL;
    insertarInicio(&lista, 3);
    insertarInicio(&lista, 2);
    insertarInicio(&lista, 1);
    imprimir(lista);
    return 0;
}
