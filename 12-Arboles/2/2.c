#include <stdio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja);
int getCantNodos (treenode *hoja){
    int cont = 0;
    if(hoja!=NULL){
        cont++;
        cont+=getCantNodos(hoja->izq);
        cont+=getCantNodos(hoja->der);
    }
    return cont;
}

int main (){
    printf ("arboles\n");
    treenode* arbol=NULL;
    crear (&arbol);
    printf ("**************\n");
    printf ("mostrar arbol\n");
    printf ("**************\n");
    mostrar (arbol);
    printf("\nLa cantidad de nodos es: %d", getCantNodos(arbol));
    return 0;
}

void crear (treenode **hoja){
    int numero;
    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    while (numero!=-1){
        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem){
    int numero=elem;
    if (elem==-1)
        return;
    if (*hoja==NULL){
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{
        if (numero>(*hoja)->dato){
            insertar (&(*hoja)->der,elem);
        }else{
        insertar (&(*hoja)->izq,elem);
        }
    }
    return;
}


void mostrar (treenode *hoja){
    if (hoja!=NULL){
        mostrar(hoja->izq);
        printf("%d ",hoja->dato);
        mostrar(hoja->der);
    }
    return;
}