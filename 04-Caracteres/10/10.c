/*
Leer un texto carácter por carácter terminando en PUNTO. Contar cuántas palabras con 2 letras seguidas iguales hay
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
    char c, anterior;
    int cont=0, cumple=0;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        while(c==' ' && c!='.')
            c = getchar();
        while(c!=' ' && c!='.'){
            anterior = c;
            c = getchar();
            if(anterior == c && !cumple){
                cont++;
                cumple = 1;
            }
        }
        cumple=0;
    }
    return cont;
}