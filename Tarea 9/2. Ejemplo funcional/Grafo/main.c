#include <stdio.h>
#include <stdlib.h>
#define N 4
typedef struct Nodo
{
    int ciudad;
    struct Nodo* sig;
}Nodo;
Nodo* agregar(Nodo* lista, int ciudad)
{
    Nodo* n = malloc(sizeof(Nodo));
    n->ciudad = ciudad;
    n->sig = lista;
    return n;
}
void mostrarGrafo(Nodo* g[])
{
    const char* nombres[] = {"Santo Domingo", "Santiago", "La vega", "Punta Cana"};
    for (int i = 0; i < N; i++)
    {
        printf("\n%s -> ",nombres[i]);
        Nodo* t = g[i];
        while (t)
        {
            printf("\n%s, ", nombres[t->ciudad]);
            t = t->sig;
        }
        printf("\nFIN");
    }
}
int main()
{
    Nodo* grafo[N] = {NULL};
    grafo[0] = agregar(grafo[0], 1);
    grafo[0] = agregar(grafo[0], 2);
    grafo[1] = agregar(grafo[1], 2);
    grafo[2] = agregar(grafo[2], 3);
    mostrarGrafo(grafo);
    return 0;
}
