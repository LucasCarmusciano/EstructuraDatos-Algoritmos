#include<stdio.h>
#include<stdlib.h>

void cargar(float x[15]){
    for(int i=0; i<15; i++){
        printf("\n [%d] -->  ", i);
        scanf("%f", &x[i]);
    }
}
void mostrar(float[]){
    for(int i=0; i<15; i++){
        printf("[%d]-");
    }
}
int main(){
    float *punt;
    float x[15];
    cargar(x);
    mostrar(x);
    punt = x;
    printf("\n--------------------------------------\n");
    for (int i = 0; i < 15; i++)
    {
        printf("Direccion -> %d   |    Memoria -> %.2f\n", punt+i, *(punt+i));
    }
    
    return 0;
}