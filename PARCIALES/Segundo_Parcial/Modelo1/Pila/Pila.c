#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4
typedef struct pila{
    int num;
    struct pila* siguiente;
}nodo;

nodo* crearNodo(int num){
    nodo *n;
    n= (nodo*)malloc(sizeof(nodo));
    n->num = num;
    n->siguiente = NULL;
    return n;
}
void apilar(nodo** p, nodo* n){
    n->siguiente = *p;
    *p=n;
}
nodo desapilar(nodo** p){
    nodo *aux, eliminado;
    aux = *p;
    eliminado = **p;
    *p=(*p)->siguiente;
    free(aux);
    return eliminado;
}
void mostrar(nodo p, int primero, int* sumatoria){
    printf("%d ", p.num);
    if(p.num > primero){
        *sumatoria+=p.num;
    }
}

int main(){
    nodo *p=NULL;
    int num, primero, sumatoria=0;
    for (int i = 0; i < CANT; i++){
        printf("Ingrese un numero: \n");
        scanf("%d", &num);
        if(i==0)
            primero = num;
        apilar(&p, crearNodo(num));
    }
    while (p!=NULL){
        mostrar(desapilar(&p),primero, &sumatoria);
    }
    if(sumatoria == 0){
        printf("No hay numeros mayores al primero ingresado (%d)", primero);
    }else{
        printf("La sumatoria de los numeros mayores a %d es: %d", primero, sumatoria);
    }
}