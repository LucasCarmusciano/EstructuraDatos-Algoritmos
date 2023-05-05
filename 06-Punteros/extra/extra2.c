#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[10]={-8,125,107,-21,134,-45};
    int *B, c=2;
    B=arr;
    *B=arr[2];
    // for(int i=0;i<6;i++)
    printf("%d ",*(B+0)**(arr+0));
}