#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARCHIVO_V "vehiculos.dat"
#define ARCHIVO_C "combustible.dat"
// Estructuras
typedef struct
{
    int id;
    char marca[50];
    char modelo[50];
    int ano;
    char placa[20];
    float consumo_ciudad; // L/100km
    float consumo_carretera; // L/100km
    float costo_seguro; // por año
    float costo_cambio_km; //  mantenimiento por km
    float tiempo_depreciacion; // años
    float costo_vehiculo; //
    float km_promedio_anual;
    float costo_limpieza;
} vehiculo;
typedef struct
{
    int id;
    char nombre[50];
    float precio_litro;
} combustible;
//Prototipos
void menuVehiculos();
void menuCombustible();
void agregarVehiculo();
void listarVehiculos();
void modificarVehiculos();
void agregarCombustible();
void ListarCombustibles();
void modificarCombustible();
void calcularViaje();

int main(void)
{
    int op;
    do
    {
        printf("\n== SISTEMA DE COSTO DE VIAJE ==\n");
        printf("\n 1.Vehiculos");
        printf("\n 2.Combustible");
        printf("\n 3.Calcular viaje");
        printf("\n 4. Salir");
        printf("\nOpcion:");
        scanf("%d", &op);
        switch(op)
        {
            case 1: menuVehiculos(); break;
            case 2: menuCombustible(); break;
            case 3: calcularViaje(); break;
            case 4: printf("\nSaliendo.."); break;
            default: printf("\nOpcion invalida.");
        }
    }
    while(op != 4);
    return 0;
}
//Menu vehiculos
void menuVehiculos()
{
    int op;
    do
    {
        printf("\n-- MENU VEHICULOS --");
        printf("\n 1.Agregar vehiculos");
        printf("\n 2.Listar vehiculos");
        printf("\n 3.modificar vehiculo");
        printf("\n 4.Volver");
        printf("\nOpcion: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: agregarVehiculo(); break;
            case 2: listarVehiculos(); break;
            case 3: modificarVehiculos(); break;
        }
    }
    while(op != 4);
}
// Menu combustible
void menuCombustible()
{
   int op;
    do
    {
        printf("\n-- MENU COMBUSTIBLE --");
        printf("\n 1.Agregar combustibles");
        printf("\n 2.Listar combustible");
        printf("\n 3.modificar combustible");
        printf("\n 4.Volver");
        printf("\nOpcion: ");
        scanf("%d", &op);
        switch(op)
        {
            case 1: agregarCombustible(); break;
            case 2: ListarCombustibles(); break;
            case 3: modificarCombustible(); break;
        }
    }
    while(op != 4);
}
// Agregar vehiculo
void agregarVehiculo()
{
    FILE *f = fopen(ARCHIVO_V, "ab");
    if(!f)
    {
        printf("\nError al abrir archivo");
        return;
    }
    vehiculo v;
    printf("\nID: ");
    scanf("%d", &v.id);
        printf("\nMarca: ");
    scanf("%s", v.marca);
        printf("\nmodelo: ");
    scanf("%s", v.modelo);
        printf("\nAno: ");
    scanf("%d", &v.ano);
        printf("\nPlaca: ");
    scanf("%s", v.placa);
        printf("\nConsumo Ciudad (L/100km): ");
    scanf("%f", &v.consumo_ciudad);
        printf("\nConsumo Carretera (L/100km): ");
    scanf("%f", &v.consumo_carretera);
        printf("\nCosto Seguro (ano): ");
    scanf("%f", &v.costo_seguro);
        printf("\nCosto Cambio por km: ");
    scanf("%f", &v.costo_cambio_km);
        printf("\nTiempo de depreciacion: ");
    scanf("%f", &v.tiempo_depreciacion);
        printf("\nCosto del vehiculo: ");
    scanf("%f", &v.costo_seguro);
        printf("\nkm promedio por ano: ");
    scanf("%f", &v.km_promedio_anual);
        printf("\nCosto Limpieza por viaje: ");
    scanf("%f", &v.costo_limpieza);
    fwrite(&v, sizeof(vehiculo), 1, f);
    fclose(f);
    printf("\nvehiculo agregado.");
}
// Listar vehiculos
void listarVehiculos()
{
    FILE *f = fopen(ARCHIVO_V, "rb");
    if(!f)
    {
        printf("\nNo hay vehiculos.");
        return;
    }
    vehiculo v;
        printf("\n-- LISTA DE VEHICULOS --");
        while(fread(&v, sizeof(vehiculo), 1, f))
        {
          printf("\nID: %d", v.id);
        printf("\nMarca: %s", v.marca);
        printf("\nmodelo: %s", v.modelo);
        printf("\nPlaca: %s", v.placa);
        printf("\nConsumo Ciudad: %.2f L/100km: ", v.consumo_ciudad);
        printf("\nConsumo Carretera: %.2f L/100km: ", v.consumo_carretera);
        printf("\nCosto Cambio por km: %.2f", v.costo_cambio_km);
        printf("\n-------------------------------");
        }
        fclose(f);
}
// Modificar vehiculo
void modificarVehiculos()
{
    FILE *f = fopen(ARCHIVO_V, "r+b");
    if(!f)
    {
        printf("\nNo hay vehiculos.");
        return;
    }
    int buscado;
    printf("\nID del vehiculo a modificar: ");
    scanf("%d", &buscado);
    vehiculo v;
    while(fread(&v, sizeof(vehiculo), 1, f))
    {
        if(v.id == buscado)
        {
            printf("\nNuevo consumo ciudad (L/100km): ");
            scanf("%f", &v.consumo_ciudad);
            printf("\nNuevo consumo carretera (L/100km): ");
            scanf("%f", &v.consumo_carretera);
            printf("\nNuevo costo cambio por Km: ");
            scanf("%f", &v.costo_cambio_km);
            fseek(f, -sizeof(vehiculo), SEEK_CUR);
            fwrite(&v, sizeof(vehiculo), 1, f);
            printf("\nvehiculo modificado.");
            fclose(f);
            return;
        }
    }
    printf("\nVehiculo no encontrado.");
    fclose(f);
}
//Agregar combustible
void agregarCombustible()
{
    FILE *f = fopen(ARCHIVO_C, "ab");
    if(!f)
    {
        printf("\nError al abrir archivo.");
        return;
    }
    combustible c;
    printf("\nID: ");
    scanf("%d", &c.id);
        printf("\nNombre: ");
    scanf("%s", c.nombre);
        printf("\nPrecio por litro: ");
    scanf("%f", &c.precio_litro);
    fwrite(&c, sizeof(combustible), 1, f);
    fclose(f);
    printf("\nCombustible agregado.");
}
// Listar combustible
void ListarCombustibles()
{
    FILE *f = fopen(ARCHIVO_C, "rb");
    if(!f)
    {
        printf("\nNo hay combustibles.");
        return;
    }
    combustible c;
    printf("\n-- LISTA DE COMBUSTIBLE --");
    while(fread(&c, sizeof(combustible), 1, f))
    {
        printf("\nID: %d", c.id);
        printf("\nNombre: %s", c.nombre);
        printf("\nPrecio por litro: %.2f", c.precio_litro);
        printf("\n--------------------------");
    }
    fclose(f);
}
//Modificar combustible
void modificarCombustible()
{
    FILE *f = fopen(ARCHIVO_C, "r+b");
    if(!f)
    {
        printf("\nNo hay combustibles.");
        return;
    }
    int buscado;
    printf("\nID del combustible a modificar: ");
    scanf("%d", &buscado);
    combustible c;
    while(fread(&c, sizeof(combustible), 1, f))
          {
              if(c.id == buscado)
            {
                printf("\nNuevo precio por litro: ");
                scanf("%f", &c.precio_litro);
                fseek(f, -sizeof(combustible), SEEK_CUR);
                fwrite(&c, sizeof(combustible), 1, f);
                printf("\nCombustible modificado.");
                fclose(f);
                return;
            }
          }
          printf("\nCombustible no encontrado.");
          fclose(f);
}
//Calcular viaje
void calcularViaje()
{
    FILE *fv = fopen(ARCHIVO_V, "rb");
        FILE *fc = fopen(ARCHIVO_C, "rb");
        if(!fv || !fc)
        {
            printf("\ndebe registrar vehiculos y combustibles primero.");
            return;
        }
        int idv, idc;
        float km, porc_ciudad;
        listarVehiculos();
        printf("\nID del vehiculo: ");
        scanf("%d", &idv);
        ListarCombustibles();
        printf("\nID del combustible: ");
        scanf("%d", &idc);
        printf("\nKilometros del viaje: ");
        scanf("%f", &km);
        printf("\n%% del viaje en ciudad: ");
        scanf("%f", &porc_ciudad);
        vehiculo v;
        combustible c;
        int foundV = 0, foundC = 0;
        rewind(fv);
        while(fread(&v, sizeof(vehiculo), 1, fv))
        {
            if(v.id == idv)
            {
                foundV = 1; break;
            }
        }
        if(!foundV)
        {
            printf("\nVehiculo no encontrado.");
            fclose(fv);
        fclose(fc);
        return;
        }
         while(fread(&c, sizeof(combustible), 1, fc))
         {
             if(c.id == idc)
             {
                 foundC = 1;
                 break;
             }
         }
         if(!foundC)
         {
             printf("\nCombustible no encontrado.");
             fclose(fv);
             fclose(fc);
             return;
         }
         fclose(fv);
         fclose(fc);
        //Calculos
        float Km_ciudad = km * (porc_ciudad/100);
        float Km_carretera = km - Km_ciudad;
        float litros_ciudad = (v.consumo_ciudad/100) * Km_ciudad;
        float litros_carretera = (v.consumo_carretera/100) * Km_carretera;
        float costo_combustible = (litros_ciudad + litros_carretera) * c.precio_litro;
        float depreciacion_anual = v.costo_vehiculo / v.tiempo_depreciacion;
        float depreciacion_Km = depreciacion_anual / v.km_promedio_anual * km;
        float seguro_Km = v.costo_seguro / v.km_promedio_anual * km;
        float mantenimiento = v.costo_cambio_km * km;
        float costo_total = costo_combustible + depreciacion_Km + seguro_Km + mantenimiento + v.costo_limpieza;
        float costo_por_Km = costo_total / km;
        //Resultados
        printf("\n=== RESULTADOS ===");
        printf("\nCosto combustible:  %.2f",costo_combustible);
        printf("\nDepreciacion:  %.2f", depreciacion_Km);
        printf("\nSeguro:  %.2f", seguro_Km);
        printf("\nMantenimiento:  %.2f", mantenimiento);
        printf("\nLimpieza:  %.2f", v.costo_limpieza);
        printf("\n-------------------------------------");
        printf("\nCOSTO TOTAL:  %.2f", costo_total);
        printf("\nCOSTO POR KM:  %.2f", costo_por_Km);
        printf("\n=====================================");
}
