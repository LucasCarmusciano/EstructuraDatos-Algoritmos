/*
Cargar una matriz de n*n de números enteros. Mostrar:
    a) la sumatoria de los elementos de la 2º fila.
    b) el mayor elemento de la segunda columna.
    c) el promedio de todos los múltiplos de 5 en la matriz.
    d) la sumatoria de la diagonal principal de la matriz.
    e) el elemento mínimo de cada fila.
    f) los elementos de la diagonal secundaria.
    g) los elementos que se encuentran debajo de la diagonal principal.
    h) si la matriz es simétrica.
*/
#include<stdio.h>
#include<stdlib.h>

void cargar(int[][10], int);
void mostrar(int[][10], int);
void sumatoriaFila(int[][10], int, int);
void promedioMultiplos(int[][10], int, int);
void sumatoriaDiagonal(int[][10], int);
void minimoFila(int[][10], int);
void elementosDiagonalSecundaria(int[][10], int);
void elementosDebajoDiagonal(int [][10], int);
void Simetria(int [][10], int);

int main(){
    int n;
    do
    {
        printf("ingresar la el valor n para una matriz nxn\n");
        scanf("%d", &n);
    } while (n<=0 && n>10);
    int mat[n][n];
    cargar(mat, n);
    mostrar(mat, n);
    sumatoriaFila(mat, n, 1);
    promedioMultiplos(mat, n, 5);
    sumatoriaDiagonal(mat, n);
    minimoFila(mat, n);
    elementosDiagonalSecundaria(mat, n);
    elementosDebajoDiagonal(mat, n);
    Simetria(mat, n);
    return 0;
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
void sumatoriaFila(int mat[][10], int n, int fila){
    printf("\n-------A-------\n");
    int sum = 0;
    if(fila<n && fila>=0){
        for (int i = 0; i < n; i++)
        {
            sum+=mat[fila][i];
        }
        
    }    
    printf("Sumatoria de la segunda fila -> %d\n", sum);
}
void promedioMultiplos(int mat[][10], int n, int multiplo){
    printf("\n-------B-------\n");
    int suma = 0, cantidad = 0;
    float promedio;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j]%5==0)
            {
                suma+=mat[i][j];
                cantidad++;
            }
            
        }
        
    }
    promedio = (float)suma/cantidad;
    printf("El promedio de multiplo de 5 en la matriz es -> %.1f\n", promedio);
}
void sumatoriaDiagonal(int mat[][10], int n){
    printf("\n-------C-------\n");
    int suma=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j)
            {
                suma+=mat[i][j];
            }
        }
    } 
    printf("La suma de la diagonal es -> %d\n", suma);
}
void minimoFila(int mat[][10], int n){
    printf("\n-------D-------\n");
    int minimo;
    for (int i = 0; i < n; i++)
    {
        minimo = mat[i][0];
        for (int j = 1; j < n; j++)
        {
            if (mat[i][j]<minimo)
            {
                minimo = mat[i][j];
            }
        }
        printf("El minimo de la fila %d es -> %d\n", i, minimo);
    } 
}
void elementosDiagonalSecundaria(int mat[][10], int n){
    printf("\n-------E-------\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==(n-1-j))
            {
                printf("mat[%d][%d] -> %d\n", i, j, mat[i][j]);
            }
        }
    } 
}
void elementosDebajoDiagonal(int mat[][10], int n){
    printf("\n-------F-------\n");
    int suma=0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i-1)==j)
            {
                printf("mat[%d][%d] -> %d\n", i, j, mat[i][j]);
            }
        }
    } 
}
void Simetria(int mat[][10], int n){
    printf("\n-------G-------\n");
    int simetria=1;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(mat[i][j]!=mat[j][i]){
                simetria = 0;
            }
        }
    }
    if (simetria){
        printf("Es simetrica");
    }else{
        printf("NO es simetrica");
    }
}