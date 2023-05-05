/*
Cargar un vector con n elementos enteros y calcular el promedio de sus elementosen forma recursiva
*/
#include <stdio.h>
#include <stdlib.h>

int cargar(int[]);
float getPromedio(int[], int);
int main(){
    int vec[100], tam;
    tam = cargar(vec);
    printf("El producto de los elementos es: %.2f", getPromedio(vec, tam));
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
float getPromedio(int vec[], int tam){
    if(tam==1){
        return vec[0];
    }else{
        return (vec[tam-1]+(getPromedio(vec, tam-1)*(tam-1)))/tam;
    }
}