#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define DIR "Cont.txt"
#include "encabezadoh.h"

int Administrador(){
    char usuario[MAX];
    char contrasenia[MAX];
    int a;

    FILE *con=fopen(DIR,"r");

    system("cls");
    printf("Usuario: ");
    fflush(stdin);
    gets(usuario);
    printf("\nContrase�a: ");
    gets(contrasenia);
    a=strcmp(contrasenia,con);
    if(a==0){
        printf("Contrase�a correcta.");
        return 0;
        }
    else
        return 1;

}


