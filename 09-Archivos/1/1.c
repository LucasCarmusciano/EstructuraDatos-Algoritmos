// Generar un vector de 30 números enteros y crear un archivo con los números pares.Mostrarlo y mostrar el registro número 3
#include<stdio.h>
#include<stdlib.h>

void generar(int vec[]);
void crearArchivo(int [], FILE *);
void mostrarArchivo(FILE *);
void mostrarRegistro(FILE *, int);

int main(){
    int vec[30];
    FILE *file;
    generar(vec);
    crearArchivo(vec, file);
    mostrarArchivo(file);
    mostrarRegistro(file, 3);
}

void generar(int vec[30]){
    for (int i = 0; i < 30; i++)
    {
        printf("Ingrese número: ");
        scanf("%d\n",vec[i]);
    }
}

void crearArchivo(int vec[30], FILE *file){
    if((file=fopen("archivo.txt","w"))==NULL){
        printf("NO SE PUEDE ABRIR");
    }else{
       for (int i = 0; i < 30; i++){
            if(vec[i]%2 == 0){
                fprintf(file,"%d\n",vec[i]);
            }
        }
    }
    fclose(file);
}

void mostrarArchivo(FILE *file){
    if((file=fopen("archivo.txt","r"))==NULL){
        printf("NO SE PUEDE ABRIR");
    }else{
        int aux;
        while(!feof(file)){
            fscanf(file, "%d\n", &aux);
            printf("%d\n",aux);
        }
    }
    fclose(file);
}

void mostrarRegistro(FILE *file, int registro){
    if((file=fopen("archivo.txt","r"))==NULL){
        printf("NO SE PUEDE ABRIR");
    }else{
        int aux;
        for(int i=0; i<registro;i++){
            fscanf(file, "%d\n", &aux);
        }
        printf("El registro numero %d es: %d\n",registro,aux);
    }
    fclose(file);
}
