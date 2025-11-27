#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct
{
    int datos[MAX];
    int frente, fin;
} Cola;

void encolar(Cola* c, int x)
{
    if ((c->fin + 1) % MAX != c->frente)
        {
        c->fin = (c->fin + 1) % MAX;
        c->datos[c->fin] = x;
    }
}

int desencolar(Cola* c)
{
    if (c->frente != c->fin)
        {
        c->frente = (c->frente + 1) % MAX;
        return c->datos[c->frente];
    }
    return -1;
}

int main()
{
    Cola c = {.frente = 0, .fin = 0};

    encolar(&c, 10);
    encolar(&c, 20);
    encolar(&c, 30);

    printf("%d\n", desencolar(&c));
    printf("%d\n", desencolar(&c));

    return 0;
}
