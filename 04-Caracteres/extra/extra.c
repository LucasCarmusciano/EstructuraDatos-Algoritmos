/*
A partir de los contenidos del modulo, se pide desarrollar un programa en C que permita leer un texto carácter
a carácter terminado en punto, se pide utilizando solo las funciones putchar() y getchar():

    a) calcular la cantidad de palabras del texto (las palabras están separadas por uno o mas espacios en blanco y
     puede haber blancos antes de la primer palabra y después de la ultima ), que tengan al menos 2 vocales.
    b) calcular la cantidad de palabras con cantidad impar de letras que empiecen con la letra que finaliza la palabra anterior.
*/
#include <stdio.h>

int main(){
    char c, final=' ';
    int vocales=0, contA=0;
    int letras=0, contB=0, cumpleInicialFinal=0;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while(c!='.'){
        while(c!=' ' && c!='.'){
            // Parte A
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                vocales++;
            // Parte B
            if(cumpleInicialFinal == -1){
                if(c == final){
                    cumpleInicialFinal = 1;
                }else{
                    cumpleInicialFinal = 0;
                }
            }
            letras++;
            final = c;
            c = getchar();
        }
        // Parte A
        if(vocales >= 2)
            contA++;       
        vocales=0;
        // Parte B
        if(letras%2 && cumpleInicialFinal == 1)
            contB++;
        cumpleInicialFinal = -1;
        letras = 0;
        if(c!='.')
            c = getchar();
    }
    printf("Palabras con almenos 2 vocales son: %d\n", contA);
    printf("Palabras con cantidad de letras impar y que empiezan con la letra que finaliza su anterior son: %d\n", contB);
}