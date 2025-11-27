#include <stdio.h>
#include <string.h>
#define MAX 5
typedef struct
{
    char paginas[MAX][50];
    int tope;
}Pila;
void visitar(Pila* p, char* url)
{
    if (p->tope < MAX - 1)
    strcpy(p->paginas[++p->tope], url);
}
char* regresar(Pila* p)
{
if (p->tope >= 0)
    return p->paginas[p->tope--];
return "sin historial";
}
int main()
{
    Pila historial = {.tope = -1};
    visitar(&historial, "google.com");
    visitar(&historial, "youtube.com");
    visitar(&historial, "tiktok.com");
    printf("\nRegresando desde: %s",regresar(&historial));
    printf("\nRegresando desde: %s", regresar(&historial));
    return 0;
}
