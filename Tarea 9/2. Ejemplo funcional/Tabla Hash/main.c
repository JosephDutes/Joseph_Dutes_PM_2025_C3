#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
typedef struct Nodo
{
    char nombre[30];
    char telefono[15];
    struct Nodo* sig;
}Nodo;
int hash(char* nombre)
{
    int suma = 0;
    for (int i = 0; nombre[i]; i++)
        suma += nombre[i];
    return suma % TAM;
}
void insertar(Nodo* tabla[], char* nombre, char* telefono)
{
    int pos = hash(nombre);
    Nodo* n = malloc(sizeof(Nodo));
    strcpy(n->nombre, nombre);
    strcpy(n->telefono, telefono);
    n->sig = tabla[pos];
    tabla[pos] = n;
}
void mostrar(Nodo* tabla[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("\n[%d] ->", i);
        Nodo* t = tabla[i];
        while (t)
        {
            printf("\n (%s: %s) -> ", t->nombre, t->telefono);
            t = t->sig;
        }
        printf("\nNULL");
    }
}
int main()
{
    Nodo* tabla[TAM] = {NULL};
    insertar(tabla, "Carlos", "809-555-3406");
    insertar(tabla, "Pedro", "849-533-3000");
    insertar(tabla, "Maria", "829-444-2015");
    insertar(tabla, "Pichard", "809-345-5008");
    insertar(tabla, "Emil", "849-095-3542");
    insertar(tabla, "Jose", "829-598-3421");
    mostrar(tabla);
    return 0;
}
