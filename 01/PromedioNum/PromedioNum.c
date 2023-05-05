#include<stdio.h>

int main(){
    int num;
    int cantIngresos = 0;
    int cantPar = 0;
    float promedio = 0.0;
    while (num>=0){
        printf("Ingrese numero: \n");
        scanf("%d",&num);
        cantIngresos++;
        promedio = ((promedio*(cantIngresos-1))+num)/cantIngresos;
        if (num>=0){
            printf("Promedio actual: %.2f\n", promedio);
            if (num%2==0){
                cantPar++;
            }
        }
        
    }
    printf("------------------\n");
    printf("cantidad de pares: %d\n", cantPar);
    
    return 0;
}