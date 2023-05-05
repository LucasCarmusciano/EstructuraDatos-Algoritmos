/*
Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto con un blanco y eliminando las palabras de 1 letra
*/
#include <stdio.h>
#include <string.h>

int main(){
    int conteo=1;
    char c, anterior;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        if (c!=' ')
        {
            if(conteo==1){
                printf("%c%c",anterior,c);
            }else{
                if(conteo>1){
                    printf("%c", c);
                }
            }
            anterior=c;
            conteo++;
            
        }else{
            printf(" ");
            conteo=0;
        }
        c = getchar();
    }
    return 0;
}