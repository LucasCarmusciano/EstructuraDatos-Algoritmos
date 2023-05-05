#include<stdio.h>

int main(){

    int anioActual = 2023;
    int cantAnios = 9;

    int ventas[cantAnios];
    int total =0, anioMayor, mayor = 0;

    for (int i = (anioActual-cantAnios); i < anioActual; i++)
    {
        printf("Cantidad de autos vendidos en el año %d \n", i);
        scanf("%d", &ventas[i-anioActual+cantAnios]);

        if (ventas[i-anioActual+cantAnios] > mayor)
        {
            mayor = ventas[i-anioActual+cantAnios];
            anioMayor = i;
        }
        total += ventas[i-anioActual+cantAnios];
    }
    
    printf("El año con mas ventas fue en %d \n", anioMayor);
    printf("el total es: %d \n", total);
}