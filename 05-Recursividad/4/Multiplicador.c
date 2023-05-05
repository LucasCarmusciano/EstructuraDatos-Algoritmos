/*
Diseñar un algoritmo recursivo que permita multiplicar los elementos de un vector
*/
#include <stdio.h>
#include <stdlib.h>

int cargar(int[]);
int multiplica(int[], int);
int main(){
    int vec[100], tam;
    tam = cargar(vec);
    printf("El producto de los elementos es: %d", multiplica(vec, tam));
}
int cargar(int vec[]){
    int i=0;
    int num;
    printf("Ingrese un numero en la pos %d (0 para terminar)\n", i);
    scanf("%d", &num);
    while (num != 0)
    {   
        vec[i] = num;
        i++;
        printf("Ingrese un numero en la pos %d (0 para terminar)\n", i);
        scanf("%d", &num);
    }
    return i;
}
int multiplica(int vec[], int tam){
    if(tam==1){
        return vec[0];
    }else{
        return vec[tam-1]*multiplica(vec, tam-1);
    }
}