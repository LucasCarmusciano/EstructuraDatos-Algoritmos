#include <stdio.h>

int main()
{
    float peso, altura, imc;

    printf("Indicar peso: ");
    scanf("%f",&peso);

    printf("Indicar altura: ");
    scanf("%f",&altura);
    
    imc = peso / (altura * altura);
    printf("Su imc es: %.2f \n", imc);

    return 0;
}