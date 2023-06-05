#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10



typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *producto, int *cont){
     	printf("%d \n", aux.dato);
        if(*cont < 5){
            *producto*=aux.dato;
        }
}

nodo* crear_nodo(int dato ){
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;
   u->siguiente = NULL;
   return u;
}

void apilar(nodo** p, nodo* u){
  	u->siguiente = *p;
	*p = u;
}

nodo desapilar(nodo** p){
	nodo* aux;
    nodo datos;
	datos=**p;
	aux=*p;
	*p=(*p)->siguiente;
	free(aux);
    return datos;
}

int main(){
    int i,num,producto=1,cont=CANT-1;
    nodo* p=NULL;
    for(i=0; i<CANT; i++){
    	printf("Ingrese un numero \n");
    	scanf("%d",&num);
    	apilar(&p, crear_nodo(num));
    }
    if (CANT > 5){
        while(p!=NULL){
            mostrar(desapilar(&p), &producto, &cont);
            cont--;
        }
        printf("El producto de los primeros 5 numeros ingresados es: %d", producto);
    }else{
        printf("Deberia tener 5 numeros minimamente para poder mostrar el producto");
    }
   return 0;
}
