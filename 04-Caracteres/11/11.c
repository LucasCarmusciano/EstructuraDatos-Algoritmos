/*
Ingrese un texto carácter a carácter terminado en PUNTO.
Contar cuantas palabras tienen más de una vez repetida la primera vocal que aparece en el texto
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
    char c, primerVocal=' ';
    int cont=0, repite=0;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        while(c==' ' && c!='.')
            c = getchar();
        while(c!=' ' && c!='.'){
            if(primerVocal==' ' && (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'))
                primerVocal=c;
            if(c==primerVocal)
                repite++;
            c = getchar();
        }
        if(repite>1)
            cont++;
        repite=0;
    }
    return cont;
}