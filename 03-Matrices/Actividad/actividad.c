#include<stdio.h>
#include<stdlib.h>

void cargar(int[][10], int);
void mostrarMatriz(int[][10], int);
void mostrarVector(float[], int);
int isSimetrica(int[][10], int);
void cargarPromedios(int[][10], float[], int);
int sumaTriangularSuperior(int[][10], int);

int main(){
    int mat[10][10], n;
    do{
        printf("ingresar la el valor natural N para una matriz NxN\n");
        scanf("%d", &n);
    } while (n<1 || n>10);
    cargar(mat, n);
    mostrarMatriz(mat, n);
    if (isSimetrica(mat,n)){
        float promFilas[10];
        cargarPromedios(mat, promFilas, n);
        mostrarVector(promFilas, n);
    }else{
        int suma;
        //Se pide calcular la suma de la triangular inferior de la traspuesta, la cual es equivalente a la triangular superior de la original:
        suma = sumaTriangularSuperior(mat, n);
        printf("Suma de la triangular inferior de la traspuesta: %d", suma);
    }
    
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
void mostrarMatriz(int mat[][10], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    } 
}
void mostrarVector(float vec[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("\n%.2f\t", vec[i]);
    } 
}
int isSimetrica(int mat[][10], int n){
    int cumple=1;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(mat[i][j]!=mat[j][i]){
                cumple = 0;
            }
        }
    }
    return cumple;
}
void cargarPromedios(int mat[][10], float vec[], int n){
    int suma;
    float promedio;
    for (int i = 0; i < n; i++){
        suma=0;
        for (int j = 0; j < n; j++){
            suma+=mat[i][j];
        }
        promedio = (float)suma/n;
        vec[i] = promedio;
    }
}
int sumaTriangularSuperior(int mat[][10], int n){
    int suma = 0;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            suma+=mat[i][j];
        }
    }
    return suma;
}

