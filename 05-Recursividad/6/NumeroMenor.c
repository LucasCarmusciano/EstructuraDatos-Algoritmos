/*
Diseñar un algoritmo recursivo que muestre el número menor de un vector.
*/
#include <stdio.h>
#include <stdlib.h>

int cargar(int[]);
int getMenor(int[], int, int);
int main(){
    int vec[100], tam;
    tam = cargar(vec);
    printf("El numero menor es: %d", getMenor(vec, tam, vec[0]));
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
int getMenor(int vec[], int tam, int menor){
    if(menor > vec[tam-1])
        menor = vec[tam];
    if(tam==1){
        return menor;
    }else{
        return getMenor(vec, tam-1, menor);
    }
}