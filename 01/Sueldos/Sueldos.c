#include<stdio.h>

int main(){
    int edad;
    float sueldo;
    int cantidadSueldosMayor = 0;
    float totalSueldosMayor = 0.0;
    float promedioEdadSueldosMayor;
    int cantSueldoMenor=0;
    int cantSueldoEntre=0;
    int cantSueldoMayor=0;
    float porcentaje;
    do{
        printf("Ingresar edad:\n");
        scanf("%d", &edad);
        printf("Ingresar sueldo:\n");
        scanf("%f", &sueldo);

        if (sueldo>10000)
        {
            totalSueldosMayor+=sueldo;
            cantidadSueldosMayor++;
        }

        if (edad > 58)
        {
            sueldo = sueldo*1.05;
            printf("[sueldo mayor de 58: %.2f]\n", sueldo);
        }
        
        if (sueldo<15000){
            cantSueldoMenor++;
        }else if(sueldo>20000){
            cantSueldoMayor++;
        }else{
            cantSueldoEntre++;
        }
        
        printf("----------------\n");
    } while (edad!=0 && sueldo!=0);
    
    promedioEdadSueldosMayor = totalSueldosMayor/cantidadSueldosMayor;
    printf("El promedio de edad de los que ganan más de $10000: %.2f\n", promedioEdadSueldosMayor);
    porcentaje = ((cantSueldoMenor*100)/(cantSueldoEntre+cantSueldoMayor+cantSueldoMenor));
    printf("*El porcentaje de empleados cuyo sueldo es menor a 15000: %.f\n", porcentaje);
    porcentaje = ((cantSueldoEntre*100)/(cantSueldoEntre+cantSueldoMayor+cantSueldoMenor));
    printf("*El porcentaje de empleados cuyo sueldo está entre 15000 y 20000: %.f\n", porcentaje);
    porcentaje = ((cantSueldoMayor*100)/(cantSueldoEntre+cantSueldoMayor+cantSueldoMenor));
    printf("*El porcentaje de empleados cuyo sueldo es mayor a 20000: %.f\n", porcentaje);

    return 0;
}