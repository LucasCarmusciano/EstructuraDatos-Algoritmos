#include<stdio.h>
#include<stdlib.h>

void cargar(int[][50], int);
void mostrar(int[][50], int);
int sumaImparesDigPrincipal(int mat[][50], int n){
    if (n == 0){
        return 0;
    } else {
        // El primer termino se anula si es un elemento par
        return (mat[n-1][n-1]*(mat[n-1][n-1]%2)) + sumaImparesDigPrincipal(mat, n-1);
    } 

}
int main(){
    int mat[50][50], n;
    do
    {
        printf("ingresar la el valor n para una matriz nxn\n");
        scanf("%d", &n);
    } while (n<=0 && n>50);
    cargar(mat, n);
    mostrar(mat, n);
    printf("\nLa suma de los elementos impares de la diagonal principal es: %d\n", sumaImparesDigPrincipal(mat, n));
}

void cargar(int mat[][50], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("valor en mat[%d][%d]\n", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}
void mostrar(int mat[][50], int n){
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        
    } 
}