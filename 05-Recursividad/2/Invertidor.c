/*
Diseñar un algoritmo recursivo que permita invertir un número. Por ejemplo, Entrada: 123 Salida: 321
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int invierte(int);
int main(){
    int num;
    printf("Ingrese un numero\n");
    scanf("%d", &num);
    printf("Su numero invertido es: %d", invierte(num));
}
int invierte(int num){
    if(num<10){
        return num;
    }else{
        int ultimoDigito = num%10;
        int numSinUltimoDigito = num/10;
        int numInvertido = invierte(numSinUltimoDigito);
        return ultimoDigito*pow(10, (int)log10(numSinUltimoDigito)+1)+numInvertido;
    }
}