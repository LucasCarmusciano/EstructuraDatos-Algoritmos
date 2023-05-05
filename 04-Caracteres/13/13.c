/*
Leer un texto carácter por carácter terminando en PUNTO y contar la cantidad de letras iguales a la primera distinta de blanco
*/
#include <stdio.h>
#include <string.h>

int main(){
    char c, first=' ';
    int cont=0;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while(c!='.'){
        if(c!=' ' && first==' ')
            first = c;
        if(c == first && c!=' ')
            cont++;
        c = getchar();
    }
    printf("La letra '%c' se repite un total de %d veces", first, cont);
}