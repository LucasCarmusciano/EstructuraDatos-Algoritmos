/*
Leer un texto carácter por carácter terminando en PUNTO. Contar grupos "TA". Mostrar reemplazando por “TE”
*/
#include <stdio.h>
#include <string.h>

int main(){
    char c, d;
    int cont=0;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while(c!='.'){
        putchar(c);
        if(c == 'T'){
            d = getchar();
            if(d == 'A'){
                cont++;
                putchar('E');
            }else{
                putchar(d);
            }
        }
        c = getchar();
    }
}