#include <stdio.h>
#include <stdlib.h>
typedef struct Nodo
{
    int precio;
    struct Nodo *izq, *der;
} Nodo;
Nodo* nuevoNodo(int precio)
{
    Nodo* n = malloc(sizeof(Nodo));
    n->precio = precio;
    n->izq = n->der = NULL;
    return n;
}
Nodo* insertar(Nodo* r, int precio)
{
    if (!r) return nuevoNodo(precio);
    if (precio < r->precio) r->izq = insertar(r->izq, precio);
    else r->der = insertar(r->der, precio);
    return r;
}
void listarPrecios(Nodo* r)
{
    if(!r) return;
    listarPrecios(r->izq);
    printf("\n$%d", r->precio);
    listarPrecios(r->der);
}
int main ()
{
    Nodo* raiz = NULL;
    insertar(raiz = insertar(raiz, 500), 200);
    insertar(raiz, 675);
    insertar(raiz, 250);
    insertar(raiz, 500);
    insertar(raiz, 750);
    insertar(raiz, 300);
    insertar(raiz, 1000);
printf("\nPrecios ordenados: ");
listarPrecios(raiz);
return 0;
}
