/*
Leer un texto carácter a carácter terminado en PUNTO. Contar cuantas palabras empiezan y terminan con la misma letra.
*/
#include <stdio.h>
#include <string.h>

int leerTexto(char[][2], int[], int);
int conteo(char[][2], char, char, int[], int);
void printResultados(char[][2], int[], int);

int main(){
    char aux[150][2]; // Matriz donde se almacenan los conjuntos de letras inicial y final.
    int cant[150], tam=0;
    tam = leerTexto(aux, cant, tam);
    printResultados(aux, cant, tam);
    return 0;
}

int leerTexto(char aux[150][2], int cant[], int tam){
    char c, anterior=' ', inicial, final;
    printf("Ingrese un texto terminando en un punto:\n");
    c = getchar();
    while (c!='.')
    {
        if(c!=' ' && anterior==' '){
            inicial=c;
        }
        if(c==' ' && anterior!=' '){
            final=anterior;
            tam = conteo(aux, inicial, final, cant, tam);
        }
        anterior=c;
        c = getchar();
    }
    if(anterior!=' '){
        final=anterior;
        tam = conteo(aux, inicial, final, cant, tam);
    }
    return tam;
}
int conteo(char aux[150][2], char inicial, char final, int cant[], int tam){
    int added=0;
    for(int i=0; i<tam; i++){
        if (inicial==aux[i][0] && final==aux[i][1]){
            cant[i]++;
            added=1;
        }
    }
    if(!added){
        aux[tam][0]=inicial;
        aux[tam][1]=final;
        cant[tam]=1;
        tam++;
    }
    return tam;
}
void printResultados(char aux[150][2], int cant[], int tam){
    for (int i = 0; i < tam; i++){
        printf("inicial[%c] - final[%c] --> %d\n", aux[i][0], aux[i][1], cant[i]);
    }
    
}