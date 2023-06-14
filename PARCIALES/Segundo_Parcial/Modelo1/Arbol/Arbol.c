#include <stdio.h>
#include <stdlib.h>

typedef struct arbol{
    int num;
    struct arbol *izq;
    struct arbol *der;
}nodo;

void crear(nodo** arbol){
    int num;
    printf("Seleccione un numero\n");
    scanf("%d", &num);
    while (num!=-1){
        insertar(&(*arbol), num);
        printf("Seleccione un numero\n");
        scanf("%d", &num);
    }
}
void insertar(nodo** arbol, int num){
    if((*arbol)==NULL){
        (*arbol) = (nodo*)malloc(sizeof(nodo));
        (*arbol)->num = num;
        (*arbol)->izq = NULL;
        (*arbol)->der = NULL;
    }else if((*arbol)->num>num){
        insertar(&(*arbol)->izq, num);
    }else{
        insertar(&(*arbol)->der, num);
    }
}
void mostrar(nodo* arbol){
    if (arbol!=NULL){
        mostrar(arbol->izq);
        printf(" %d ", arbol->num);
        mostrar(arbol->der);
    }
}
void getMayorDivisor(nodo* arbol, int raiz, int* mayor){
    if(arbol!=NULL){
        if(raiz%arbol->num==0 && arbol->num>*mayor){
            *mayor=arbol->num;
        }
        getMayorDivisor(arbol->izq, raiz, mayor);
        getMayorDivisor(arbol->der, raiz, mayor);
    }
}
int getHojasImpares(nodo* arbol){
    if(arbol!=NULL){
        if(arbol->der==NULL && arbol->izq==NULL){
            return 1;
        }else{
            return getHojasImpares(arbol->der)+getHojasImpares(arbol->izq);
        }
    }else{
        return 0;
    }
}
int main(){
    nodo* arbol = NULL;
    crear(&arbol);
    printf("\n------MOSTRAR------\n");
    mostrar(arbol);
    printf("\n------MAYOR DIVISOR DE RAIZ %d------\n", arbol->num);
    int mayor=0;
    getMayorDivisor(arbol->izq, arbol->num, &mayor);
    getMayorDivisor(arbol->der, arbol->num, &mayor);
    printf("%d", mayor);
    printf("\n------HOJAS IMPARES------\n");
    printf("%d", getHojasImpares(arbol));
}