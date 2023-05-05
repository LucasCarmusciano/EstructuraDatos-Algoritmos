#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void crearOrdenada(nodo *registro, int);
void show(nodo *registro);
void eliminarConjunto(nodo *registro);


int main(){
    nodo *cabeza;
    int min,max;
    cabeza = (nodo *)malloc(sizeof(nodo));
    crearOrdenada(cabeza, 0);
    show(cabeza);
    eliminarConjunto(cabeza);
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

void eliminarConjunto(nodo *p){
    int min, max;
    nodo *aux1,*aux2;
    do{
        printf("Ingresar valor min (superior a 0 y menor que 1000):\n");
        scanf("%d", &min);
    } while (min<0 || min>1000);
    do{
        printf("Ingresar valor max (superior a min y menor que 1000):\n");
        scanf("%d", &max);
    } while (max>1000 || max<min);
    while (p->sig!=NULL){
        if(p->sig->num >= min){
            aux1 = p;
            p=p->sig;
            while (p->num <= max){
                aux2 = p->sig;
                free(p);
                p=aux2;
            }
            aux1->sig = aux2;
            return;
        }
    }
}
