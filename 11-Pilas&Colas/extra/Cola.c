#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 5


typedef struct tiponodo{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *cant, int segundo){
   if (aux.dato==segundo){
      *cant= *cant+1;
   }
  	printf("%d \n", aux.dato);
}

nodo* crear_nodo(int dato){
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;
   u->siguiente = NULL;
   return u;
}

void acolar(nodo** p,nodo** u, nodo *q){
	if(*p==NULL)
      *p = *u = q;
   else{
    	(*u)->siguiente = q;
    	(*u) = q;
   }
}

nodo desacolar(nodo** inicio){
	nodo* aux;
   nodo datos;
	datos=**inicio;
	aux=*inicio;
	*inicio=(*inicio)->siguiente;
	free(aux);
   return datos;
}

int main(){
   int i,num,segundo,cant=0;
   nodo* p=NULL;
   nodo* u=NULL;
   for(i=0; i<CANT; i++){
      printf("Ingrese un numero\n");
      scanf("%d",&num);
      if (i==1)
         segundo=num;
      acolar(&p, &u, crear_nodo(num));
   }
	while(p!=NULL){
    	mostrar(desacolar(&p),&cant,segundo);
   }
   printf("\nLa cantidad de veces que se repite el segundo numero (%d) es: %d", segundo, cant);
   return 0;
}
