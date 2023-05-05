#include <stdio.h>
#include <stdlib.h>
void mostrar(float arr[15]){
    float *p;
    p = arr;
    for (int i = 0; i < 15; i++){
        printf("Direccion -> %d   |    Contenido -> %.2f\n", p+i, *(p+i));
    }
}
void cargar(float *arr){
    printf("Asignar valores al arreglo:\n");
    for(int i=0; i<15; i++){
        printf("[%d] -> ",i);
        scanf("%f", (arr+i));
    }
}
int main(){
    float arr[15];
    cargar(&arr);
    mostrar(arr);
}