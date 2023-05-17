#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;

void crear(nodo *p);
void mostrar(nodo *p);
void insertarImpares(nodo *p, nodo *p2);
nodo* eliminarMenoresPromedio(nodo *p, nodo *p2);
nodo* eliminarMenorPromedio(nodo *p, float promedio);
float getPromedio(nodo *p);

int main(){
    nodo *cabeza, *impares;
    float promedio;
    cabeza = (nodo *)malloc(sizeof(nodo));
    impares = (nodo *)malloc(sizeof(nodo));
    crear(cabeza);
    printf("\n----------print-----------\n");
    mostrar(cabeza);
    printf("--------------------------\n");
    insertarImpares(cabeza, impares);
    printf("\n----------print-----------\n");
    mostrar(impares);
    printf("--------------------------\n");
    promedio = getPromedio(cabeza);
    impares = eliminarMenorPromedio(impares, promedio);
    printf("\n----------print-----------\n");
    mostrar(impares);
    printf("--------------------------\n");
    return 0;
}

void crear(nodo *p){
    scanf("%d", &p->num);
    if (p->num != -2){
        p->sig = (nodo*)malloc(sizeof(nodo));
        crear(p->sig);
    }else{
        p->sig = NULL;
    }
}

void mostrar(nodo *p){
    if(p->sig!=NULL){
        printf("%d\n", p->num);
        mostrar(p->sig);
    }
}

void insertarImpares(nodo *p, nodo *p2){
    while(p->sig!=NULL){
        if(p->num%2!=0){
            p2->num = p->num;
            p2->sig = (nodo*)malloc(sizeof(nodo));
            p2 = p2->sig;
        }
        p=p->sig;
    }
    p2->sig = NULL;
}

// nodo* eliminarMenoresPromedio(nodo *p, nodo *p2){
//     float promedio;
//     nodo *aux;
//     promedio = getPromedio(p);
//     while(p2->sig!=NULL && p2->sig->sig!=NULL){
//         if(p2->sig->num < promedio){
//             aux = p2->sig->sig;
//             free(p2);
//             p2->sig = p2->sig->sig;
//         }else{
//             p2 = p2->sig;
//         }
//     }
// }

nodo* eliminarMenorPromedio(nodo *p, float promedio){
    nodo *aux;
    aux = p;
    if(p->sig!=NULL && p->sig->sig!=NULL){
        p->sig = eliminarMenorPromedio(p->sig, promedio);
    }
    if(p->num < promedio){
        aux = p->sig;
        free(p);
    }
    return aux;
}


float getPromedio(nodo *p){
    int i=0, total=0;
    while(p->sig!=NULL){
        total+=p->num;
        i++;
        p = p->sig;
    }
    return (float)total/i;
}