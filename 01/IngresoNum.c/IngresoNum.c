
#include<stdio.h>

int main(){
    int num =0;
    int multiplos = 0, cantMultiplos = 0, menor = -1, cantNumIntervalo=0;
    float promedio;
    printf("ingrese numero: \n");
    scanf("%d",&num);
    do
    {
        if ((num>4)&&(num<25)){
            cantNumIntervalo++;
        }
        if(num<menor || menor==-1){
            menor = num;
        }
        if (num%6 == 0){
            multiplos +=num;
            cantMultiplos++;
        }   
        printf("ingrese numero: \n");
        scanf("%d",&num);
    } while (num>=0);
    promedio = multiplos/cantMultiplos;
    printf("Cantidad de números mayores a 4 y menores a 25: %d\n",cantNumIntervalo);
    printf("Promedio de multiplos de 6: %.2f\n",promedio);
    printf("Menor numero: %d\n",menor);

    
}