#include<stdio.h>
#include<stdlib.h>

int cargar(int []);
void mostrar(int [], int);
float getPromedio(int [], int);
int eliminarEntrePromedioYDobleNum(int [], int);
int insertarCerosAnteriores(int [], int);
void ordenar(int [], int);

int main(){
    int vec[200], dim=0;
    dim = cargar(vec);
    if (dim){
        mostrar(vec, dim);
        dim = eliminarEntrePromedioYDobleNum(vec, dim);
        mostrar(vec, dim);
        dim = insertarCerosAnteriores(vec, dim);
        mostrar(vec, dim);
        ordenar(vec, dim);
        mostrar(vec, dim);
    }
    else{
        printf("No hay elementos\n");
    }
    return 0;
}

// Funcion de carga, la cual devuelve la dimension del vector
int cargar(int vec[]){
    int num, i=0;
    printf("Ingrese un numero entero (0 para terminar)\n");
    do
    {
        scanf("%d",&num);
        if (num%2==0 && num!=0){
            vec[i]=num;
            i++;
        }
    } while (num!=0 && i<100);
    return i;
}

void mostrar(int vec[], int dim){
    int i;
    for(i = 0; i < dim; i++){
        printf(" %d -", vec[i]);
    }
    printf("\n");
}

float getPromedio(int vec[], int dim){
    int suma=0;
    for (int i = 0; i < dim; i++){
        suma+=vec[i];
    }
    float promedio = (float)suma/dim;
    return promedio;
}

int eliminarEntrePromedioYDobleNum(int vec[], int dim){
    printf("\n--------A--------\n");
    float menor, mayor, num, promedio;
    promedio = getPromedio(vec, dim);
    printf("Ingresar un numero\n");
    scanf("%f",&num);
    num*=2;
    // Asigno menor y mayor
    if(num<promedio){
        menor= num;
        mayor=promedio;
    }else{
        menor=promedio;
        mayor=num;
    }
    printf("Se eliminarán numero entre %.2f y %.2f\n", menor, mayor);
    // Elimino del vector superponiendo su valor por el siguiente y reduciendo su dimension
    for (int i = 0; i < dim; i++){
        if(menor<vec[i] && vec[i]<mayor){
            for (int j = i; j < dim; j++){
                vec[j]=vec[j+1];
            }
            dim--;
            i--;
        }
    }
    return dim;
}

int insertarCerosAnteriores(int vec[], int dim){
    printf("\n--------B--------\n");
    float promedio = getPromedio(vec, dim);
    // Busco el maximo
    int maximo = vec[0];
    for(int i=1; i<dim; i++){
        if(vec[i]>maximo){
            maximo=vec[i];
        }
    }
    printf("Se insertará un 0 a cada numero entre %.2f y %d\n", promedio, maximo);
    for (int i = 0; i < dim; i++){
        if(promedio<vec[i] && vec[i]<maximo){
            for (int j = dim-1; j >= i; j--){
                vec[j+1]=vec[j];
            }
            vec[i]=0;
            dim++;
            i++;
        }
    }
        printf("dimension -> %d\n", dim);
    return dim;
}

void ordenar(int vec[], int dim){
    int aux;
    printf("\n--------C--------\n");
    for(int i=0; i<dim-1; i++){
        for(int j=i+1; j<dim; j++){
            if(vec[j]>vec[i]){
                aux = vec[i];
                vec[i]= vec[j];
                vec[j]= aux;
            }
        }
    }
}