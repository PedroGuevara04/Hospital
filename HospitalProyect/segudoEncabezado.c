#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "encabezadoh.h"


//Segunda parte
int Lleno(int indice2){
    return (indice2 == MAX-1);
}
int Vacio(int indice2) {
   return indice2 ==-1;
}

Reserva * creaReserva(){
    Reserva *uReserva;
    uReserva=(Reserva *)malloc(sizeof(Reserva));

    return uReserva;
}

void Capturar(Reserva *uReserva,Doctor *segmento){
    int doc;
   printf("\nClave: ");
   scanf("%d",&uReserva->claveS);
   printf("\nMotivo: ");
   fflush(stdin);
   gets(uReserva->Motivo);
   printf("\nNombre de la persona: ");
   fflush(stdin);
   gets(uReserva->Paciente.nombre);
   printf("\nApellido del paciente: ");
   fflush(stdin);
   gets(uReserva->Paciente.apellido);
   printf("\nCuanto puede aportar economicamente : ");
   scanf("%f",&uReserva->precio);

    printf("Elige un doctor: ");
    doc=Menu("\n1) Doctora Dulce Mariana Gomez Paredes\n2) Medico Javier Aldama San Pedro\n3) Doctor Augusto Aguirre de la Oya\n4) Doc Hernan Cortez\n",4);
    printf("Has elegido el doctor: %s",segmento[doc-1].nombre);
    segmento[doc-1].contadorPacientes++;
    segmento[doc-1].recaudacion+=uReserva->precio;
}

void Insertar(Reserva dato, Reserva *arreglo, int *indice2){ //******* Cambia: tipos de dato
    *indice2=*indice2+ 1;
    arreglo[*indice2]= dato;
}
void listarReserva(Reserva uReserva){
  printf("\n%d\t%s\t%s\t%s\t%.2f\n", uReserva.claveS,uReserva.Motivo,uReserva.Paciente.nombre,uReserva.Paciente.apellido,uReserva.precio  );
}

void Listar(Reserva arreglo[],int indice2){ //****** Cambia: tipos de datos
    int i;
    if (Vacio(indice2))
        printf("No hay datos en el arreglo\n");
    else
      for (i=0; i<= indice2; i++)
    listarReserva(arreglo[i]); //******

    printf("\n");
}

int Buscar(int dato, Reserva arreglo[], int indice2) { //***
   int i;
   for(i=0; i<=indice2; i++){
        if(dato==arreglo[i].claveS) //**** COMPARAMOS CON STRCOMP CUANDO SON CADENAS
            return i;
   }
   printf("No existe el dato %d en el arreglo\n", dato);
   return -1;
}

Reserva Borrar (Reserva *arreglo,int pos, int *indice2 ){ //*****
   Reserva aux = arreglo[pos]; //****
   arreglo[pos]=arreglo[*indice2];
   (*indice2)--;
   return aux;
}
void ListarDato(Reserva arreglo[],int pos){ //
    listarReserva(arreglo[pos]);
}

void Actualizar(int pos, Reserva *uReserva, Doctor *segmento) {
    int opcion,doc;
    system("cls");
      printf("Que quieres actualizar.\n1)Motivo\n2)Cita\n3)Nombre\n4)Apellido\n5)Aportacion economica\n6)Doctor\nOpcion: ");
      scanf("%d", &opcion);
  switch (opcion)
  {
  case 1:
        printf("\nMotivo: ");
        fflush(stdin);
        gets(uReserva->Motivo);
   break;
  case 2:
        printf("\nNuevo numero de cita: ");
        scanf("%d",&uReserva->claveS);
    break;
  case 3:
        printf("\nNombre de la persona: ");
        fflush(stdin);
        gets(uReserva->Paciente.nombre);
   break;
  case 4:
        printf("\nApellido del paciente: ");
        fflush(stdin);
        gets(uReserva->Paciente.apellido);
    break;
  case 5:
    printf("\nCuanto puede aportar economicamente : ");
   scanf("%f",&uReserva->precio);
   break;
  case 6:
    printf("Elige un doctor: ");
    doc=Menu("\n1) Doctora Dulce Mariana Gomez Paredes\n2) Medico Javier Aldama San Pedro\n3) Doctor Augusto Aguirre de la Oya\n4) Doc Hernan Cortez\n",4);
    printf("\nHas elegido el doctor: %s",segmento[doc-1].nombre);
    break;
  }
}

void InsertarActualizacion(Reserva dato, Reserva *arreglo, int *indice2){ //******* Cambia: tipos de dato
    arreglo[*indice2]= dato;
}



