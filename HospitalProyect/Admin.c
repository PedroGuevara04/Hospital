#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#define DIR "Cont.txt"
#include "encabezadoh.h"

void Administrador(){
    char usuario[MAX];
    char contrasenia[MAX];
    int a;

    FILE *con=fopen(DIR,"r");

    system("cls");
    printf("Usuario: ");
    fflush(stdin);
    gets(usuario);
    printf("\nContraseņa: ");
    gets(contrasenia);
    a=strcmp(contrasenia,con);
    if(a==0)
        printf("Contraseņa correcta.");
    else
        return;

}
