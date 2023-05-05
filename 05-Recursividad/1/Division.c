/*
Diseñar un algoritmo recursivo que permita hacer la división por restas sucesivas
*/
#include <stdio.h>
#include <stdlib.h>

int divide(int, int);
int main(){
    int a, b;
    printf("Ingrese un numero y su divisor\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("El cociente es: %d\n", divide(a,b));
}
int divide(int a, int b){
    if(a<b){
        return 0;
    }else {
        return divide(a-b, b)+1;        
    }
}