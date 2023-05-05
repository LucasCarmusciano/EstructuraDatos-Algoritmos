#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void crearOrdenada(nodo *registro);
void show(nodo *registro);
void eliminarSegundo(nodo *registro);


int main(){
    nodo *cabeza;
    cabeza = (nodo *)malloc(sizeof(nodo));
    crearOrdenada(cabeza);
    show(cabeza);
    eliminarSegundo(cabeza);
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

void eliminarSegundo(nodo *p){
    nodo *aux;
    while (p->sig!=NULL){
        if(p->num == p->sig->num){
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        }else{
            p = p->sig;
        } 
    }
}
