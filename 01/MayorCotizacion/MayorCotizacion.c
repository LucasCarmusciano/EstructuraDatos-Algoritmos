#include<stdio.h>

int main(){
    int dias, diaMayor, i;
    float cotizacion, cotMayor = 0.0;

    printf("Cantidad de dias:");
    scanf("%d", &dias);

    for (i = 1; i <= dias; i++)
    {
        printf("Ingrese cotizacion en el dia %d: ", i);
        scanf("%f", &cotizacion);
        if (cotizacion > cotMayor)
        {
            cotMayor = cotizacion;
            diaMayor = i;
        }
        
    }
    printf("El dia con mayor cotizacion fue el dia %d y su cotizacion fue de $%.2f \n", diaMayor, cotMayor);
}