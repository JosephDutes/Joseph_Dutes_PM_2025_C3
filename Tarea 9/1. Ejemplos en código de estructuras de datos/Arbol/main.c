#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int dato;
    struct Nodo* izq;
    struct Nodo* der;
} Nodo;
Nodo* nuevoNodo(int x)
{
Nodo* n = malloc(sizeof(Nodo));
n->dato = x;
n->izq = n->der = NULL;
return n;
}
Nodo* insertar(Nodo* raiz, int x)
{
    if (!raiz) return nuevoNodo(x);
    if (x < raiz->dato) raiz->izq = insertar(raiz->izq, x);
    else raiz->der = insertar(raiz->der, x);
    return raiz;
}
void inOrden(Nodo* raiz)
{
    if (!raiz) return;
    inOrden(raiz->izq);
    printf("\n%d", raiz->dato);
    inOrden(raiz->der);
}
int main()
{
    Nodo* raiz = NULL;
    raiz = insertar(raiz, 5);
    insertar(raiz, 3);
    insertar(raiz, 7);
    insertar(raiz, 1);
    insertar(raiz, 11);
    insertar(raiz, 9);
    insertar(raiz, 13);
    insertar(raiz, 15);
    inOrden(raiz);
    return 0;
}
