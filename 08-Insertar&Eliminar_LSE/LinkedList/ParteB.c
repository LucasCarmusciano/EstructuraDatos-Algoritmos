#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void crearOrdenada(nodo *registro);
void show(nodo *registro);
nodo* eliminar1(nodo *registro);
void eliminar2(nodo *registro);
nodo* eliminarPrimero(nodo *registro);


int main(){
    nodo *cabeza;
    cabeza = (nodo *)malloc(sizeof(nodo));
    crearOrdenada(cabeza);
    show(cabeza);
    cabeza = eliminarPrimero(cabeza);
    show(cabeza);
    return 0;
}

void crearOrdenada(nodo *registro){
    scanf("%d", &registro->num);
    if(registro->num == 1000){
        registro->sig=NULL;
    }else{
        registro->sig = (nodo *)malloc(sizeof(nodo));
        crearOrdenada(registro->sig);
    }
}

void show(nodo *registro){
    printf("\n----------print-----------\n");
    while (registro->sig!=NULL){
        printf("%d -----  ",registro);
        printf("%d\n",registro->num);
        registro = registro->sig;
    }
    printf("--------------------------");
}

nodo* eliminar1(nodo *cabeza){
    nodo *aux;
    aux = cabeza->sig;
    free(cabeza);
    cabeza = aux;
    return cabeza;
}

void eliminar2(nodo *p){
    nodo *aux;
    while (p->sig!=NULL && p->sig->sig!=NULL){
        if(p->sig->num == p->sig->sig->num){
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        }else{
            p = p->sig;
        }
        
    }
}

nodo* eliminarPrimero(nodo *p){
    eliminar2(p->sig);
    if(p->num == p->sig->num){
        return eliminar1(p);
    }else{
        return p;
    }
}
