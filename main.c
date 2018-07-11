#include <stdio.h>
#include <stdlib.h>
#include "query1ADT.h"
#include "query2ADT.h"
#include "query3ADT.h"
#include "query4ADT.h"
#include "TAD.h"
#include "cargarAeropuertos.h"
#include "cargarNextVuelo.h"
#include "process_queries.h"

#define NOMBRE_ARCHIVO_AEROPUERTOS "aeropuertos.csv"
#define NOMBRE_ARCHIVO_VUELOS "vuelos.csv"

int main( int argc, char *argv[] ){
	if(argc==2){
		int year;
		sscanf(argv[1],"%d",&year);
		if(year>=2014 && year<=2018){
			AeroListaADT aeropuertos=cargarAeropuertos(NOMBRE_ARCHIVO_AEROPUERTOS);

			if(aeropuertos==NULL){
				return 1;
			}

			query1ADT query1=newQuery1();
			query2ADT query2=newQuery2();
			query3ADT query3=newQuery3();
			query4ADT query4=newQuery4();
			vueloADT vuelo=newVuelo();

			FILE* fVuelos=fopen(NOMBRE_ARCHIVO_VUELOS,"rt");
			while(!feof(fVuelos)){
				cargarNextVuelo(fVuelos,vuelo,year);
				processVuelo(aeropuertos,query1,query2,query3,query4,vuelo);
			}
			fclose(fVuelos);

			FILE* fsalida=fopen("movs_aeropuerto.csv","wt");
			printQuery1(query1,fsalida);
			fclose(fsalida);

			fsalida=fopen("movs_internacional.csv","wt");
			printQuery2(query2,fsalida);
			fclose(fsalida);

			fsalida=fopen("semanal.csv","wt");
			printQuery3(query3,fsalida);
			fclose(fsalida);

			fsalida=fopen("aerop_detalle.csv","wt");
			printQuery4(query4,fsalida);
			fclose(fsalida);

			freeQuery1(query1);
			freeQuery2(query2);
			freeQuery3(query3);
			freeQuery4(query4);

			freeVuelo(vuelo);
			freeAeroLista(aeropuertos);
		}
		else{
			printf("Argumento incorrecto. El argumento debe ser un año entre 2014 y 2018\n");
			return 2;
		}
	}
	else{
		printf("Cantidad de argumentos incorrecta(debe ser 1)\n");
		return 1;
	}
}
