/* 
Crear un archivo con:
‐ Código de artículo.
‐ Cantidad de artículos.
‐ Precio unitario.
 Generar un vector con el precio total por artículo.
 Mostrar el código de artículo con más cantidad.
*/
#include<stdio.h>
#include<stdlib.h>

int crearArchivo(FILE *);
void generar(int vec[], FILE *, int);
void mostrarVector(int vec[], int);
void mostrarMayorCantidad(FILE *);

int main(){
    int size;
    FILE *file;
    int vec[10];
    size = crearArchivo(file);
    generar(vec, file, size);
    mostrarVector(vec, size);
    mostrarMayorCantidad(file);
}

int crearArchivo(FILE *file){
    int i=0;
    if((file=fopen("archivo.txt","w"))==NULL){
        printf("NO SE PUEDE ABRIR");
    }else{
        int codigo, cantidad, precio;
        printf("\nCodigo de articulo: (0 para terminar): ");
        scanf("%d", &codigo);
        while (codigo!=0 && i<10){
            printf("\nCantidad: ");
            scanf("%d", &cantidad);
            printf("\nPrecio: ");
            scanf("%d", &precio);
            fprintf(file, "%d   %d  %d\n", codigo, cantidad, precio);
            printf("\nCodigo de articulo: (0 para terminar): ");
            scanf("%d", &codigo);
            i++;
        }
    }
    fclose(file);
    return i;
}

void generar(int vec[10], FILE *file, int size){
    if((file=fopen("archivo.txt","r"))==NULL){
        printf("NO SE PUEDE ABRIR");
    }else{
        int cantidad, precio;
        for (int i = 0; i < size; i++){
            if(!feof(file)){
                fscanf(file,"%*d    %d  %d\n", &cantidad, &precio);
                vec[i]=(cantidad*precio);
            }
        }
    }
    fclose(file);
}

void mostrarVector(int vec[10], int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d\n",vec[i]);
    }
}

void mostrarMayorCantidad(FILE *file){
    if((file=fopen("archivo.txt","r"))==NULL){
        printf("NO SE PUEDE ABRIR");
    }else{
        int mayor=0, auxMayor, codigo, auxCodigo;
        while(!feof(file)){
            fscanf(file, "%d   %d\n", &auxCodigo, &auxMayor);
            if(auxMayor>mayor){
                mayor = auxMayor;
                codigo = auxCodigo;
            }
        }
        printf("El cosigo de mayor cantidad es <%d> con un total de <%d>", codigo, mayor);
    }
    fclose(file);
}
