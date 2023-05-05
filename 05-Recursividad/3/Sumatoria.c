/*
Diseñar un algoritmo recursivo que permita sumar los dígitos de un número. Por ejemplo, Entrada: 123 Resultado: 6
*/
#include <stdio.h>
#include <stdlib.h>

int sumaDigitos(int);
int main(){
    int num;
    printf("Ingrese un numero\n");
    scanf("%d", &num);
    printf("La sumatoria de sus digitos es: %d\n", sumaDigitos(num));
}
int sumaDigitos(int num){
    if(num<10){
        return num;
    }else{
        int ultimoDigito = num%10;
        int numSinUD = num/10;
        return ultimoDigito+sumaDigitos(numSinUD);
    }
}