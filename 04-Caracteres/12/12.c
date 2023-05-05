/*
Ingrese un texto carácter a carácter terminado en PUNTO y repítalo agregando una‘u’ entre cada letra ‘q’ seguida de ‘i’ o ‘e’
*/
#include <stdio.h>
#include <string.h>

int main(){
    char c;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while(c!='.'){
        if(c == 'q'){
            c = getchar();
            if(c == 'i' || c == 'e'){
                putchar('q');
                putchar('u');
                putchar(c);
            }else{
                putchar('q');
                putchar(c);
            }
        }else{
            putchar(c);
        }
        c = getchar();
    }
}