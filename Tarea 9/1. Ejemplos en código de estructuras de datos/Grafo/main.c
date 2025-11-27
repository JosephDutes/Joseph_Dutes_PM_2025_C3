#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct Nodo
{
    int vertice;
    struct Nodo* sig;
} Nodo;
Nodo* agregar(Nodo* lista, int v)
{
    Nodo* n = malloc(sizeof(Nodo));
    n->vertice = v;
    n->sig = lista;
    return n;
}
int main()
{
    Nodo* grafo[MAX] = {NULL};
    grafo[0] = agregar(grafo[0], 1);
    grafo[0] = agregar(grafo[0], 2);
    grafo[1] = agregar(grafo[1], 2);
    grafo[2] = agregar(grafo[2], 3);
    for (int i = 0; i < MAX; i++)
    {
        printf("\n%d: ", i);
        Nodo* temp = grafo[i];
        while (temp)
        {
            printf("\n%d -> ", temp->vertice);
            temp = temp->sig;
        }
        printf("\nNULL");
    }
}

