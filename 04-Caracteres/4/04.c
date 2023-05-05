/*
Leer un texto carácter a carácter, terminado en PUNTO y repetirlo reemplazandolos grupos ‘vl’ por ‘bl’.
*/
#include <stdio.h>
#include <string.h>

void reemplaza();
int main(){
    int conteo=1;
    char c;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        if(c!='v'){
            printf("%c",c);
        }else{
            reemplaza();
        }
        c = getchar();
    }
    return 0;
}

void reemplaza(){
    char c;
    c = getchar();
    if(c=='l'){
        printf("bl");
    }else{
        printf("v%c",c);
    }
}