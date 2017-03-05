#ifndef ENCABEZADOH_H_INCLUDED
#define ENCABEZADOH_H_INCLUDED

#define MAX 50
#define ARG 10

int Menu (char texto[], int n);
typedef struct {
    int numero;
    char *sala;
    char *cuarto;

} DatosA;

typedef struct {
    int CedDoctor;
    char * nombre;
    DatosA ubicacion;
} Doctor;

//===Segunda parte;
typedef struct {
   char nombre[MAX];
   char apellido[MAX];
} datosP;

typedef struct {
   int claveS;//clave
   char Motivo[MAX];//Titulo
   datosP Paciente;
   float precio;
} Reserva;//libro

typedef struct{//Seccion de hospital que contiene sus propios doctores y pacientes

}SeccionH;

int Lleno(int indice);
int Vacio(int indice);
Reserva * creaReserva();
void Capturar(Reserva *uReserva,Doctor *segmento);
void Insertar(Reserva dato, Reserva *arreglo, int *indice);
void listarReserva(Reserva uReserva);
void Listar(Reserva arreglo[],int indice);
int Buscar(int dato, Reserva arreglo[], int indice);
Reserva Borrar (Reserva *arreglo,int pos, int *indice );
void ListarDato(Reserva arreglo[],int pos);
//=====


Doctor *AddDoctor();
void fullEst(FILE *fp,Doctor *nDoc);
void listaDoc(Doctor UDoc);
void freeMem(Doctor *UDoc);

#endif // ENCABEZADOH_H_INCLUDED
