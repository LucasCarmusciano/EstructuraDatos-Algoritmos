#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num1;
    int num2;
    int num3;
    struct lista *sig;
}nodo;

typedef struct listaSuma{
    int suma;
    struct listaSuma *sig;
}nodoSuma;


void crear(nodo *p);
void mostrar(nodo *p);
void mostrarSuma(nodoSuma *p);
void cargarSuma(nodo *p, nodoSuma *s);
nodo* insertarMitades(nodo *p);
nodo* eliminar1(nodo *p);
void eliminar2(nodo *p);

int main(){
    nodo *cabeza, *suma;
    cabeza = (nodo *)malloc(sizeof(nodo));
    suma = (nodoSuma *)malloc(sizeof(nodoSuma));
    crear(cabeza);
    printf("\n-------------print--------------\n");
    mostrar(cabeza);
    cargarSuma(cabeza, suma);
    printf("\n-------------print--------------\n");
    mostrarSuma(suma);
    cabeza = insertarMitades(cabeza);
    printf("\n-------------print--------------\n");
    mostrar(cabeza);
    cabeza = eliminar1(cabeza);
    eliminar2(cabeza);
    printf("\n-------------print--------------\n");
    mostrar(cabeza);
}

void crear(nodo *p){
    printf("Ingrese valores (0 para terminar):\n");
    scanf("%d", &p->num1);
    if(p->num1 == 0){
        p->sig = NULL;
    }else{
        scanf("%d", &p->num2);
        scanf("%d", &p->num3);
        p->sig = (nodo*)malloc(sizeof(nodo));
        crear(p->sig);
    }
}

void mostrar(nodo *p){
    if(p->sig!=NULL){
        printf("%d, %d, %d\n", p->num1, p->num2, p->num3);
        mostrar(p->sig);
    }
}

void mostrarSuma(nodoSuma *p){
    if(p->sig!=NULL){
        printf("%d\n", p->suma);
        mostrarSuma(p->sig);
    }
}

void cargarSuma(nodo *p, nodoSuma *s){
    int suma;
    while(p->sig!=NULL){
        suma = p->num1 + p->num2 + p->num3;
        if(suma>10){
            s->suma = suma;
            s->sig = (nodoSuma*)malloc(sizeof(nodoSuma));
            s = s->sig;
        }
        p = p->sig;
    }
    s->sig = NULL;
}

nodo* insertarMitades(nodo *p){
    nodo *aux, *cabeza;
    cabeza = (nodo*)malloc(sizeof(nodo));
    cabeza->num1 = p->num1/2;
    cabeza->num2 = p->num2/2;
    cabeza->num3 = p->num3/2;
    cabeza->sig = p;
    while(p->sig!=NULL && p->sig->sig!=NULL){
        aux = (nodo*)malloc(sizeof(nodo));
        aux->num1 = p->sig->num1/2;
        aux->num2 = p->sig->num2/2;
        aux->num3 = p->sig->num3/2;
        aux->sig = p->sig;
        p->sig = aux;
        p = p->sig->sig;
    }
    return cabeza;
}

nodo* eliminar1(nodo *p){
    nodo *aux;
    while(p->num1*p->num2*p->num3<30){
        aux = p->sig;
        free(p);
        p = aux;
    }
    return p;
}

void eliminar2(nodo *p){
    nodo *aux;
    while(p->sig!=NULL && p->sig->sig!=NULL){
        if(p->sig->num1 * p->sig->num2 * p->sig->num3 <30){
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        }else{
            p = p->sig;
        }
    }
}