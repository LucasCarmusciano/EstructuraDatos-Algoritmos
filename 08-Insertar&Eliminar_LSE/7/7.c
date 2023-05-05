#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void crearOrdenada(nodo *registro, int);
void show(nodo *registro);
nodo* intercalar(nodo *registro, nodo *anterior);


int main(){
    nodo *cabeza1, *cabeza2;
    cabeza1 = (nodo *)malloc(sizeof(nodo));
    cabeza2 = (nodo *)malloc(sizeof(nodo));
    crearOrdenada(cabeza1, 0);
    crearOrdenada(cabeza2, 0);
    cabeza1 = intercalar(cabeza1,cabeza2);
    show(cabeza1);
    return 0;
}

void crearOrdenada(nodo *registro, int anterior){
    do{
        scanf("%d", &registro->num);
    } while (registro->num < anterior || registro->num > 1000);
    if(registro->num == 1000){
        registro->sig=NULL;
    }else{
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crearOrdenada(registro->sig, registro->num);
    }
}

void show(nodo *registro){
    printf("\n----------print-----------\n");
    while (registro->sig!=NULL){
        printf("%d -----  ",registro);
        printf("%d\n",registro->num);
        registro = registro->sig;
    }
    printf("--------------------------\n");
}

nodo* intercalar(nodo *p1, nodo *p2){
    nodo *aux1, *aux2, *cabeza;
    if(p1->num > p2->num){
        cabeza = p2;
        while(p2->sig->num < p1->num && p2->sig!=NULL){
            p2 = p2->sig;
        }
        aux1 = p2->sig;
        p2->sig = p1;
        p2 = aux1;
    }else{
        cabeza = p1;
    }
    while (p1->sig!=NULL && p2->sig!=NULL){
       if(p1->sig->num >= p2->num && p1->num < p2->num){
            aux1 = p1->sig;
            aux2 = p2->sig;
            p1->sig = p2;
            p2->sig = aux1;
            p2 = aux2;
        }else{
            p1 = p1->sig;
        } 
    }
    if(p1->sig==NULL){
            p1->sig = p2;
    }
    return cabeza;
}
