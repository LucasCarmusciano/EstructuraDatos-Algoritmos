#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int legajo;
    int edad;
    int cantCursadas;
    int cantAprobadas;
    int cantReprobadas;
    struct lista *sig;
}nodo;

void cargar(nodo *p);
void generarArchivo(FILE *, nodo *);
void mostrarArchivo(FILE *);

int main(){
    nodo *cabeza;
    FILE *file;
    cabeza = (nodo*)malloc(sizeof(nodo));
    cargar(cabeza);
    generarArchivo(file, cabeza);
    mostrarArchivo(file);
    return 0;
}

void cargar(nodo *p){
    printf("\nNumero de legajo (0 para terminar): ");
    scanf("%d",&p->legajo);
    if(p->legajo == 0){
        p->sig=NULL;
    }else{
        printf("\nEdad: ");
        scanf("%d",&p->edad);
        printf("\nCantidad de materias cursadas: ");
        scanf("%d",&p->cantCursadas);
        printf("\nCantidad de materias aprobadas: ");
        scanf("%d",&p->cantAprobadas);
        printf("\nCantidad de materias reprobadas: ");
        scanf("%d",&p->cantReprobadas);
        p->sig = (nodo *)malloc(sizeof(nodo));
        cargar(p->sig);
    }
}

void generarArchivo(FILE *file, nodo *p){
    if((file=fopen("alumnos.txt","w"))==NULL){
        printf("No se puede abrir el archivo\n");
    }else{
        while(p->sig!=NULL){
            if(p->cantCursadas > p->cantAprobadas){
                fprintf(file,"%d    %d  %d  %d  %d\n", p->legajo,p->edad,p->cantCursadas,p->cantAprobadas,p->cantReprobadas);
            }
            p = p->sig;
        }
    }
    fclose(file);
}

void mostrarArchivo(FILE *file){
    int legajo, edad, cursadas, aprobadas, reprobadas;
    if((file=fopen("alumnos.txt","r"))==NULL){
        printf("No se puede abrir el archivo");
    }else{
        while(!feof(file)){
            fscanf(file,"%d    %d  %d  %d  %d\n",&legajo,&edad,&cursadas,&aprobadas,&reprobadas);
            if(reprobadas==0 && edad>35){
                printf("%d    %d  %d  %d  %d\n",legajo,edad,cursadas,aprobadas,reprobadas);
            }
        }
    }
    fclose(file);
}