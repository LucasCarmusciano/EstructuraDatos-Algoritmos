#include<stdio.h>
#include<stdlib.h>

void cargar(int x[3][4]){
    for(int i=0; i<3; i++){
        for (int j = 0; j < 4; j++){
            printf("\n [%d][%d] -->  ", i, j);
            scanf("%d", &x[i][j]);
        }
    }
}
void mostrar(int x[3][4]){
    for(int i=0; i<3; i++){
        for (int j = 0; j < 4; j++){
            printf("(%d)-", x[i][j]);
        }
        printf("\n");
    }
}
int main(){
    int *punt;
    int x[3][4];
    cargar(x);
    mostrar(x);
    punt = x;
    printf("\n--------------------------------------\n");
    for (int i = 0; i < 3*4; i++){
            printf("Direccion -> %d   |    Memoria -> %d\n", punt+i, *(punt+i));
    }
    
    return 0;
}