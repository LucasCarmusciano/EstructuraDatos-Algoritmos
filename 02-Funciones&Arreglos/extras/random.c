#include <stdio.h>

int main(){
    int n[5];
    int i;
    for (i=0; i<5; i++)
        n[i]=0;
    printf("%8s%13s\n","elemento", "valor");
    for (i=0; i<5; i++)
        printf("%8d%13d\n", i, n[i]);
}