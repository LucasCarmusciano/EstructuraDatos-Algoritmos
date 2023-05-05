#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void crearOrdenada(nodo *registro);
void show(nodo *registro);
void agregarTerceroConsecutivo(nodo *registro);

int main(){
    nodo *cabeza;
    cabeza = (nodo *)malloc(sizeof(nodo));
    crearOrdenada(cabeza);
    show(cabeza);
    agregarTerceroConsecutivo(cabeza);
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

void agregarTerceroConsecutivo(nodo *registro){
    while (registro->sig != NULL){
        if (registro->num == registro->sig->num){
            nodo *aux;
            aux = (nodo*)malloc(sizeof(nodo));
            aux->num = registro->num;
            aux->sig = registro->sig;
            registro->sig = aux;
            registro = registro->sig;
        }
        registro = registro->sig;
    }
}


