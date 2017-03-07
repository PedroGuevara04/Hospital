#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define DIR "Cont.txt"
#include "encabezadoh.h"

int Administrador(){
    FILE *con;
    char usuario[MAX];
    char cadena[MAX],contrasenia[MAX];
    int a;

    con=fopen(DIR,"rt");

    system("cls");
    printf("\n\tUsuario: ");
    fflush(stdin);
    gets(usuario);
    printf("\n\n\tPassword: ");
    fflush(stdin);
    gets(contrasenia);

    while (feof(con) == 0)
    {
        fgets(cadena,MAX,con);
    }
    a=strcmp(contrasenia,cadena);

    if(a==0){
        printf("Exito\n");
        return 0;
        }
    else{
        printf("Error\n");
        return 1;
        }
    fclose(con);
}

int doctorMejor(Doctor *doctores, int max){
    int ret=0, aux=0;
    int j;
    for(j=0;j<max;j++,doctores++){
        if(doctores->contadorPacientes>aux){
            aux=doctores[j].contadorPacientes;
            ret=j;
        }
    }
    return ret;
}

int doctorPeor(Doctor *doctores, int max){
    int ret=0, aux=MAX;
    int j;
    for(j=0;j<max;j++,doctores++){
        if(doctores->contadorPacientes<aux){
            aux=doctores[j].contadorPacientes;
            ret=j;
        }
    }
    return ret;
}

int PacientePeor(Reserva *arreglo, int max){
    int ret=0;
    return ret;
}

int PacienteMejor(Reserva *arreglo, int max){
    int ret=0;
    int j;
    /*for(j=0;j<max;j++,arreglo++,cont++){

    }*/
    return ret;
}

int doctorRico(Doctor *doctores, int max){
    int ret=0;
    float aux=0;
    int j;
    for(j=0;j<max;j++,doctores++){
        if(doctores->recaudacion>aux){
            aux=doctores[j].recaudacion;
            ret=j;
        }
    }
    return ret;
}

int doctorPobre(Doctor *doctores, int max){
    int ret=0;
    int j;
    float aux=10000000;
    for(j=0;j<max;j++,doctores++){
        if(doctores->contadorPacientes<aux){
            aux=doctores[j].contadorPacientes;
            ret=j;
        }
    }
    return ret;
}

float Presupuesto(Reserva *arreglo, int max){
    float ret=0.0;
    int cont;
    for(cont=0;cont<=max;cont++){
        ret=ret+(arreglo[cont].precio);
    }
    //printf("tot: %.2f",ret);
    return ret;
}
