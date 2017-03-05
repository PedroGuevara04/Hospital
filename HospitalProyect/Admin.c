#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define DIR "Cont.txt"
#include "encabezadoh.h"

int Administrador(){
    char usuario[MAX];
    char contrasenia[MAX], auxContrasenia[]="gordito21";
    int a;

    //FILE *con=fopen(DIR,"r");

    system("cls");
    printf("Usuario: ");
    fflush(stdin);
    gets(usuario);
    printf("\nContraseña: ");
    fflush(stdin);
    gets(contrasenia);
    //fscanf(con,"%s",auxContrasenia);
    //printf("C:%s",auxContrasenia);
    a=strcmp(contrasenia,auxContrasenia);
    if(a==0){
        printf("Contraseña correcta. \n");
        return 0;
        }
    else{
        printf("Contraseña incorrecta. \n");
        return 1;
        }

}


int PacienteMejor(Reserva *arreglo, int max){
    int ret=0;
    int j;
    /*for(j=0;j<max;j++,arreglo++,cont++){

    }*/
    return ret;
}

int PacientePeor(Reserva *arreglo, int max){
    int ret=0;
    return ret;
}

float Presupuesto(Reserva *arreglo, int max){
    float ret=0.0;
    int j;
    for(j=0;j<max;j++,arreglo++){
        ret=ret+((*arreglo).precio);
    }
    return ret;
}
