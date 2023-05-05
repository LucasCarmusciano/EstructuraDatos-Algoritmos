/*
Leer un texto carácter a carácter, terminado en PUNTO.
Mostrar el texto intercambiando la última letra con la anteúltima de las palabras de más de 2 letras
*/

#include <stdio.h>
#include <string.h>

void leerTexto();
void reemplaza(char[], int);

int main(){
    leerTexto();
    return 0;
}

void leerTexto(){
    char c, palabra[50];
    int cont=0;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        if(c==' '){
            if(cont>2){
                reemplaza(palabra, cont);
            }else{
                palabra[cont]='\0';
                printf("%s ",palabra);
            }
            cont=0;
        }else{
            palabra[cont]=c;
            cont++;
        }
        c = getchar();
    }
    if(cont>2){
        reemplaza(palabra, cont);
    }else{
        palabra[cont]='\0';
        printf("%s ",palabra);
    }
}
void reemplaza(char palabra[50], int tam){
    for (int i = 0; i < tam-2; i++){
        printf("%c", palabra[i]);
    }
    printf("%c%c",palabra[tam-1], palabra[tam-2]);
    printf(" ");
}