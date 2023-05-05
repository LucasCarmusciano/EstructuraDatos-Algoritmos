#include<stdio.h>

int main(){
    int num, cantTotal=0, cantAbundante=0, cantDeficiente=0, sumaDivisores=0;
    do{
        printf("Ingresar numero: \n");
        scanf("%d",&num);
        if(num){
            cantTotal++;
            for (int i = 1; i < num; i++){
                if (!(num%i)){
                    sumaDivisores+=i;
                }
            }
            if(sumaDivisores!=num){
                sumaDivisores>num?cantAbundante++:cantDeficiente++;
            }
            sumaDivisores=0;
        }
    } while (num);
    printf("El porcentaje de numeros abundantes ingresados es: %d\n", (100*cantAbundante)/cantTotal);
    printf("El porcentaje de numeros deficientes ingresados es: %d\n", (100*cantDeficiente)/cantTotal);
    return 0;
}