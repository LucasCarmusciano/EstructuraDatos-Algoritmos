// #include <stdio.h>
// #include <stdlib.h>

// typedef struct list{
//     int num;
//     struct node *next;
// }node;

// void create(node *registro);
// void show(node *registro);

// int main(){
//     node *list;
//     list = (node *)malloc(sizeof(node));
//     create(list);
//     show(list);
//     return 0;
// }

// void create(node *registro){
//     printf("Ingrese un numero:\n");
//     scanf("%d", &registro->num);
//     if(registro->num == 0){
//         registro->next=NULL;
//     }else{
//         registro->next = (node *)malloc(sizeof(node));
//         create(registro->next);
//     }
// }

// void show(node *registro){
//     if (registro->next!=NULL){
//         printf("%d\n",registro->num);
//         show(registro->next);
//     }
// }
#include <stdio.h>
#include <stdlib.h>

typedef struct list{
    int num;
    struct node *next;
}node;

void create(node *registro);
void show(node *registro);

int main(){
    node *list;
    list = (node *)malloc(sizeof(node));
    create(list);
    show(list);
    return 0;
}

void create(node *registro){
    printf("Ingrese un numero:\n");
    scanf("%d", &registro->num);
    if(registro->num == 0){
        registro->next=NULL;
    }else{
        registro->next = (node *)malloc(sizeof(node));
        create(registro->next);
    }
}

void show(node *registro){
    while (registro->next!=NULL){
        printf("%d\n",registro->num);
        registro = registro->next;
    }
}