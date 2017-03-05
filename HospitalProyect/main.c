#include <stdio.h>
#include <stdlib.h>
#define DIR "doctor.txt"
#include "encabezadoh.h"

int main()
{
    FILE *fp = fopen(DIR,"rt");
    Doctor *doc, *segmento;
    Reserva *arreglo,*uReserva;
        int indice,i;
        int dato,opcion, pos, indice2, adm,opcion2;
        int pres;
    indice2= -1;

    if (fp==NULL){
        printf("Error al abrir el archivo...");
        exit(1);
    }
    arreglo=(Reserva *)malloc(MAX*sizeof(Reserva)); //*****

    segmento = (Doctor *)calloc(ARG,sizeof(Doctor));
    indice=0;
    while (!feof(fp)){
        doc=AddDoctor();
        fullEst(fp,doc);
        segmento[indice]=*doc;
        free(doc);
        indice++;
    }
    listaDoc(segmento,indice);
    fclose(fp);
    //=============Menu
    do{
        opcion = Menu("\n1)Agregar Cita\n2)Cancelar cita\n3)Actualizar cita\n4)Buscar cita\n5)Listar citas\n6)Administrador\n7)Salir\nOpcion: ",7);
            switch(opcion){
                case 1: //Agrega cita
                     if (!Lleno(indice2)){
                        printf("Captura los datos del paciente:");
                        uReserva=creaReserva(); //se pone en lugar del scanf
                        Capturar(uReserva,segmento);
                        Insertar(*uReserva,arreglo,&indice2); //*****
                        Listar(arreglo,indice2);
                    }
                    else
                      printf("Error: no hay espacio en el arreglo...");
                    break;
                case 2: //Borrar cita
                    printf("Escribe la clave de la cita a borrar:");
                    scanf("%d",&dato);
                    pos= Buscar(dato,arreglo,indice2);
                    if (pos !=-1)
                        Borrar(arreglo,pos, &indice2);
                break;
                case 3: //actualizar
                    printf("Dame el numero de cita a actualizar: ");
                    scanf("%d",&dato);
                    pos= Buscar(dato,arreglo,indice);
                    if (pos !=-1)
                        Actualizar(pos, uReserva,segmento);
                        InsertarActualizacion(*uReserva,arreglo,&indice2); //PARA QUE SOBREESCRIBA LOS DATOS SIN AUMENTAR INDICE
                    break;
                case 4: //Buscar
                    printf("Clave de la cita a buscar :");
                    scanf("%d",&dato);
                    pos= Buscar(dato,arreglo,indice2);
                    if (pos !=-1)
                        ListarDato(arreglo,pos);
                break;
                case 5: //Listar
                    Listar(arreglo, indice2);
                break;
                case 6:
                       adm=Administrador();
                       if(adm==0){
                        opcion2=Menu("Seleccione una estadística\n1.Presupuesto del mes\n2.Pacientes con peor salud\n3.Pacientes con mejor salud\n4.\n5.\n6.\n7.\n8.\n9.Salir\n",9);
                        switch(opcion2){
                        case 1:
                                pres=Presupuesto(arreglo, indice2);
                                printf("El presupuesto del mes es: %.2f",pres);
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            break;
                        case 6:
                            break;
                        case 7:
                            break;
                        case 8:
                            break;
                        case 9:
                            break;
                        }
                       }
                       else{
                        printf("No tiene autorizacion\n");
                       }
                    break;

            }
    }while (opcion != 7);
    free(arreglo);
    //==============


    for (i=0; i<indice; i++)
        freeMem(&segmento[i]);
    free(segmento);

    return 0;
}
