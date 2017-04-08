#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "encabezadoh.h"



Doctor *AddDoctor(){
    Doctor *nDoc;
    nDoc = (Doctor *)calloc(1,sizeof(Doctor));
        nDoc->nombre = (char *)calloc(MAX,sizeof(char));
            nDoc->ubicacion.sala = (char *)calloc(MAX,sizeof(char));
            nDoc->ubicacion.cuarto = (char *)calloc(MAX,sizeof(char));
 return nDoc;
}
void fullEst(FILE *fp,Doctor *nDoc){
    fscanf(fp,"%i\n",&nDoc->CedDoctor);
    fgets(nDoc->nombre,MAX,fp);
    fgets(nDoc->ubicacion.sala,MAX,fp);
    fscanf(fp,"%i\n",&nDoc->ubicacion.numero);
    fgets(nDoc->ubicacion.cuarto,MAX,fp);
}
void listaDoc(Doctor *UDoc, int max){
    int j;
    for(j=0; j<max;j++,UDoc++){
    (*UDoc).nombre[strlen((*UDoc).nombre)-1]='\0';
    (*UDoc).ubicacion.sala[strlen((*UDoc).ubicacion.sala)-1]='\0';
    printf("%i\t %s\t%s\t%i\t%s\n",(*UDoc).CedDoctor, (*UDoc).nombre,(*UDoc).ubicacion.sala,(*UDoc).ubicacion.numero,(*UDoc).ubicacion.cuarto);
    }
}
void freeMem(Doctor *UDoc){
 free(UDoc->nombre);
    free(UDoc->ubicacion.sala);
    free(UDoc->ubicacion.cuarto);
}


