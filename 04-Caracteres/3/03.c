/*
Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabras tienen más de 2 letras y terminan con “s”
*/
#include <stdio.h>
#include <string.h>

int getCantPalabras();

int main(){
    int cantPalabras = 0;
    cantPalabras = getCantPalabras();
    printf("\nSon un total de %d palabras con mas de 2 letras y que terminan con 's'", cantPalabras);
}

int getCantPalabras(){
    int conteo=0, cantPalabras=0;
    char c, anterior;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        if (c==' '){
            if(conteo>2 && anterior=='s'){
                cantPalabras++;
            }
            conteo=0;
        }else{
            conteo++;
        }
        anterior=c;
        c = getchar();
    }
    if(conteo>2 && anterior=='s'){
    cantPalabras++;
    }
    return cantPalabras;
}