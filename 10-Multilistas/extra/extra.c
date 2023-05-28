#include <stdio.h>
#include <stdlib.h>

typedef struct anios {
	int anio;
	struct meses *mes;
	struct anios *sig;
} anio;

typedef struct meses {
	float promDolar;
	struct meses *sig;
} mes;

void insertarAnios(anio *p, int anterior);
void insertarMeses(mes *p, int num);
void mostrarAnios(anio *p);
void mostrarMeses(mes *p, int num);
void insertarActual(anio *p);
int getMayorMes(mes *p, int num);
void borrarMeses(anio *p);
mes* borrar1(mes *p);
void borrar2(mes *p);


int main(){
    anio *pa;
    pa = (anio*)malloc(sizeof(anio));
    insertarAnios(pa, 0);
    mostrarAnios(pa);
    insertarActual(pa);
    printf("*********************\n");
    mostrarAnios(pa);
    borrarMeses(pa);
    printf("*********************\n");
    mostrarAnios(pa);
}


void insertarAnios(anio *pa, int anterior){
    printf("\nIngrese el año(0 para finalizar): ");
    scanf("%d", &pa->anio);
    while (pa->anio <= anterior && pa->anio != 0){
        printf("\nERROR: año invalido\n");
        scanf("%d", &pa->anio);
    }
    if(pa->anio == 0){
        pa->sig = NULL;
        return;
    }else{
        pa->mes = (mes*)malloc(sizeof(mes));
        insertarMeses(pa->mes, 1);
        pa->sig = (anio*)malloc(sizeof(anio));
        insertarAnios(pa->sig, pa->anio);      
    }
}
void insertarMeses(mes *pm, int num){
    if(num<13){
        printf("\nIngrese el promedio del dolar en el mes %d(0 para finalizar): ", num);
        scanf("%f", &pm->promDolar);
    }
    while (pm->promDolar < 0){
        printf("\nERROR: promedio invalido\n");
        scanf("%f", &pm->promDolar);
    }
    if(pm->promDolar == 0 || num > 12){
        pm->sig = NULL;
        return;
    }else{
        pm->sig = (mes*)malloc(sizeof(mes));
        insertarMeses(pm->sig, num+1);      
    }
}

void mostrarAnios(anio *pa){
    if(pa->sig == NULL){
        return;
    }else{
        printf("-----------------");
        printf("[%d]\n", pa->anio);
        mostrarMeses(pa->mes, 1);
        mostrarAnios(pa->sig);
    }
}
void mostrarMeses(mes *pm, int num){
    if(pm->sig == NULL){
        return;
    }else{
        printf("Mes: %d - Promedio dolar: $%.2f\n", num, pm->promDolar);
        mostrarMeses(pm->sig, num+1);
    }
}

void insertarActual(anio *pa){
    while(pa->sig->sig != NULL){
        pa = pa->sig;
    }
    if(getMayorMes(pa->mes, 0) == 12){
        anio *nuevoAnio;
        nuevoAnio = (anio*)malloc(sizeof(anio));
        nuevoAnio->mes = (mes*)malloc(sizeof(mes));
        nuevoAnio->sig = pa->sig;
        pa->sig = nuevoAnio;
        nuevoAnio->anio = pa->anio+1;
        pa = nuevoAnio;
    }
    mes *pm, *nuevoMes;
    pm = pa->mes;
    nuevoMes = (mes*)malloc(sizeof(mes));
    if(pm->sig == NULL){
        nuevoMes->sig = pm;
        pa->mes = nuevoMes;
    }else{
        while(pm->sig->sig != NULL){
            pm = pm->sig;
        }
        nuevoMes->sig = pm->sig;
        pm->sig = nuevoMes;
    }
    do{
        printf("\nPromedio del Dolar: ");
        scanf("%f",&nuevoMes->promDolar);
    }while(nuevoMes->promDolar<=0);
}

int getMayorMes(mes *pm, int num){
    if(pm->sig == NULL){
        return num;
    }else{
        return getMayorMes(pm->sig, num+1);
    }
}

void borrarMeses(anio *pa){
    if(pa->sig == NULL){
        return;
    }else{
                    printf("****hola**1*\n");
        pa->mes = borrar1(pa->mes);
                    printf("****hola**2*\n");

        borrar2(pa->mes);
                    printf("****hola**3*\n");

        borrarMeses(pa->sig);
    }
}
mes* borrar1(mes *p){
    mes *aux;
    while(p->promDolar < 125 && p->sig != NULL){
        aux = p->sig;
        free(p);
        p = aux;
    }
    return p;
}
void borrar2(mes *p){
    mes *aux;
    while(p->sig != NULL && p->sig->sig != NULL){
        if(p->sig->promDolar < 125){
            aux = p->sig->sig;
            free(p->sig);
            p->sig = aux;
        }else{
            p = p->sig;
        }
    }
}
