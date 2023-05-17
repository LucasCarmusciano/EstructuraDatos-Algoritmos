#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void crear(nodo *p);
void mostrar(nodo *p);
void generarLista2(nodo *p, nodo *p2);
void sumaConsecutivos(nodo *p);

int main(){
    nodo *cabeza, *cabeza2;
    cabeza = (nodo *)malloc(sizeof(nodo));
    cabeza2 = (nodo *)malloc(sizeof(nodo));
    crear(cabeza);
    printf("\n----------print-----------\n");
    mostrar(cabeza);
    printf("--------------------------\n");
    generarLista2(cabeza, cabeza2);
    printf("\n----------print-----------\n");
    mostrar(cabeza2);
    printf("--------------------------\n");
    sumaConsecutivos(cabeza);
    printf("\n----------print-----------\n");
    mostrar(cabeza);
    printf("--------------------------\n");
}

void crear(nodo *p){
    scanf("%d", &p->num);
    if (p->num != 1000){
        p->sig = (nodo*)malloc(sizeof(nodo));
        crear(p->sig);
    }else{
        p->sig = NULL;
    }
}

void mostrar(nodo *p){
    if(p->sig!=NULL){
        printf("%d\n", p->num);
        mostrar(p->sig);
    }
}

void generarLista2(nodo *p, nodo *p2){
    while(p->sig != NULL){
        if(p->num%3 == 0){
            p2->num = p->num;
            p2->sig = (nodo*)malloc(sizeof(nodo));
            p2 = p2->sig;
        }
        p = p->sig;
    }
    p2->sig = NULL;
}

void sumaConsecutivos(nodo *p){
    int suma;
    nodo *aux;
    while(p->sig!=NULL && p->sig->sig!=NULL){
        suma = p->num + p->sig->num;
        if(suma > 20){
            aux = (nodo*)malloc(sizeof(nodo));
            aux->num = 0;
            aux->sig = p->sig;
            p->sig = aux;
            p = p->sig->sig;
        }else if(suma < 10){
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        }else{
            p = p->sig;
        }
    }
}