/*
Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabras tienen más de 3 letras.
*/
#include <stdio.h>
#include <string.h>

int getCantPalabras();

int main(){
    int cantPalabras = 0;
    cantPalabras = getCantPalabras();
    printf("\nSon un total de %d palabras con mas de 3 letras", cantPalabras);
}

int getCantPalabras(){
    int conteo=0, cantPalabras=0;
    char c;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        if (c==' '){
            conteo=0;
        }else{
            conteo++;
        }
        if(conteo==3){
            cantPalabras++;
        }
        c = getchar();
    }
    return cantPalabras;
}