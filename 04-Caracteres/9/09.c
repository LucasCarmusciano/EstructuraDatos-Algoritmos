/*
Leer un texto carácter a carácter terminado en PUNTO. Contar cuantas palabras comienzan con las mismas 2 letras de la palabra anterior
*/
#include <stdio.h>
#include <string.h>

int leerTexto();

int main(){
    int cant=0;
    cant = leerTexto();
    printf("Cantidad de palabras que cumplen: %d\n", cant);
    return 0;
}

int leerTexto(){
    char c, primeraAnterior, segundaAnterior, primeraActual, segundaActual, palabra[50];
    int cont=0;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        while(c==' ' && c!='.')
            c = getchar();
        primeraActual = c;
        c = getchar();
        if(c!=' ' && c!='.'){
            segundaActual = c;
            if(primeraActual==primeraAnterior && segundaActual==segundaAnterior)
                cont++;
        }
        primeraAnterior = primeraActual;
        segundaAnterior = segundaActual;
        while(c!=' ' && c!='.')
            c = getchar();
    }
    return cont;
}