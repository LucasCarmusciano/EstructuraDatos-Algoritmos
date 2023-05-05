#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int dni;
    char nombre[15];
    char tipoCuenta;
    float saldo;
    struct node *next;
}node;

void create(node *registro);
void show(node *registro);

node* coincide(int dni, node *registro){
    while (registro != NULL){
        if(registro->dni == dni)
            return registro;
        registro = registro->next;
    }
    return registro;
}

void getDni(node *registro);
void getNombre(node *registro);
void getTipoCuenta(node *registro);
void getSaldo(node *registro);


int main(){
    node *list;
    list = (node *)malloc(sizeof(node));
    create(list);
    show(list);

    int dni;
    printf("Ingrese un numero de DNI\n");
    scanf("%d",&dni);
    printf("%d", coincide(dni, list));
    return 0;
}

void create(node *registro){
    int key;
    getDni(registro);
    getNombre(registro);
    getSaldo(registro);
    getTipoCuenta(registro);

    printf("Ingrese 0 para terminar:\n");
    scanf("%d", &key);
    if(key == 0){
        registro->next=NULL;
    }else{
        registro->next = (node *)malloc(sizeof(node));
        create(registro->next);
    }
}

void show(node *registro){
    printf("--------------------\n");
    if (registro!=NULL){
        printf("%d\n",registro->dni);
        printf("%d\n",registro);
        show(registro->next);
    }
}

void getDni(node *registro){
    printf("DNI:\n");
    scanf("%d", &registro->dni);
    if(registro->dni < 0 || registro->dni > 99999999){
        getDni(registro);
    }
}
void getNombre(node *registro){
    char c;
    int i=0;
    printf("Nombre:\n");
    c = getchar();
    while(i<15 && c!='.'){
        registro->nombre[0] = c;
        c = getchar();
    }
}
void getTipoCuenta(node *registro){
    do
    {
        printf("Tipo de Cuenta(C,E,A):\n");
        scanf("%c", &registro->tipoCuenta);
    } while (registro->tipoCuenta != 'C' && registro->tipoCuenta != 'E' && registro->tipoCuenta != 'A');
}
void getSaldo(node *registro){
    printf("Saldo:\n");
    scanf("%f", &registro->saldo);
}
