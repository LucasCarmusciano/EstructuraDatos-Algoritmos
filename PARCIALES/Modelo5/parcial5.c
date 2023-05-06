#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num1;
    int num2;
    struct lista *sig;
}nodo;

typedef struct listaPromedio{
    float prom;
    struct listaPromedio *sig;
}nodoProm;


void crear(nodo *p);
void mostrar(nodo *p);
void mostrarPromedio(nodoProm *p);
void cargarPromedio(nodo *p, nodoProm *p2);
void insertar(nodo *p);
nodo* eliminar1(nodo *p);
void eliminar2(nodo *p);

int main(){
    nodo *cabeza;
    nodoProm *promedio;
    cabeza = (nodo *)malloc(sizeof(nodo));
    promedio = (nodoProm *)malloc(sizeof(nodoProm));
    crear(cabeza);
    printf("\n-------------print--------------\n");
    mostrar(cabeza);
    printf("\n-------------print--------------\n");
    cargarPromedio(cabeza, promedio);
    mostrarPromedio(promedio);
    printf("\n-------------print--------------\n");
    insertar(cabeza);
    mostrar(cabeza);
    printf("\n-------------print--------------\n");
    cabeza = eliminar1(cabeza);
    eliminar2(cabeza);
    mostrar(cabeza);
}

void crear(nodo *p){
    printf("Ingrese valores (0 para terminar):\n");
    scanf("%d", &p->num1);
    scanf("%d", &p->num2);
    if(p->num1 == 0 && p->num2 == 0){
        p->sig = NULL;
    }else{
        p->sig = (nodo*)malloc(sizeof(nodo));
        crear(p->sig);
    }
}

void mostrar(nodo *p){
    if(p->sig!=NULL){
        printf("%d, %d\n", p->num1, p->num2);
        mostrar(p->sig);
    }
}

void mostrarPromedio(nodoProm *p){
    if(p->sig!=NULL){
        printf("%.1f\n", p->prom);
        mostrarPromedio(p->sig);
    }
}

void cargarPromedio(nodo *p, nodoProm *p2){
    while(p->sig!=NULL){
        p2->prom = (float)(p->num1 + p->num2)/2;
        p2->sig = (nodoProm*)malloc(sizeof(nodoProm));
        p2 = p2->sig;
        p = p->sig;
    }
    p2->sig = NULL;
}

void insertar(nodo *p){
    nodo *nuevo;
    while(p->sig!=NULL){
        if(p->num1+p->num2 > 15){
            nuevo = (nodo*)malloc(sizeof(nodo));
            nuevo->num1 = p->num1/2;
            nuevo->num2 = p->num2/2;
            nuevo->sig = p->sig;
            p->sig = nuevo;
            p = p->sig;
        }
        p = p->sig;
    }
}

nodo* eliminar1(nodo *p){
    nodo *aux;
    while(p->num1%p->num2 == 0){
        aux = p->sig;
        free(p);
        p = aux;
    }
    return p;
}

void eliminar2(nodo *p){
    nodo *aux;
    while(p->sig!=NULL && p->sig->sig!=NULL){
        if(p->sig->num1%p->sig->num2 == 0){
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        }else{
            p = p->sig;
        }
    }
}