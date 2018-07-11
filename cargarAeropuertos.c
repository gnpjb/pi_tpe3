#include <stdio.h>
#include <string.h>
#include "TAD.h"
#include "cargarAeropuertos.h"

#define DELIM ";"
#define MAX_LONG_LINEA 500

AeroListaADT cargarAeropuertos(char *filename){

	FILE* f=fopen(filename,"rt");
	if(f==NULL){
		return NULL;
	}

	AeroListaADT resp=newAeroLista();
	AeropuertoADT toAdd=newAeropuerto();

	char linea[MAX_LONG_LINEA];

	char *field;
	while(fgets(linea,MAX_LONG_LINEA,f)!=NULL){
		setAeropuertoIATA(toAdd,"");
		setAeropuertoLocal(toAdd,"");
		setAeropuertoOACI(toAdd,"");
		setAeropuertoDenominacion(toAdd,"");
		//primer field es local
		field=strtok(linea,DELIM);
		if(field!=NULL){
			setAeropuertoLocal(toAdd,field);
		}
			//segundo field es oaci, de que este exista depende si es valido o no
		field=strtok(NULL,DELIM);
		if(field!=NULL&&strlen(field)==4){
			setAeropuertoOACI(toAdd,field);
			//tercer field es iata
			field=strtok(NULL,DELIM);
			if(field!=NULL){
				if(strlen(field)==3)
				setAeropuertoIATA(toAdd,field);
			}

			//cuarto field es tipo
			field=strtok(NULL,DELIM);
			//quinto field es denominacion
			field=strtok(NULL,DELIM);
			if(field!=NULL){
				setAeropuertoDenominacion(toAdd,field);
			}
				addAeroLista(resp,toAdd);
		}
	}
	freeAeropuerto(toAdd);
	fclose(f);
	return resp;
}
