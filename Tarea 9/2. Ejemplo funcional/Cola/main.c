#include <stdio.h>
#define MAX 5

typedef struct
 {
    int turno[MAX];
    int frente;
    int fin;
} Cola;

void encolar(Cola* c, int t)
{
    if ((c->fin + 1) % MAX != c->frente)
        {
        c->fin = (c->fin + 1) % MAX;
        c->turno[c->fin] = t;
    }
}
int atender(Cola* c)
 {
    if (c->frente != c->fin)
        {
        c->frente = (c->frente + 1) % MAX;
        return c->turno[c->frente];
    }
    return -1;
}
int main()
{
    Cola banco = {.frente = 0, .fin = 0};
    encolar(&banco, 101);
    encolar(&banco, 102);
    encolar(&banco, 103);
    printf("Atendiendo turno: %d\n", atender(&banco));
    printf("Atendiendo turno: %d\n", atender(&banco));
    return 0;
}
