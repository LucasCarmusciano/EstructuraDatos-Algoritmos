#include<stdio.h>

int main(){
int num=0, hallados=0, aux, cant1=0;
int cantNum = 4;
while (hallados!=cantNum)
{
    aux = num;
    while (aux!=0){
        if (aux%2){
            cant1++;
        }
        aux /= 2;
    }
    if (cant1%2==0 && cant1!=0){
        printf("[%d]\n", num);
        hallados++;
    }
    num++;
    cant1 = 0;
}

return 0;
}