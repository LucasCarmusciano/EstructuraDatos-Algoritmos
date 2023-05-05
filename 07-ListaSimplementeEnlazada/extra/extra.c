#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int legajo;
    char nombre[15];
    char apellido[25];
    int sector;
    int antiguedad;
    float sueldo;
    struct nodo *sig;
}nodo;

void crear(nodo *n);
void mostrar(nodo *n);
float promedioSueldo(nodo *n, int *contador);
int sectorMayor(nodo *n);
void generar(nodo *a, nodo*n, int sector);

int main(){
    nodo *lista, *aux;
    int contador=0,*p;
    p=&contador;
    lista = (nodo*)malloc(sizeof(nodo));
    aux = (nodo*)malloc(sizeof(nodo));
    crear(lista);
    mostrar(lista);
    printf("\n\nEl sueldo promedio del sector 2 con apellido mayor a 4 letras es: %.2f", promedioSueldo(lista,p));
    generar(aux, lista, sectorMayor(lista));
    mostrar(aux);
}

void crear(nodo *n){
    printf("Legajo:\n");
    scanf("%d", &n->legajo);
    if(n->legajo == 0){
        n->sig = NULL;
    }else{
        printf("Nombre:\n");
        scanf("%s", &n->nombre);
        printf("Apellido:\n");
        scanf("%s", &n->apellido);
        do{
            printf("Sector(1,2,3):\n");
            scanf("%d", &n->sector);
        } while (n->sector!=1 && n->sector!=2 && n->sector!=3);
        printf("Antiguedad:\n");
        scanf("%d", &n->antiguedad);
        printf("Sueldo:\n");
        scanf("%f", &n->sueldo);
        n->sig=(nodo*)malloc(sizeof(nodo));
        crear(n->sig);
    }
    return;
}

void mostrar(nodo *n){
    if(n->sig != NULL){
        printf("\n------------empleado------------");
        printf("\nLegajo:  %d", n->legajo);
        printf("\nNombre:  %s", n->nombre);
        printf("\nApellido:  %s", n->apellido);
        printf("\nSector:  %d", n->sector);
        printf("\nAntiguedad:  %d", n->antiguedad);
        printf("\nSueldo:  %.2f", n->sueldo);
        mostrar(n->sig);
    }
    return;
}

float promedioSueldo(nodo *n, int *contador){
    if(n->sig == NULL){
        return 0;
    }else{
        if (n->sector == 2 && strlen(n->apellido) > 4){
            *contador += 1;
            return promedioSueldo(n->sig,contador)+(n->sueldo / *contador);
        }else{
            return promedioSueldo(n->sig, contador);
        }
    }
}

int sectorMayor(nodo *n){
    int a=0,b=0,c=0;
    while(n->sig!=NULL){
        switch (n->sector){
        case 1:
            a++;
            break;
        case 2:
            b++;
        case 3:
            c++;
            break;
        }
        n = n->sig;
    }
    if (a>=b && a>=c)
        return 1;
    if (b>=a && b>=c)
        return 2;
    if (c>=a && c>=b)
        return 3;
}

void generar (nodo *a, nodo *n, int sector){
    while(n->sig!=NULL){
        if(n->sector == sector && n->antiguedad>=3){
            a->legajo = n->legajo;
            strcpy(a->nombre, n->nombre);
            strcpy(a->apellido, n->apellido);
            a->sector = sector;
            a->antiguedad = n->antiguedad;
            a->sueldo = n->sueldo;
            a->sig = (nodo*)malloc(sizeof(nodo));
            a = a->sig;
        }
        n = n->sig;
    }
    a->sig = NULL;
}