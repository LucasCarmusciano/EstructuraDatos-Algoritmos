#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num1;
    int num2;
    int num3;
    struct lista *sig;
}nodo;

typedef struct lista2{
    float prom;
    struct lista2 *sig;
}nodo2;


void cargar(nodo *p);
void mostrar(nodo *p);
void mostrar2(nodo2 *p);
float getPromedio(nodo *p){
    return (p->num1+p->num2+p->num3)/3;
}
nodo* insertarOpuesto(nodo *p, nodo *anterior);
nodo* eliminarPromImpar(nodo *p, nodo2 *p2);
nodo* eliminar1(nodo *p, nodo2 *p2);
void eliminar2(nodo *p, nodo2 *p2);


int main(){
    nodo *cabeza1, *cabeza2;
    cabeza1 = (nodo *)malloc(sizeof(nodo));
    cabeza2 = (nodo2 *)malloc(sizeof(nodo2));
    cargar(cabeza1);
    printf("\n---------print---------\n");
    mostrar(cabeza1);
    cabeza1 = insertarOpuesto(cabeza1, NULL);
    printf("\n---------print---------\n");
    mostrar(cabeza1);
    cabeza1 = eliminarPromImpar(cabeza1, cabeza2);
    printf("\n---------print---------\n");
    mostrar(cabeza1);
    printf("\n---------print---------\n");
    mostrar2(cabeza2);
    return 0;
}

void cargar(nodo *p){
    printf("Cargar valores de nodo\n");
    scanf("%d",&p->num1);
    if(p->num1 == 0){
        p->sig=NULL;
    }else{
        scanf("%d",&p->num2);
        scanf("%d",&p->num3);
        p->sig = (nodo *)malloc(sizeof(nodo));
        cargar(p->sig);
    }
}

void mostrar(nodo *p){
    if(p->sig!=NULL){
        printf("[%d]  [%d]  [%d]\n", p->num1, p->num2, p->num3);
        mostrar(p->sig);
    }
}
void mostrar2(nodo2 *p){
    if(p->sig!=NULL){
        printf("[%.2f]\n",p->prom);
        mostrar2(p->sig);
    }
}

nodo* insertarOpuesto(nodo *p, nodo *anterior){
    nodo *aux;
    if(p->sig!=NULL){
        p->sig = insertarOpuesto(p->sig, p);
    }
    if(getPromedio(p)>=20){
        aux = (nodo*)malloc(sizeof(nodo));
        aux->num1 = p->num1*(-1);
        aux->num2 = p->num2*(-1);
        aux->num3 = p->num3*(-1);
        aux->sig = p;
        return aux;
    }else{
        return p;
    }
}

nodo* eliminarPromImpar(nodo *p, nodo2 *p2){
    if((int)getPromedio(p)%2!=0){
        p2->prom = getPromedio(p);
        p2->sig = (nodo2*)malloc(sizeof(nodo2));
        p2 = p2->sig;
    }
    eliminar2(p,p2);
    return eliminar1(p,p2);
}

void eliminar2(nodo *p, nodo2 *p2){
    nodo *aux;
    while(p->sig!=NULL){
        if((int)getPromedio(p->sig)%2!=0){
            aux = p->sig->sig;
            p2->prom = getPromedio(p->sig);
            p2->sig = (nodo2*)malloc(sizeof(nodo2));
            free(p->sig);
            p->sig = aux;
            p2 = p2->sig;
        }else{
            p = p->sig;
        }
    }
}

nodo* eliminar1(nodo *p, nodo2 *p2){
    nodo *aux;
    if((int)getPromedio(p)%2!=0){
        aux = p->sig;
        free(p);
        return aux;
    }else{
        return p;
    }
}
