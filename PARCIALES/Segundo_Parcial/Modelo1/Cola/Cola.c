#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4
typedef struct cola{
    int num;
    struct cola* siguiente;
}nodo;

nodo* crearNodo(int num){
    nodo *n;
    n= (nodo*)malloc(sizeof(nodo));
    n->num = num;
    n->siguiente = NULL;
    return n;
}
void acolar(nodo** p, nodo** u, nodo* n){
    if(*p==NULL){
        *p = *u = n;
    }else{
        (*u)->siguiente = n;
        (*u) = (*u)->siguiente;
    }
}
nodo desacolar(nodo** p){
    nodo *aux, eliminado;
    aux = *p;
    eliminado = **p;
    *p=(*p)->siguiente;
    free(aux);
    return eliminado;
}
void mostrar(nodo p, int *sumatoria, int *cont){
    printf("%d ", p.num);
    if(CANT>=3 && *cont>0){
        *sumatoria+=p.num;
        *cont=*cont-1;
    }
}

int main(){
    nodo *p=NULL, *u=NULL;
    int num, sumatoria=0, cont=3;
    for (int i = 0; i < CANT; i++){
        printf("Ingrese un numero: \n");
        scanf("%d", &num);
        acolar(&p, &u, crearNodo(num));
    }
    while (p!=NULL){
        mostrar(desacolar(&p), &sumatoria, &cont);
    }
    if(CANT>=3){
        printf("\nEl promedio de los primeros 3 valores es: %.2f", (float)sumatoria/3);
    }else{
        printf("No hay suficientes numeros para calcular el promedio");
    }
}