#include <stdio.h>
#include <stdlib.h>

int multiplicacionRusa (int a, int b){
    if (a==0 || b==0){
        return 0;
    }else {
        // El primer termino se anula si el multiplicador es par
        return ((b%2)*a) + multiplicacionRusa((a*2), (b/2));
    }
}

int main() {
    int a,b;
    do{
        printf("Ingrese dos numeros mayores o iguales a 0 para obtener su producto\n");
        scanf("%d", &a);
        scanf("%d", &b);
    } while (a < 0 && b < 0);
    printf("El resultado es: %d\n", multiplicacionRusa(a,b));
}