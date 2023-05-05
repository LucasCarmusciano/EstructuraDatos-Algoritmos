/* 
Se ingresan los datos de vuelos a distintas ciudades para obtener estadísticas. Paraello se pide:
    Día de vuelo
    nombre de la ciudad
    capacidad del avión
    cantidad depasajes vendidos
Estos datos se ingresan hasta que el día de vuelo sea cero.
Mostrar los datos ingresados.
Calcular y mostrar:
    a) La ciudad y el día con la mayor cantidad de pasajes vendidos.
    b) El porcentaje de pasajes vendidos de cada ciudad.
    c) Mostar las ciudades en forma ordenada de menor a mayor según lacantidad de pasajes vendidos
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

// Prototipos
void cargar(int *, int[], int[], int[], char[][20]);
void mostrar(int, int[], int[], int[], char[][20]);
void mayorPasajesVendidos(int, char[][20], int[], int[]);
void porcentajeCiudad(int, char[][20], int[]);
void mostrarCiudades(int, char[][20], int[]);

int main(){
    // Declaracion de variables
    int cantVuelos=0, vecDia[50], vecPasajes[50], vecCapacidad[50];
    char vecCiudad[50][20];

    cargar(&cantVuelos, vecDia, vecPasajes, vecCapacidad, vecCiudad);
    mostrar(cantVuelos, vecDia, vecPasajes, vecCapacidad, vecCiudad);
    mayorPasajesVendidos(cantVuelos, vecCiudad, vecDia, vecPasajes);
    porcentajeCiudad(cantVuelos, vecCiudad, vecPasajes);
    mostrarCiudades(cantVuelos, vecCiudad, vecPasajes);
}

void cargar(int *cantVuelos, int vecDia[], int vecPasajes[], int vecCapacidad[], char vecCiudad[][20]){
    int i=0;
    printf("Dia (0 para terminar): \n");
    scanf("%d",&vecDia[i]);
    while (vecDia[i]!=0 && i<50)
    {
        printf("Cantidad de pasajes: \n");
        scanf("%d",&vecPasajes[i]);
        printf("Capacidad de vuelo: \n");
        scanf("%d",&vecCapacidad[i]);
        printf("Ciudad de destino: \n");
        scanf("%s",vecCiudad[i]);
        i++;
        printf("-------------------\n");
        printf("Dia (0 para terminar): \n");
        scanf("%d",&vecDia[i]);    
    }
    // Se le asigna el valor en la direccion del puntero de cantVuelos
    *cantVuelos = i;
}

void mostrar(int cantVuelos, int vecDia[], int vecPasajes[], int vecCapacidad[], char vecCiudad[][20]){
    printf("%11s%11s%11s%11s\n", "Ciudad", "Dia", "Pasajes", "Capacidad");
    for (int i = 0; i < cantVuelos; i++)
    {
        printf("%11s%11d%11d%11d\n", vecCiudad[i], vecDia[i], vecPasajes[i], vecCapacidad[i]);
    }
}

void mayorPasajesVendidos(int cantVuelos, char vecCiudad[][20], int vecDia[], int vecPasajes[]){
    int posMayor = 0;
    for (int i = 1; i < cantVuelos; i++)
    {
        if (vecPasajes[posMayor]<vecPasajes[i]){
            posMayor = i;
        }
    }
    printf("\n---------A---------\n");
    printf("Mayor cantidad de pasajes vendidos en %s, el dia %d\n", vecCiudad[posMayor], vecDia[posMayor]);
}

void porcentajeCiudad(int cantVuelos, char vecCiudad[][20], int vecPasajes[]){
    printf("\n---------B---------\n");
    float porcentaje = 0.0;
    int j=0, contiene, tamAux=1, repetido=0;
    char auxCiudad[50][20];
    for (int i = 0; i < cantVuelos; i++){
        contiene=0;
        repetido=0;
      
        for (int aux = 0; aux < tamAux; aux++){
            // Aplico funcion para saber si son iguales las cadenas de caracteres
            if(strcmp(auxCiudad[aux], vecCiudad[i]) == 0)
                contiene=1;
        }
        if (!contiene){
            strcpy(auxCiudad[tamAux-1], vecCiudad[i]);
            tamAux++;
            for (int a = 0; a < cantVuelos; a++){
                if(strcmp(vecCiudad[i], vecCiudad[a]) == 0)
                    repetido++;
            }
            porcentaje = (float)(100*repetido)/cantVuelos;
            printf("%s   ->   %.2f\n", vecCiudad[i], porcentaje);
        }
    }
}

void mostrarCiudades(int cantVuelos, char vecCiudad[][20], int vecPasajes[]){
    printf("\n---------C---------\n");
    int i,j,auxP;
    char auxC[20];
    for (i = 0; i < cantVuelos-1; i++){
        for (j = i; j < cantVuelos; j++){
            if (vecPasajes[i]>vecPasajes[j])
            {
                auxP = vecPasajes[i];
                strcpy(auxC, vecCiudad[i]);
                vecPasajes[i] = vecPasajes[j];
                strcpy(vecCiudad[i], vecCiudad[j]);
                vecPasajes[j] = auxP;
                strcpy(vecCiudad[j], auxC);
            }
        }
    }
    for (i = 0; i < cantVuelos; i++)
    {
        printf("%s%11d\n",vecCiudad[i],vecPasajes[i]);
    }
}