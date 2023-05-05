/*
Ingresar un texto carácter a carácter y determinar e informar cuantas palabras capicúas hay de 2 o 3 letras.
*/
#include <stdio.h>
#include <string.h>

int leerTexto();
int isCapicua(char[], int);

int main(){
    int cantidad=0;
    cantidad = leerTexto();
    printf("Cantidad de palabras capicuas: %d\n", cantidad);
    return 0;
}

int leerTexto(){
    char c, palabra[50];
    int cont=0, cantCapicuas=0;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.'){
        if(c==' '){
            if(cont==2 || cont==3){
                if(isCapicua(palabra, cont)){
                    cantCapicuas++;
                }
            }
            cont=0;
        }else{
            palabra[cont]=c;
            cont++;
        }
        c = getchar();
    }
    if(cont==2 || cont==3){
        if(isCapicua(palabra, cont)){
            cantCapicuas++;
        }
    }
    return cantCapicuas;
}

int isCapicua(char palabra[50], int tam){
    int isCapicua=1;
    for (int i = 0; i < tam/2; i++){
        if(palabra[i]!=palabra[tam-1-i]){
            isCapicua=0;
        }
    }
    return isCapicua;
}