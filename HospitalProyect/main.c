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
        float pres;
        int doctor;
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
                       do{
                        opcion2=Menu("Seleccione una estadística\n1.Presupuesto del mes\n2.Pacientes con peor salud\n3.Pacientes con mejor salud\n4.Total de pacientes\n5.Doctor mas solicitado\n6.Doctor menos solicitado\n7.Doctor que deja mas ganancias\n8.Doctor que deja menos ganancias\n9.Salir\n",9);
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
                            printf("Pacientes en el hospital: %d\n", indice2+1);
                            break;
                        case 5:
                            doctor=doctorMejor(segmento,indice);
                            printf("El doctor más solicitado es: %s con %d visitas\n",segmento[doctor].nombre, segmento[doctor].contadorPacientes);
                            break;
                        case 6:
                            doctor=doctorPeor(segmento,indice);
                            printf("El doctor menos solicitado es: %s con %d visitas\n",segmento[doctor].nombre, segmento[doctor].contadorPacientes);
                            break;
                        case 7:
                            doctor=doctorRico(segmento,indice);
                            printf("El doctor que deja mas ganancias es: %s con $%.2f MXN\n",segmento[doctor].nombre, segmento[doctor].recaudacion);
                            break;
                        case 8:
                            doctor=doctorPobre(segmento,indice);
                            printf("El doctor que deja menos ganancias es: %s con $%.2f MXN\n",segmento[doctor].nombre, segmento[doctor].recaudacion);
                            break;
                        }
                       }while(opcion2!=9);
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
