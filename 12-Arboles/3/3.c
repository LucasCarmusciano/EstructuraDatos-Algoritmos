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
void mostrarInOrden (treenode *hoja);
void mostrarPreOrden (treenode *hoja);
void mostrarPostOrden (treenode *hoja);


int main (){
    printf ("arboles\n");
    treenode* arbol=NULL;
    crear (&arbol);
    printf ("\n-------------\n");
    printf ("In Orden\n");
    mostrarInOrden (arbol);
    printf ("\n-------------\n");
    printf ("Pre Orden\n");
    mostrarPreOrden (arbol);
    printf ("\n-------------\n");
    printf ("Post Orden\n");
    mostrarPostOrden (arbol);
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


void mostrarInOrden (treenode *hoja){
    if (hoja!=NULL){
        mostrarInOrden(hoja->izq);
        printf("%d ",hoja->dato);
        mostrarInOrden(hoja->der);
    }
    return;
}
void mostrarPreOrden (treenode *hoja){
    if (hoja!=NULL){
        printf("%d ",hoja->dato);
        mostrarPreOrden(hoja->izq);
        mostrarPreOrden(hoja->der);
    }
    return;
}
void mostrarPostOrden (treenode *hoja){
    if (hoja!=NULL){
        mostrarPostOrden(hoja->izq);
        mostrarPostOrden(hoja->der);
        printf("%d ",hoja->dato);
    }
    return;
}