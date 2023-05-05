/*
Diseñar un algoritmo recursivo que permita sumar los elementos de una matriz
*/
#include <stdio.h>
#include <stdlib.h>

void cargar(int[][100], int);
int sumaMatriz(int[][100], int, int);
int sumaVector(int[][100], int, int);
int main(){
    int n;
    do
    {
        printf("ingresar la el valor n para una matriz nxn\n");
        scanf("%d", &n);
    } while (n<=0 && n>100);
    int mat[n][n];
    cargar(mat, n);
    printf("La suma de los elementos es: %d", sumaMatriz(mat, n, n));
}
void cargar(int mat[100][100], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("valor en mat[%d][%d]\n", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
int sumaMatriz(int mat[][100], int n, int fila){
    if(fila==1){
        return sumaVector(mat, n, fila-1);
    }else{
        return sumaVector(mat, n, fila-1)+sumaMatriz(mat, n, fila-1);
    }
}
int sumaVector(int vec[][100], int tam, int fila){
    if(tam==1){
        return vec[fila][0];
    }else{
        return vec[fila][tam-1]+sumaVector(vec, tam-1, fila);
    }
}