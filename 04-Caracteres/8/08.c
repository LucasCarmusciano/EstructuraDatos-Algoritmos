/*
Ingresar un texto carácter a carácter terminado en PUNTO.
Contar cuantas palabras empiezan con la anteúltima letra de la palabra anterior.
En palabras de 1 sola letra deberá tomar esta única letra como anteúltima.
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
    char c, anteultima, palabra[50];
    int cont=0, cantidadPalabras=0;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        if(c==' '){
            if(cont==1){
                anteultima=palabra[cont-1];
            }else{
                if(cont>1){
                    anteultima=palabra[cont-2];
                }
            }
            cont=0;
        }else{
            if(cont==0 && c==anteultima){
                cantidadPalabras++;
            }
            palabra[cont]=c;
            cont++;
        }
        c = getchar();
    }
    return cantidadPalabras;
}