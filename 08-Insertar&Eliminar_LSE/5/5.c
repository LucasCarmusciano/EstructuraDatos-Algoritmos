#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void crearOrdenada(nodo *registro, int);
void show(nodo *registro);
nodo* invertir(nodo *registro, nodo *anterior);


int main(){
    nodo *cabeza;
    cabeza = (nodo *)malloc(sizeof(nodo));
    crearOrdenada(cabeza, 0);
    show(cabeza);
    cabeza = invertir(cabeza, NULL);
    show(cabeza);
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

nodo* invertir(nodo *p, nodo *anterior){
    nodo *aux;
    if(p->sig!=NULL){
        aux = p->sig;
        p->sig = anterior;
        return invertir(aux, p);
    }else{
        p->sig = anterior;
        return p;
    }
}
