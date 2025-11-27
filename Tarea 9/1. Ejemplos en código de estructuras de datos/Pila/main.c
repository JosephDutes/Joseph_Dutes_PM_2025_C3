#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct
{
    int datos[MAX];
    int tope;
} Pila;
void push(Pila* p, int x)
{
    if (p->tope < MAX - 1)
        p->datos[++p->tope] = x;
}
int pop(Pila* p)
{
    if (p->tope >= 0)
        return p->datos[p->tope--];
    return -1;
}
int main()
{
    Pila p = {.tope = -1};
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
printf("\n%d", pop(&p));
printf("\n%d", pop(&p));
return 0;
}
