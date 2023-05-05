/*
Cargar una matriz de n*n de números enteros y mostrar:
    a) la matriz transpuesta
    b) El promedio de los elementos de las dos diagonales (principal y secundaria)
    c) Multiplicar la matriz por su transpuesta.
    d) Determinar cuántos números primos hay en la matriz.
*/
#include<stdio.h>
#include<stdlib.h>

void cargar(int[][10], int);
void mostrar(int[][10], int);
void cargarTranspuesta(int[][10], int, int[][10]);
void promedioDiagonales(int [][10], int);
void matrizXTranspuesta(int[][10], int, int[][10]);
void cantPrimos(int[][10], int);
int main(){
    int n;
    int mat[10][10], trp[10][10];
    do
    {
        printf("ingresar la el valor n para una matriz nxn\n");
        scanf("%d", &n);
    } while (n<=0 && n>10);
    cargar(mat, n);
    mostrar(mat, n);
    cargarTranspuesta(mat, n, trp);
    mostrar(trp, n);
    promedioDiagonales(mat, n);
    matrizXTranspuesta(mat, n, trp);
    cantPrimos(mat, n);
}

void cargar(int mat[][10], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("valor en mat[%d][%d]\n", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void mostrar(int mat[][10], int n){
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        
    } 
}
void cargarTranspuesta(int mat[][10], int n, int trp[][10]){
    printf("\n-------A-------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            trp[i][j] = mat[j][i];
        }
    }
}
void promedioDiagonales(int mat[][10], int n){
    printf("\n-------B-------\n");
    int suma=0;
    float promedio;
    for (int i = 0; i < n; i++)
    {
        suma+=mat[i][i];
        suma+=mat[i][n-1-i];
    } 
    promedio = (float)suma/(2*n);
    printf("El promedio de las diagonales es -> %.2f\n", promedio);
}
void matrizXTranspuesta(int mat[][10], int n, int trp[][10]){
    int rta=0;
    printf("\n-------C-------\n");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            for (int z = 0; z < n; z++){
                rta+= mat[i][z]*trp[z][j];
            }
            
            printf("%d\t", rta);
            rta=0;
        }
    }   
}
void cantPrimos(int mat[][10], int n){
    printf("\n-------D-------\n");
    int cant=0, primo=1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mat[i][j]>1){
                for (int z = 2; z < mat[i][j]-1; z++){
                    if(mat[i][j]%z==0 ){
                        primo = 0;
                    }
                }
                if(primo){
                    printf("%d primo\n",mat[i][j]);
                    cant++;
                }
                primo = 1;
            }
        }
    } 
    printf("Cantidad de primos -> %d\n", cant);
}