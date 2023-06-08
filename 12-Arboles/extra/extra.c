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
int getMaxMultiplo (treenode *hoja, int dato){
    if(hoja!=NULL){
        int maxIzq, maxDer, max;
        maxIzq = getMaxMultiplo(hoja->izq,dato);
        maxDer = getMaxMultiplo(hoja->der,dato);
        if(maxIzq>maxDer)
            max = maxIzq;
        else
            max = maxDer;
        if((hoja->dato)%dato==0){
            if(hoja->dato > max)
                max = hoja->dato;
        }
        return max;
    }else
        return 0;
}
int getCantHojasMultiplos(treenode *hoja, int dato){
    int cont=0;
    if(hoja!=NULL){
        if((hoja->izq==NULL && hoja->der==NULL) && (hoja->dato)%dato==0)
            cont++;
        cont+=getCantHojasMultiplos(hoja->izq, dato);
        cont+=getCantHojasMultiplos(hoja->der, dato);
    }
    return cont;
}
int getSumatoria(treenode *hoja){
    int sum=0;
    if(hoja!=NULL){
        if((hoja->dato%2==0) && ((hoja->izq==NULL&&hoja->der!=NULL) || (hoja->izq!=NULL&&hoja->der==NULL))){
            sum=hoja->dato;
        }
        sum+=getSumatoria(hoja->izq);
        sum+=getSumatoria(hoja->der);
    }
    return sum;
}

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
    
    printf("\nEl maximo multiplo de %d es: %d", arbol->dato, getMaxMultiplo(arbol, arbol->dato));
    printf("\nLa cantidad de hojas multiplos de la raiz son: %d", getCantHojasMultiplos(arbol, arbol->dato));
    printf("\nLa sumatoria de nodos pares con un hijo es: %d", getSumatoria(arbol));
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