#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int coeficiente;
    int potencia;
    struct lista *sig;
}nodo;

void crear(nodo *p);
void cargar(nodo *p, int potAnterior);
void mostrar(nodo *p);
void completarPolinomio(nodo *p);
void suma(nodo *p, nodo *p2, nodo *s);
void eliminar0(nodo *p);

int main(){
    nodo *cabeza, *cabeza2, *s;
    cabeza = (nodo *)malloc(sizeof(nodo));
    cabeza2 = (nodo *)malloc(sizeof(nodo));
    s = (nodo *)malloc(sizeof(nodo));
    crear(cabeza);
    crear(cabeza2);
    printf("\n----------polinomio 1-----------\n");
    mostrar(cabeza);
    printf("\n----------polinomio 2-----------\n");
    mostrar(cabeza2);
    completarPolinomio(cabeza);
    printf("\n----------polinomio 1-----------\n");
    mostrar(cabeza);
    completarPolinomio(cabeza2);
    printf("\n----------polinomio 2-----------\n");
    mostrar(cabeza2);
    suma(cabeza, cabeza2, s);
    printf("\n-------------SUMA---------------\n");
    mostrar(s);
    eliminar0(s);
    printf("\n-------------SUMA---------------\n");
    mostrar(s);
}

void crear(nodo *p){
    printf("\nCargar lista\n");
    do{
        scanf("%d", &p->coeficiente);
        scanf("%d", &p->potencia);
    } while (p->potencia < 0);
    p->sig = (nodo*)malloc(sizeof(nodo));
    cargar(p->sig, p->potencia);
}

void cargar(nodo *p, int potAnterior){
    do{
        printf("Ingresar coeficiente y potencia:\n");
        scanf("%d", &p->coeficiente);
        scanf("%d", &p->potencia);
    } while (p->potencia > potAnterior);
    if(p->potencia < 0){
        p->sig = NULL;
    }else{
        p->sig = (nodo*)malloc(sizeof(nodo));
        cargar(p->sig, p->potencia);
    }
}

void mostrar(nodo *p){
    if(p->sig!=NULL){
        printf("%d^%d -> ", p->coeficiente, p->potencia);
        mostrar(p->sig);
    }
}

void completarPolinomio(nodo *p){
    nodo *nuevo;
    while(p->potencia > 0){
        if(p->potencia != p->sig->potencia+1){
            nuevo = (nodo*)malloc(sizeof(nodo));
            nuevo->coeficiente = 0;
            nuevo->potencia = p->potencia-1;
            nuevo->sig = p->sig;
            p->sig = nuevo;
        }
        p = p->sig;
    }
}

void suma(nodo *p, nodo *p2, nodo *s){
    nodo *mayor, *menor;
    if(p->potencia > p2->potencia){
        mayor = p;
        menor = p2;
    }else {
        mayor = p2;
        menor = p;
    }
    while(mayor->potencia != menor->potencia){
        s->potencia = mayor->potencia;
        s->coeficiente = mayor->coeficiente;
        mayor = mayor->sig;
        s->sig = (nodo*)malloc(sizeof(nodo));
        s = s->sig;
    }
    while(mayor->sig!=NULL){
        s->potencia = mayor->potencia;
        s->coeficiente = mayor->coeficiente + menor->coeficiente;
        mayor = mayor->sig;
        menor = menor->sig;
        s->sig = (nodo*)malloc(sizeof(nodo));
        s = s->sig;
    }
    s->sig = NULL;
}

void eliminar0(nodo *p){
    nodo *aux;
    while(p->sig!=NULL && p->sig->sig!=NULL){
        if(p->sig->coeficiente == 0){
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        }else{
            p = p->sig;
        }
    }
}