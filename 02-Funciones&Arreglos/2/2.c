/*
Leer números enteros hasta cargar un arreglo de 10 elementos donde los primeros 5 son positivos y los restantes negativos.
    a) Mostrar los primeros 4 elementos mayores del arreglo.
    b) Generar otro arreglo intercalando el número positivo con los números negativos. Mostrarlo
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Prototipos
void cargar(int[]);
void mostrarMayores(int, int[]);
void ArregloIntercalado(int, int[]);

int main(){
    int vec[15], dim=10;
    cargar(vec);
    mostrarMayores(dim, vec);
    ArregloIntercalado(dim, vec);
}

void cargar(int vec[]){
    int num;
    int cantPos=0, cantNeg=5;
    while((cantNeg+cantPos-5)<10){
        printf("Ingrese un numero\n");
        scanf("%d", &num);
        if (num>0 && cantPos<5)
        {
            vec[cantPos]=num;
            cantPos++;
        }
        if (num<0 && cantNeg<10)
        {
            vec[cantNeg]=num;
            cantNeg++;
        }
        
        
        printf("Faltan ingresar [%d] positivos y [%d] negativos\n", 5-cantPos, 10-cantNeg);
    }
}

void mostrarMayores(int dim, int vec[]){
    printf("------A-----");
    int aux[15], menor=INT_MAX, posMenor=0;
    // Copio en un auxiliar
    for (int i = 0; i < dim; i++){
        aux[i] = vec[i];
    }
    
    // Borro los 6 menores
    for (int j = 0; j < 6; j++){
        for (int i = 0; i < dim; i++)
        {
            if((aux[i]<menor)&&(aux[i]!=0)){
                menor = aux[i];
                posMenor = i;
            }
        }
        aux[posMenor] = 0;
        menor = INT_MAX;
    }
    // Imprimo los 4 restantes
    for (int i = 0; i < dim; i++)
    {
        if (aux[i]!=0)
        {
            printf("%d\n", vec[i]);
        }
    }
}

void ArregloIntercalado(int dim, int vec[]){
    printf("------B-----");
    int aux[15];
    for (int i = 0; i < dim/2; i++)
    {
        aux[2*i]=vec[i];
        aux[2*i+1]= vec[i+5];
    }
    for (int i = 0; i < dim; i++)
    {
        printf("%d\n", aux[i]);
    }
    
}